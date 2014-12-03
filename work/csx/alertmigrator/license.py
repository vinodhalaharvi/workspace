# Copyright (c) 2013, RTP Network Services, Inc.
# All Rights Reserved      (904-236-6993)
# Vinod Halaharvi / vinod.halaharvi@rtpnet.net, vinod.halaharvi@gmail.com
# 
# http://www.rtpnet.net / codesupport@rtpnet.net
#
# There is NO warranty for this software.  If this software is used by
# someone else and passed on, the recipients should know that what they
# have is not the original, so that any problems introduced by others will
# not reflect on the original authors' reputations. This is *not* authorization
# to copy or distribute this software to others!

import socket
import sys
import datetime

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
	if isTimeExpired("2014-11-19"):
		print "time expired .." 
		print licErrorString
		sys.exit(99)
	elif nslookup("csx.com")[0] not in ("216.231.209.155",):
			print nslookup("csx.com")
			print "nslookup failure .."
			print licErrorString
			sys.exit(99)
	else: 
		return 0

if __name__ == '__main__':
	licErrorString = '''
	Script is not supported on this host. Contact codesupport@rtpnet.net..
	'''
	isLicenseValid(licErrorString)
	print "License O.K."
