#!/usr/bin/env python
# 
# Copyright (c) 2013, RTP Network Services, Inc.
# All Rights Reserved      (904-236-6993)
# Vinod Halaharvi / vinod.halaharvi@rtpnet.net
#
# http://www.rtpnet.net / codesupport@rtpnet.net
#
# There is NO warranty for this software.  If this software is used by
# someone else and passed on, the recipients should know that what they
# have is not the original, so that any problems introduced by others will
# not reflect on the original authors' reputations. This is *not* authorization
# to copy or distribute this software to others!

from get import Get
from lxml import etree
import os
import sys
from  libxml import * 
import time
import socket
import datetime

def getResourceId(what, plat):
	"""docstring for getResourceId"""
	g = Get(gc.config[what]['hq_username'], gc.config[what]['hq_password'])
	url = r"http://%s:%s/hqu/hqapi1/resource/get.hqu?fqdn=%s" % (gc.config[what]['hq_host'], \
			gc.config[what]['hq_port'], plat)
	print url
	xmlstring = g.get(url,) 
	root = etree.fromstring(xmlstring)
	return root.xpath('//Resource')[0].attrib['id']

def getXML(url, hyperic_username, hyperic_password):
	"""docstring for getXML"""
	g = Get(hyperic_username, hyperic_password)
	data = g.get(url,)
	print url
	return xml.dom.minidom.parseString(data).toprettyxml()


def getResourceXML(what, resourceId, verbose=False):
	"""docstring for getResourceXML"""
	if verbose:
		url = r"http://%s:%s/hqu/hqapi1/resource/get.hqu?id=%s&children=true&verbose=true" % (gc.config[what]['hq_host'], gc.config[what]['hq_port'], resourceId)
	else:
		url = r"http://%s:%s/hqu/hqapi1/resource/get.hqu?id=%s" % (gc.config[what]['hq_host'],gc.config[what]['hq_port'], resourceId)
	return getXML(url, gc.config[what]['hq_username'], gc.config[what]['hq_password'])


def getAlertDefXML(what, resourceId):
	"""docstring for getAlertDefXML"""
	#url = r"http://%s:%s/hqu/hqapi1/alertdefinition/listDefinitions.hqu?resourceId=%s&verbose=true"  \
	url = r"http://%s:%s/hqu/hqapi1/alertdefinition/listDefinitions.hqu?resourceId=%s&children=true&verbose=true"  \
		% (gc.config[what]['hq_host'], gc.config[what]['hq_port'], resourceId)
	print url
	return getXML(url, gc.config[what]['hq_username'], gc.config[what]['hq_password'])

def get_Resource_and_Alerts(what, plat, resourcefilepath, alertdeffilepath, verbose=False):
	#Get source_resource resources and alertdefs
	resId = None
	if resourcefilepath and os.path.isfile(resourcefilepath):
		with open(resourcefilepath) as f:
			res_string = f.read()
			print "Using resource from file %s" % (resourcefilepath, )
			resId = etree.fromstring(res_string)\
					.xpath('//ResourceResponse/Resource')[0].attrib['id']
	else:
		#assert 1 == 0, "Error: No such %s found .. " % (resourcefilepath, )
		resId = getResourceId(what, plat)
		res_string = getResourceXML(what, resId, verbose)
		print "Writing/Creating resource to file %s" % (resourcefilepath, )
		with open(resourcefilepath, 'w') as f:
			f.write(res_string)
	resource = etree.fromstring(res_string)
	if alertdeffilepath and os.path.isfile(alertdeffilepath):
		with open(alertdeffilepath) as f:
			alertdef_string = f.read()
			print "Using alertdef from file %s" % (alertdeffilepath, )
	else:
		#assert 1 == 0, "Error: No such %s found .. " % (alertdeffilepath, )
		alertdef_string = getAlertDefXML(what, resId)
		print "Writing/Creating alertdef to file %s" % (alertdeffilepath, )
		with open(alertdeffilepath, 'w') as f:
			f.write(alertdef_string)
	alertdef = etree.fromstring(alertdef_string)
	return  (resource, res_string, alertdef, alertdef_string)

def nslookup(host):
	"""docstring for nslookup"""
	ip_list = []
	ais = socket.getaddrinfo(host,0,0,0,0)
	for result in ais:
		ip_list.append(result[-1][0])
	ip_list = list(set(ip_list))
	return ip_list

def isTimeExpired(dateString):
	"""docstring for isTimeExpired"""
	return datetime.datetime.now() > datetime.datetime.strptime(dateString, "%Y-%m-%d")

def isLicenseValid(licErrorString):
	"""docstring for main"""
	if isTimeExpired("2015-07-31"):
		print licErrorString
		sys.exit(99)
	elif nslookup("csx.com")[0] not in ("10.87.22.38",):
			print nslookup("csx.com")
			print licErrorString
			sys.exit(99)
	else: 
		return 0

class GlobalConfig(object):
	"""docstring for GlobalConfig"""
	def __init__(self,):
		self.config = {}
		super(GlobalConfig, self).__init__()
		self.sourceplat = None
		self.targetplat = None
	def printConfig(self):
		"""docstring for printConfig"""
		print "config is:"
		for key in self.config.items():
			print "%s=%s" % (key, value, )
		print "sourceplat=%s", self.sourceplat
		print "targetplat=%s", self.targetplat

# Procedure is simple
# Get original resource XML
# Get new resource XML 
# Merge original resource XML with new resource XML's data - only the data we care about
# write the merged XML to "sync" file
if __name__ == '__main__':
	# check lic first
	licErrorString = '''
	Script is not supported on this host. Contact codesupport@rtpnet.net..
	'''
	#isLicenseValid(licErrorString)
	#print "License O.K."

	#sanity check on the input arguments
	assert len(sys.argv) == 4, "Usage:\n python diffxml.py configFile  sourceplatform targetplatform"
	# Get Global environment
	gc = GlobalConfig()
	configFile = sys.argv[1]
	gc.sourceplat = sys.argv[2]
	gc.targetplat = sys.argv[3]

	with open(configFile) as f:
		gcroot = etree.fromstring(f.read())
	gc.config["source"] = {}
	for e in gcroot.xpath('//hq/config/source/enum'):
		gc.config["source"].update({e.attrib['key']: e.attrib['value']})
	gc.config["target"] = {}
	for e in gcroot.xpath('//hq/config/target/enum'):
		gc.config["target"].update({e.attrib['key']: e.attrib['value']})
	#Global config settings
	(gc.sourceplat, gc.targetplat) = sys.argv[2:]
	logfile = "data/%s_alertmigrator.log" %(configFile, )
	log = open(logfile, "a")

	sourceResourceFileStr = "data/source_resources_%s.xml" % (gc.sourceplat, )
	sourceAlertDefFileStr = "data/source_alertdefs_%s.xml" % (gc.sourceplat, )
	targetResourceFileStr = "data/target_resources_%s.xml" % (gc.targetplat, )
	targetAlertDefFileStr = "data/target_alertdefs_%s.xml" % (gc.targetplat, )

	(source_resource, source_resource_string, \
			source_alertdef, source_alertdef_string) = \
			get_Resource_and_Alerts('source', 
			gc.sourceplat, \
			sourceResourceFileStr,  \
			sourceAlertDefFileStr, \
				True)

	(target_resource, target_resource_string, \
			target_alertdef, target_alertdef_string) = \
			get_Resource_and_Alerts('target', 
			gc.targetplat, \
			targetResourceFileStr,  \
			targetAlertDefFileStr, \
				True)
	print
	print "<- means in source and not in target .. " 
	print "-> means in target and not in source .. " 
	print "Resources .. " 
	print '##########################'
	prefixStr =  "<-"
	for resource in resources(source_resource):
		if foundResourceByName(resource, target_resource, gc.sourceplat, gc.targetplat):
			continue
		else:
			print "%s Resource %s not found!" % (prefixStr, resource.attrib['name'], )
	prefixStr =  "->"
	for resource in resources(target_resource):
		if foundResourceByName(resource, target_resource, gc.targetplat, gc.sourceplat):
			continue
		else:
			print "%s Resource %s not found!" % (prefixStr, resource.attrib['name'], )
	
	print 
	print "Alerts .. " 
	print '##########################'
	prefixStr =  "<-"
	for alertdef in all_alertdefs(source_resource, source_alertdef):
		if foundAlertDef(alertdef, target_alertdef, gc.sourceplat, gc.targetplat):
			continue
		else: 
			print "%s Alert %s not found!" % (prefixStr, alertdef.attrib['name'],)
        prefixStr =  "->"
        for alertdef in all_alertdefs(target_resource, target_alertdef):
                if foundAlertDef(alertdef, source_alertdef, gc.targetplat, gc.sourceplat):
                        continue
                else:
                        print "%s Alert %s not found!" % (prefixStr, alertdef.attrib['name'],)
	sys.exit(0)
