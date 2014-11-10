/**
 * 
 */
package cscie97.asn3.squaredesk.test;

import java.io.FileNotFoundException;
import java.net.URI;
import java.net.URISyntaxException;
import java.text.ParseException;

import cscie97.asn3.squaredesk.provider.AccessException;
import cscie97.asn3.squaredesk.provider.ContactInfo;
import cscie97.asn3.squaredesk.provider.Image;
import cscie97.asn3.squaredesk.provider.OfficeSpaceNotFoundException;
import cscie97.asn3.squaredesk.provider.RatingNotFoundException;
import cscie97.asn3.squaredesk.renter.RenterAlreadyExistException;
import cscie97.asn3.squaredesk.renter.RenterNotFoundException;
import cscie97.asn3.squaredesk.renter.RenterService;

/**
 * The Class RenterTestDriver.
 */
public class RenterTestDriver extends TestDriverBase { 
	/**
	 * @throws ParseException 
	 * @throws FileNotFoundException 
	 * 
	 */
	public RenterTestDriver() 
			throws FileNotFoundException, ParseException { 
		//RenterService = new RenterService(); 
	}

	@Override
	public void createTest() 
			throws RenterAlreadyExistException, AccessException, URISyntaxException {
		RenterService.createRenter(ContextRenter.getAuthToken(), "Vinod Halaharvi", 
				new ContactInfo("vinod.halaharvi@gmail.com"), 
				new Image("Amazing Picture", new URI("https://images.google.com"))
				);		
		beginTest("createTest");
		//USING RenterService
		//First create a Singleton RenterService object
		//Add OfficeSpace to Renter
		//get OfficeSpace object from Renter object (and verify by printing to stdout) 
		//add rates to the OfficeSpace of this Renter  (and verify by printing to stdout)
		//Mandatory fields are, location, capacity, facility, rate (at least one rate)
		endTest("createTest");
	}

	@Override
	public void readTest() {
		beginTest("readTest"); 
		endTest("readTest"); 
	}

	@Override
	public void init() {
		//RenterService.getInstance();
	}

	@Override
	public void deleteTest() 
			throws RatingNotFoundException {
		beginTest("deleteTest");
		endTest("deleteTest"); 
	}

	@Override
	public void updateTest() 
			throws OfficeSpaceNotFoundException, RenterNotFoundException, AccessException, 
			URISyntaxException {
		beginTest("updateTest");
		endTest("updateTest");
	}
}
