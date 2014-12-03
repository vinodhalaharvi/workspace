0) 
# only if libxslt and make is not installed
# you will get an error about xslt and make when you run the script
# you can then come back and install these two packages
sudo yum install libxslt.x86_64 # if not already present then install xslt xml library
sudo yum install make.x86_64 # if not already present then install make
sudo su - hyperic && cd /opt/local/software/hyperic/utils/alertmigrator
#make sure that you are in the 'alertmigrator/' directory when you run the 'make' commands. One common mistake is to be in 'alertmigrator/data' directory or to be in 'utils/' directory when you run 'make' command.
0.1) . setenv.sh
1) make cleandata
2) make
        make export configfile=hqConnect_lnx40014_to_apl00124.xml sourceplat=lnx20770.csxt.csx.com
        make import configfile=hqConnect_lnx40014_to_apl00124.xml sourceplat=lnx20770.csxt.csx.com targetplat=lnx20770.csxt.csx.com
2.1) Create a configuration file by copying one of the hqConnect_*.xml files and edit the source and target information accordingly.
3) make export configfile=hqConnect_lnx40014_to_apl00124.xml sourceplat=lnx20770.csxt.csx.com
4) make import configfile=hqConnect_lnx40014_to_apl00124.xml sourceplat=lnx20770.csxt.csx.com targetplat=lnx20770.csxt.csx.com
6) cat ~/.hq/client.properties
7) hqapi.sh alertdefinition sync < data/target_alertdefs_lnx20771.csxt.csx.com.xml
