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

from copy import deepcopy
from get import Get
from lxml import etree
from post import Post
import multiprocessing as mp
import os
import re
import sys
import xml.dom.minidom
from  libxml import * 
import time
import socket
import datetime

def postXML(url, hyperic_username, hyperic_password, xmldata):
        g = Post(hyperic_username, hyperic_password)
        data = g.post(url, xmldata)
	print url
	return xml.dom.minidom.parseString(data).toprettyxml()


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

def postResourceXML(what, xmldata):
	"""docstring for postResourceXML"""
        url = r"http://%s:%s/hqu/hqapi1/resource/sync.hqu" \
			% (gc.config[what]['hq_host'],  gc.config[what]['hq_port'], )
	print url
	return postXML(url, gc.config[what]['hq_username'], gc.config[what]['hq_password'], xmldata)


def postAlertDefXML(what, xmldata):
	"""docstring for postResourceXML"""
        url = r"http://%s:%s/hqu/hqapi1/alertdefinition/sync.hqu" \
			% (gc.config[what]['hq_host'], gc.config[what]['hq_port'], )
	return postXML(url, gc.config[what]['hq_username'], gc.config[what]['hq_password'], xmldata)


def getOutputResourceId(xmlstring):
	"""docstring for getOutputResourceId"""
	root = etree.fromstring(xmlstring)
	return root.xpath('//Resource')[0].attrib['id']

def getResourceId(what, plat):
	"""docstring for getResourceId"""
	g = Get(gc.config[what]['hq_username'], gc.config[what]['hq_password'])
	url = r"http://%s:%s/hqu/hqapi1/resource/get.hqu?fqdn=%s" % (gc.config[what]['hq_host'], \
			gc.config[what]['hq_port'], plat)
	print url
	xmlstring = g.get(url,) 
	root = etree.fromstring(xmlstring)
	return root.xpath('//Resource')[0].attrib['id']

def get_Resource_and_Alerts(what, plat, resourcefilepath, alertdeffilepath, verbose=False):
	#Get source_resource resources and alertdefs
	resId = None
	if resourcefilepath and os.path.isfile(resourcefilepath):
		with open(resourcefilepath) as f:
			res_string = f.read()
			#print "Using resource from file %s" % (resourcefilepath, )
			resId = etree.fromstring(res_string)\
					.xpath('//ResourceResponse/Resource')[0].attrib['id']
	else:
		resId = getResourceId(what, plat)
		res_string = getResourceXML(what, resId, verbose)
	resource = etree.fromstring(res_string)
	if alertdeffilepath and os.path.isfile(alertdeffilepath):
		with open(alertdeffilepath) as f:
			alertdef_string = f.read()
			#print "Using alertdef from file %s" % (alertdeffilepath, )
	else:
		alertdef_string = getAlertDefXML(what, resId)
	alertdef = etree.fromstring(alertdef_string)
	return  (resource, res_string, alertdef, alertdef_string)


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

def addServer(source_resource, target_resource, server):
	"""docstring for addServer"""
	for oe in  source_resource.xpath('//*/Resource[@typeId=2][contains(@name, "%s")]' % server):
		platform(target_resource)[0].append(deepcopy(oe))
		oe.getparent().remove(oe)

def addServers(source_resource, target_resource, servers):
	"""docstring for addServer"""
	for server in servers:
		addServer(source_resource, target_resource, server)

def addService(source_resource, e, service):
	"""docstring for addService"""
	for oe in  source_resource.xpath('//*/Resource[@typeId=3][contains(@name, "%s")]' % service):
		e[0].append(oe.getparent())

def addServices(source_resource, e, services):
	"""docstring for addServices"""
	# append type 3(services) data from source_resource
	for service in services:
		addService(source_resources_, e, service)

def deleteServer(root, server):
	"""docstring for deleteServer"""
	for oe in  findResourcebyNameContainsTypeId(root, name=server, typeId=2):
		log.write("Deleting .. %s" % (oe.attrib, ))
		oe.getparent().remove(oe)

def deleteServerByPrototype(root, server):
	"""docstring for deleteServer"""
	for oe in  findResourcebyNameTypeId(root, name=server, typeId=2):
		op = oe.getparent()
		op.getparent().remove(op)

def deleteService(root, service):
	"""docstring for deleteService"""
	for oe in  findResourcebyNameTypeId(root, name=service, typeId=3):
		oe.getparent().remove(oe)

def deleteServices(root, services):
	"""docstring for deleteService"""
	for service in services:
		deleteService(root, service)

def deleteServers(root, servers):
	"""docstring for deleteServer"""
	for server in servers:
		deleteServer(root, server)
	
def blankInstanceIds(target_resource):
	"""docstring for blankInstanceIds"""
	for tr in target_resource.xpath('//*/Resource'):
		tr.attrib['instanceId'] = ""

def blankServiceResourceIds(target_resource):
	"""docstring for blankServiceResourceIds"""
	for tr in target_resource.xpath('//*/Resource[@typeId=3]'):
		if tr.attrib['name'].strip().lower() == gc.targetplat.strip().lower():
			continue
		else:
			tr.attrib['id'] = ""
def blankServerResourceIds(target_resource):
	"""docstring for blankServiceResourceIds"""
	for tr in target_resource.xpath('//*/Resource[@typeId=2]'):
		if tr.attrib['name'].strip().lower() == gc.targetplat.strip().lower():
			continue
		else:
			tr.attrib['id'] = ""

def adjustResourcePrototypes(target_resource, resource_prototypes):
	"""docstring for adjustResourcePrototypes"""
	for tr in target_resource.xpath('//*/ResourcePrototype'):
		'''assert len(resource_prototypes.xpath('//*/ResourcePrototype[@name="%s"]' \
				% (tr.attrib['name'], ))) >= 1, "No resourceprototype with name '%s' found in \
				the resource_prototypes" % (tr.attrib['name'], )'''
		for rp in resource_prototypes.xpath('//*/ResourcePrototype[@name="%s"]' \
				% (tr.attrib['name'], )):
			assert tr.attrib['name'] == rp.attrib['name'], "Error target resource prototypes names\n \
					don't match %s != %s\n \
					source = %s:%s\n \
					target = %s:%s\n \
					"  % (tr.attrib['name'], rp.attrib['name'], \
					gc.config['source']['hq_host'], \
					gc.config['source']['hq_port'], \
					gc.config['target']['hq_host'], \
					gc.config['target']['hq_port'], )
			tr.attrib['id'] = rp.attrib['id']
			tr.attrib['instanceId'] = rp.attrib['instanceId']
			tr.attrib['resourceTypeId'] = rp.attrib['resourceTypeId']

def delete(e):
        """docstring for delete"""
        e.getparent().remove(e)

def sortAlertDefinitions(root):
        assert root.tag == 'AlertDefinitionsResponse', "Does not look like a AlertDefinitions file? .. "
        children  = root.xpath('//*/AlertDefinition')
        for e in root:
                delete(e)
	status = etree.SubElement(root, "Status")
	status.text = "Success"
        children[:] = sorted(children, key=lambda x: x.attrib['willRecover'], reverse=True)
        for c in children:
                root.append(c)

def runCmd(cmdString):
	"""docstring for runCmd"""
	#set up the environment first
        rc = os.system(cmdString)
	count  = 0 
        while rc != 0 and count <15:
                rc = os.system(cmdString)
                time.sleep(1)
		count += 1
	if count == 15:
		print "Giving up on some resources! These resources might have been synced properly .."
		print "Log in to webconsole and verify .." 

def writeClientProperties():
	"""docstring for writeClientProperties"""
	client_properties_str = '''host=%s
port=%s
secure=%s
user=%s
password=%s''' % ( gc.config['target']['hq_host'], \
		gc.config['target']['hq_port'], \
		"false", \
		gc.config['target']['hq_username'], \
		gc.config['target']['hq_password'], \
		)
	client_properties_path = os.path.expanduser('~/.hq/client.properties')
	print "cat %s" % (client_properties_path, )
	with open(client_properties_path, 'w') as f:
		f.write(client_properties_str)



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
	isLicenseValid(licErrorString)
	#print "License O.K."

	#sanity check on the input arguments
	assert len(sys.argv) == 5, "Usage:\n python copyXml.py [export|import] sourceplatform [targetplatform]"
	task = int(sys.argv[1])
	configFile = sys.argv[2]
	assert  os.path.exists(configFile), "Config file %s does not exist .. " % (configFile, )
	EXPORT = 0
	IMPORT = 1

	# Get Global environment
	gc = GlobalConfig()
	with open(configFile) as f:
		gcroot = etree.fromstring(f.read())

	gc.config["source"] = {}
	for e in gcroot.xpath('//hq/config/source/enum'):
		gc.config["source"].update({e.attrib['key']: e.attrib['value']})

	gc.config["target"] = {}
	for e in gcroot.xpath('//hq/config/target/enum'):
		gc.config["target"].update({e.attrib['key']: e.attrib['value']})

	#Global config settings
	(gc.sourceplat, gc.targetplat) = sys.argv[3:]
	logfile = "data/%s_alertmigrator.log" %(configFile, )
	log = open(logfile, "a")

	if task == IMPORT:
		sourceresfilepath = "data/source_resources_%s.xml" % (gc.sourceplat,)
		sourcealertdeffilepath = ("data/source_alertdefs_%s.xml" % (gc.sourceplat,))
		if not os.path.isfile(sourceresfilepath):
			print sourceresfilepath
			print "Error: Source resource not exported yet .. " 
			print "Run:"
			print 'python copyXml.py 0 source "ignore"'
			sys.exit(99)
		if not os.path.isfile(sourcealertdeffilepath):
			print sourcealertdeffilepath
			print "Error: Source alertdef not exported yet .. " 
			print "Run:"
			print 'python copyXml.py 0 source "ignore"'
			sys.exit(99)
	#source
	(source_resource, source_resource_string, \
			source_alertdef, source_alertdef_string) = \
			get_Resource_and_Alerts('source', 
			gc.sourceplat, \
			"data/source_resources_%s.xml" % (gc.sourceplat, ), \
			"data/source_alertdefs_%s.xml" % (gc.sourceplat, ), \
				True)
	source_resource_copy = deepcopy(source_resource)

	#Get source_resource resources and alertdefs
	if task == EXPORT:
		with open("data/source_resources_%s.xml" % gc.sourceplat, 'w') as f:
			f.write(source_resource_string)

		with open("data/source_alertdefs_%s.xml" % gc.sourceplat, 'w') as f:
			f.write(source_alertdef_string)
		#print "Done exporting .. " 
		sys.exit(0)

	(target_resource, target_resource_string, target_alertdef, \
			target_alertdef_string) = \
			get_Resource_and_Alerts('target', 
			gc.targetplat, \
			"", \
			"",  \
			False)

	with open("data/target_resources_%s.xml" % gc.targetplat, 'w') as f:
		f.write(target_resource_string)

	with open("data/target_alertdefs_%s.xml" % gc.targetplat, 'w') as f:
		f.write(target_alertdef_string)

	# get type 1 resource on target_resource server
	target_resource_type1 = target_resource.xpath('//*/Resource[@typeId=1]')
	# append type 2(servers) data from source_resource
	log.write("%s\n" % (time.time(), ))
	log.write("Adding Servers ..\n" )
	#addServers(source_resource, target_resource, ('MultiLogTracker 1.0', 'FileServer', ))
	server_names = [server.attrib['name'] for server in source_resource.xpath('//*/Resource[@typeId=2]')]
	log.write("Following Servers found .. \n")
	for server in  server_names:
		log.write("%s\n" % (server, ))
	addServers(source_resource, target_resource, server_names)
	deleteServers(source_resource, server_names)

	log.write("Adding Services ..\n")
	#addServices(source_resource, target_resource_type1, ('FileServer Mount', 'crond', ))
	service_names = [service.attrib['name'] for service in source_resource.xpath('//*/Resource[@typeId=3]')]
	addServices(source_resource, target_resource_type1, service_names)
	deleteServices(source_resource, service_names)

	# filter  out the unwanted sync  resources
	log.write("Filtering out some problem sync servers .. \n")
	#deleteServers(target_resource, ('HQ Agent', 'Apache','Postfix', 'NTP',  ))
	deleteServers(target_resource, ('HQ Agent', 'Apache',))

	# write it to a target_resource file
	url =  "http://%s:%s/hqu/hqapi1/resource/getResourcePrototypes.hqu?" % (gc.config['target']['hq_host'],\
			gc.config['target']['hq_port'])
	print "Getting ResourcePrototypes from url:"
	print url
	xmlstring =  getXML(url, gc.config['target']['hq_username'], gc.config['target']['hq_password'])
	resource_prototypes = etree.fromstring(xmlstring)
	adjustResourcePrototypes(target_resource, resource_prototypes)
	blankInstanceIds(target_resource)

	target_resource_sync = deepcopy(target_resource)
	blankServiceResourceIds(target_resource_sync)
	blankServerResourceIds(target_resource_sync)
	#trgt_sync_res_string = etree.tostring(target_resource_sync).replace(gc.sourceplat, gc.targetplat)
	trgt_sync_res_string = etree.tostring(target_resource_sync).replace(\
			gc.sourceplat, gc.targetplat).replace('ResourceResponse', 'ResourcesResponse')
	with open('data/.target_resources_%s_1.xml' % gc.targetplat, 'w') as f:
		f.write(trgt_sync_res_string)
	# sync the resources 
	log.write("Target sync resource string is .. \n")
	log.write("\n")
	print "If you want to sync it manually, here it is.." 
	print "But I am syncing it for you!"
	print "hqapi.sh resource sync < %s" % ('data/.target_resources_%s_1.xml' % gc.targetplat, )
	print "Syncing Resources.. " 
	writeClientProperties()
	cmdString =  "hqapi.sh resource sync < %s" \
			% ('data/.target_resources_%s_1.xml' % gc.targetplat, )
	print cmdString
	runCmd(cmdString)
	print "Sleeping for 10 secs, for resources to settle down .. "
	time.sleep(10)

	# and get the targetly synced resources in the sync_target files
	resId = getResourceId('target', gc.targetplat)
	trgt_refresh_res_string = getResourceXML('target', resId, True)
	refresh_target_resource = etree.fromstring(trgt_refresh_res_string)
	with open('data/.target_refresh_resources_%s.xml' % gc.targetplat, 'w') as f:
		f.write(trgt_refresh_res_string)
	
	resource_ids_map = []
	# get source_resource, target_resource resource id maps
	refresh_target_resource_type1 = refresh_target_resource.xpath('//*/Resource[@typeId=1]')
	#source_resource_type1 = source_resource.xpath('//*/Resource[@typeId=1]')
	source_resource_type1 = source_resource_copy.xpath('//*/Resource[@typeId=1]')
	'''resource_ids_map.append((source_resource_type1[0].attrib['id'] , \
			refresh_target_resource_type1[0].attrib['id'],))'''
	resource_ids_map.append((refresh_target_resource_type1[0].attrib['id'], \
		source_resource_type1[0].attrib['id'],))

	for se in refresh_target_resource_type1[0].iter('Resource'): 
		temp = target_resource_type1[0].xpath('//*/Resource[@typeId="%s"][@name="%s"]' \
				% (se.attrib['typeId'], se.attrib['name']))
		if temp:
			sye = temp[0]
			log.write("Copying ..(%s, %s)" % (se.attrib['id'], sye.attrib['id'],))
			log.write("\n")
			if 'name' in se.attrib and 'name' in sye.attrib:
				log.write("Copying .. (%s, %s)" % (se.attrib['name'], sye.attrib['name'],))
			log.write("\n")
			log.write("\n")
			resource_ids_map.append((se.attrib['id'], sye.attrib['id']))

	# update resouceIds for the alert definitions
	log.write("Adding Alerts ..\n")
	count = 0
	for r in resource_ids_map:
		#print r[0], r[1]
		for sde in source_alertdef.xpath('//*/AlertDefinition/Resource[@id="%s"]' % r[1]):
			print sde.getparent().attrib['name'], "Resource: %s" % (sde.attrib['name'], )
			#if not foundAlertDef(sde.getparent(), target_alertdef, gc.sourceplat, gc.targetplat):
			log.write("Adding %s" % sde.getparent().attrib['name'])
			log.write("\n")
			temp = deepcopy(sde.getparent())
			temp.attrib['id'] = ""
			temp.xpath('//*/Resource')[0].attrib['id'] = r[0]
			if temp.attrib['willRecover'] == 'false':
				#temp.xpath('//*/AlertCondition')[1].attrib['recoverId'] = ""
				t = temp.xpath('//*/AlertCondition[@recoverId]')
				if len(t) >= 1:
					t[0].attrib['recoverId'] = ""
			target_alertdef.xpath('//AlertDefinitionsResponse')[0].append(temp)
			count += 1
			'''else:
				log.write("Skipping %s" % sde.getparent().attrib['name'])
				log.write("\n")'''
	log.write("%d New alerts will have to be copied from source to target .." % count)
	log.write("Please run the command as shown below to copy the alerts .. \n")

	# write target_resource alert definitions back to files
	log.write("Writing target_resource alert definition to the \
			file: data/target_alertdefs_%s.xml" % (gc.targetplat, ))
	log.write("\n")
	sortAlertDefinitions(target_alertdef)
	with open('data/target_alertdefs_%s.xml' % gc.targetplat, 'w') as f:
		#Adjust the script application
		temp_string = etree.tostring(target_alertdef).replace(gc.sourceplat, gc.targetplat)
		temp_string = temp_string.replace(gc.config['source']['alertscriptpath'], \
				gc.config['target']['alertscriptpath'])
		temp_string = temp_string.replace(gc.config['source']['clearscriptpath'], \
				gc.config['target']['clearscriptpath'])
		f.write(temp_string)
		# now finally sync the alert definitions
		#print "Sync your alert definitions using .. " 
		print "I have adjusted your ~/.hq/client_properties file for you" 
		print "IMPORTANT !!!"
		print "Before you run this script you HAVE to make sure the ~/.hq/client.properties" 
		print "looks right"
		print
		cmdString =  "hqapi.sh alertdefinition sync < data/target_alertdefs_%s.xml" % (gc.targetplat, )
		print cmdString
		#runCmd(cmdString)
		#print "Also check for logs in %s file" % (logfile, )
		#print "But I am syncing it for you!"
		#print postAlertDefXML('target', temp_string)
	for i in range(5):
		log.write("\n")
	sys.exit(0)
