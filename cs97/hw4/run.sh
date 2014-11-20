unzip Vinod_Halaharvi_SquareDesk.zip
cd SquareDesk
javac -cp ./snakeyaml-1.11.jar: src/cscie97/asn4/squaredesk/provider/*.java  src/cscie97/asn4/squaredesk/renter/*.java src/cscie97/asn4/squaredesk/authentication/*.java src/cscie97/asn4/squaredesk/test/*.java
java -cp ./snakeyaml-1.11.jar:./src cscie97/asn4/squaredesk/test/TestDriver ./provider.yaml ./renter.yaml
