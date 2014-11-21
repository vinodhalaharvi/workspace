unzip Vinod_Halaharvi_RenterService.zip
cd RenterService
javac -cp ./snakeyaml-1.11.jar: src/cscie97/asn3/squaredesk/provider/*.java  src/cscie97/asn3/squaredesk/renter/*.java src/cscie97/asn3/squaredesk/test/*.java
java -cp ./snakeyaml-1.11.jar:./src cscie97/asn3/squaredesk/test/TestDriver ./provider.yaml ./renter.yaml
