/**
 * 
 */
package cscie97.asn3.squaredesk.test;
import java.io.FileNotFoundException;
import java.net.URISyntaxException;
import java.text.ParseException;

import cscie97.asn3.squaredesk.renter.AccessException;
import cscie97.asn3.squaredesk.renter.OfficeSpaceNotFoundException;
import cscie97.asn3.squaredesk.renter.ProviderAlreadyExistException;
import cscie97.asn3.squaredesk.renter.ProviderNotFoundException;
import cscie97.asn3.squaredesk.renter.RatingNotFoundException;
import cscie97.asn3.squaredesk.renter.RenterAlreadyExistException;
import cscie97.asn3.squaredesk.renter.RenterNotFoundException;

/**
 * The Class TestDriver.
 *
 * @author Vinod Halaharvi
 */
public class TestDriver {

	/**
	 * The main method.
	 *
	 * @param args the arguments
	 * @throws FileNotFoundException the file not found exception
	 * @throws ParseException the parse exception
	 * @throws URISyntaxException the URI syntax exception
	 * @throws ProviderAlreadyExistException the provider already exist exception
	 * @throws AccessException the access exception
	 * @throws ProviderNotFoundException the provider not found exception
	 * @throws RatingNotFoundException the rating not found exception
	 * @throws OfficeSpaceNotFoundException the office space not found exception
	 * @throws RenterNotFoundException 
	 * @throws RenterAlreadyExistException 
	 */
	public static void main(String[] args) 
			throws FileNotFoundException, 
			ParseException, URISyntaxException, 
			ProviderAlreadyExistException, AccessException, 
			ProviderNotFoundException, RatingNotFoundException, 
			OfficeSpaceNotFoundException, RenterAlreadyExistException, RenterNotFoundException {
		
		YamlImporterRenter.getInstance();
		YamlImporterRenter.init(args[0]);
		
		/*System.out.println(yamlImporterRenter.importFacility());
		System.out.println(yamlImporterRenter.importFeatures());
		System.out.println(yamlImporterRenter.importImage());
		System.out.println(yamlImporterRenter.importLocation());
		System.out.println(yamlImporterRenter.importRatings());
		System.out.println(yamlImporterRenter.importAccount());*/

		ContextRenter.importFile("/Users/vinodhalaharvi/harvard/vhalaharvi_harvard_projects/cs97/workspace/RenterService/renter.yaml");		
		TestDriverBase renterTestDriver = new RenterTestDriver();
		renterTestDriver.createTest(); 
		System.exit(0); 

		
		TestDriverBase renterServiceTestDriver = new RenterServiceTestDriver();
		renterServiceTestDriver.readTest(); 
		renterServiceTestDriver.deleteTest(); 
		renterServiceTestDriver.updateTest();
		
		
		/*Context.importFile(args[0]);
		TestDriverBase providerTestDriver = new ProviderTestDriver();
		providerTestDriver.createTest(); 
		providerTestDriver.readTest(); 
		providerTestDriver.deleteTest(); 
		providerTestDriver.updateTest();*/ 
		System.exit(0); 
	}
}