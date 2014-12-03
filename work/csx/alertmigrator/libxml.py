#!/usr/bin/env python

#hyperic post using dict or xml
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


platform = etree.XPath("//Resource[@typeId='1']")
servers = etree.XPath("//*/Resource[@typeId='2']")
services = etree.XPath("//*/Resource[@typeId='3']")
resources = etree.XPath("//*/Resource")
alertdefs = etree.XPath("//*/AlertDefinition/Resource[@id=$resourceId]")
findAlertByName = etree.XPath("//*/AlertDefinition[@name=$name]")
findResourcebyNameTypeId = etree.XPath("//*/Resource[@name=$name][@typeId=$typeId]")
findResourcebyNameContainsTypeId = etree.XPath("//*/Resource[contains(@name,$name)][@typeId=$typeId]")
#findResourcebyPrototypeTypeId = etree.XPath("//*/Resource[@typeId=$typeId]/ResourcePrototype[@prototype=$prototype]")


def all_alertdefs(resourceroot, alertroot):
	"""docstring for all_alertdefs"""
	for resource in resources(resourceroot):
		for alertdef in alertdefs(alertroot, resourceId = resource.attrib['id']):
			yield alertdef.getparent()
	

def server_alertdefs(resourceroot, alertroot):
	"""docstring for resourceroot"""
	for server in servers(resourceroot):
		for alertdef in alertdefs(alertroot, resourceId = server.attrib['id']):
			yield alertdef.getparent()

def platform_alertdefs(resourceroot, alertroot):
	"""docstring for platform_alertdefs"""
	for p in platform(resourceroot):
		for alertdef in alertdefs(alertroot, resourceId = p.attrib['id']):
			yield alertdef.getparent()


def service_alertdefs(resourceroot, alertroot):
	"""docstring for resource_and_alerts"""
	for service in services(resourceroot):
		for alertdef in alertdefs(alertroot, resourceId = service.attrib['id']):
			yield alertdef.getparent()

def foundAlertDef(alertdef, alertroot, sourceplat, targetplat):
	"""docstring for foundAlertDef"""
	if len(findAlertByName(alertroot, \
			name = alertdef.attrib['name'].replace(sourceplat, targetplat))) >=1 :
		return True
	else:
		return False

def foundResource(resource, resourceroot, sourceplat, targetplat):
	"""docstring for foundResource"""
	if len(findResourcebyNameTypeId(resourceroot, \
			name = resource.attrib['name'].replace(sourceplat, targetplat), \
			typeId = resource.attrib['typeId'])) >=1 :
		return True
	else:
		return False

'''
# SOME USE CASES AS SHOWN BELOW
if __name__ == '__main__':
	(sourceplat, targetplat) = ('lnx20776.csxt.csx.com', 'lnx20777.csxt.csx.com')

	with open(sys.argv[1]) as f:
		source_resource = etree.fromstring(f.read())

	with open(sys.argv[2]) as f:
		source_alertdef = etree.fromstring(f.read())
	
	with open(sys.argv[3]) as f:
		target_resource = etree.fromstring(f.read())

	with open(sys.argv[4]) as f:
		targetalertdef = etree.fromstring(f.read())
	
	print 
	print "ALL RESOURCES .. " 
	for r in resources(source_resource):
		if foundResource(r, source_resource, sourceplat, targetplat):
			print "Skipping resource %s .. " % r.attrib['name']
		else:
			print "Adding resource %s .." % r.attrib['name']

	print "ALL ALERTS .. " 
	for a in all_alertdefs(source_resource, source_alertdef):
		if foundAlertDef(a, targetalertdef, sourceplat, targetplat):
			print "Skipping source_alertdef %s .." % a.attrib['name']
	sys.exit(0)

	print "Printing RESOURCE AND ITS CORRESPONDING ALERTS!!"
	for p in platform(source_resource):
		print p.attrib['name']
		for a in alertdefs(source_alertdef, source_resourceId=p.attrib['id']):
			print "\t", a.getparent().attrib['name']
		print 

	for sr in servers(source_resource):
		print sr.attrib['name']
		for a in alertdefs(source_alertdef, source_resourceId=sr.attrib['id']):
			print a.getparent().attrib['name']
		print 
	
	for a in all_alertdefs(source_resource, source_alertdef):
		print a
		if foundAlertDef(a, source_alertdef, sourceplat, targetplat):
			print "YES!"
	sys.exit(0)

	print 
	print "PLATFORM LEVEL ALERTS .. " 
	for a in platform_alertdefs(source_resource, source_alertdef):
		print a.attrib['name']
	sys.exit(0)
	
	print "SERVER LEVEL ALERTS .. " 
	for a in server_alertdefs(source_resource, source_alertdef):
		print a

	print "SERVICE LEVEL ALERTS .. " 
	for a in service_alertdefs(source_resource, source_alertdef):
		print a
	sys.exit(0)
'''
