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
        os.environ['JAVA_HOME'] = '/opt/local/software/hyperic/server-4.6.6-EE/jre/'
        os.environ['PATH'] += ':'.join((
                        '/opt/local/software/hyperic/utils/make-4.0',
                        '/opt/local/software/hyperic/hqapi1-client-4.1.0.M1/bin',
                        '/opt/local/software/hyperic/utils/python2.7.6/bin',
                        '%s/bin' % (os.environ['JAVA_HOME'], ),
                ))
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

