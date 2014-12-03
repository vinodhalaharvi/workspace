#!/bin/bash
#make sure to install this first
#sudo yum install libxslt.x86_64
export JAVA_HOME=/opt/local/software/hyperic/utils/jre
export PATH=$JAVA_HOME/bin:$PATH
export PATH=$PATH:/opt/local/software/hyperic/utils/hqapi1-client-4.1.0.M1/bin
HQ_DIR=~/.hq
if [ ! -d $HQ_DIR ]; then
	mkdir $HQ_DIR
	if [[ $? -eq 0 ]]; then
		echo "Create directory $HQ_DIR Successful"
	else
		echo "Create directory $HQ_DIR Failed!"
	fi
fi
touch $HQ_DIR/client.properties
