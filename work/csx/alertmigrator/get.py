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


__all__ = ["Get", ]

import sys, os

class Get(object):
	"""docstring for Get"""
	def __init__(self, hyperic_username, hyperic_password):
		super(Get, self).__init__()
		self.hyperic_username = hyperic_username
		self.hyperic_password = hyperic_password


	def get(self, url=None,):
		import sys
		import urllib
		import urllib2
		import base64
		import os
		assert self.hyperic_username
		assert self.hyperic_password
		import xml.dom.minidom
		return urllib2.urlopen( urllib2.Request(
			url=url, 
			headers={"Authorization": "Basic %s" % base64.encodestring('%s:%s' % (
					self.hyperic_username,
					self.hyperic_password)).replace('\n', '')}
			)).read()
