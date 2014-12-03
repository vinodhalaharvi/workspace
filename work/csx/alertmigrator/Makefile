export PATH := /opt/local/software/hyperic/utils/python2.7/bin:$(PATH)

all:
	@echo 
	@echo "	Please specify one of the following example targets as shown below:"
	@echo "	make export configfile=hqConnect_lnx40014_to_apl00059.xml sourceplat=lnx20776.csxt.csx.com"
	@echo "	make import configfile=hqConnect_lnx40014_to_apl00059.xml sourceplat=lnx20776.csxt.csx.com targetplat=lnx20777.csxt.csx.com"
	@echo 


export:
	python copyXml.pyc 0 $(configfile) $(sourceplat) "" 

import:
	python copyXml.pyc 1 $(configfile) $(sourceplat) $(targetplat)

cleandata:
	rm  -f data/*.xml
	rm  -f data/.*.xml
	ls data/*
run: 
	make cleandata
	make export configfile=hqConnect_lnx40014_to_apl00059.xml sourceplat=lnx20759.csxt.csx.com
	make import configfile=hqConnect_lnx40014_to_apl00059.xml sourceplat=lnx20759.csxt.csx.com targetplat=lnx20759.csxt.csx.com


sql:
	@echo "Run the below sql in the browser at:"
	@echo "http://hqserver:7080/admin.sql.jsp"
	@echo "select" 
	@echo "	eam_platform.fqdn,"
	@echo "	eam_platform.resource_id"
	@echo "from"
	@echo "	eam_platform;" 
	@echo 

digest:
	@md5sum *.py* > digest.txt

.PHONY: cleandata 
