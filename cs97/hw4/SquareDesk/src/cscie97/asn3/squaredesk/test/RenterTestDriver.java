/**
 * 
 */
package cscie97.asn3.squaredesk.test;

import java.io.FileNotFoundException;
import java.net.URI;
import java.net.URISyntaxException;
import java.text.ParseException;

import cscie97.asn3.squaredesk.authentication.AccessException;
import cscie97.asn3.squaredesk.provider.ContactInfo;
import cscie97.asn3.squaredesk.provider.Image;
import cscie97.asn3.squaredesk.provider.OfficeSpaceNotFoundException;
import cscie97.asn3.squaredesk.provider.RatingNotFoundException;
import cscie97.asn3.squaredesk.renter.RenterAlreadyExistException;
import cscie97.asn3.squaredesk.renter.RenterNotFoundException;
import cscie97.asn3.squaredesk.renter.RenterService;

// TODO: Auto-generated Javadoc
/**
 * The Class RenterTestDriver.
 */
public class RenterTestDriver extends TestDriverBase { 
	
	/**
	 * Instantiates a new renter test driver.
	 *
	 * @throws FileNotFoundException the file not found exception
	 * @throws ParseException the parse exception
	 */
	public RenterTestDriver() 
			throws FileNotFoundException, ParseException { 
		//RenterService = new RenterService(); 
	}

	/* (non-Javadoc)
	 * @see cscie97.asn3.squaredesk.test.TestDriverBase#createTest()
	 */
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

	/* (non-Javadoc)
	 * @see cscie97.asn3.squaredesk.test.TestDriverBase#readTest()
	 */
	@Override
	public void readTest() {
		beginTest("readTest"); 
		endTest("readTest"); 
	}

	/* (non-Javadoc)
	 * @see cscie97.asn3.squaredesk.test.TestDriverBase#init()
	 */
	@Override
	public void init() {
		//RenterService.getInstance();
	}

	/* (non-Javadoc)
	 * @see cscie97.asn3.squaredesk.test.TestDriverBase#deleteTest()
	 */
	@Override
	public void deleteTest() 
			throws RatingNotFoundException {
		beginTest("deleteTest");
		endTest("deleteTest"); 
	}

	/* (non-Javadoc)
	 * @see cscie97.asn3.squaredesk.test.TestDriverBase#updateTest()
	 */
	@Override
	public void updateTest() 
			throws OfficeSpaceNotFoundException, RenterNotFoundException, AccessException, 
			URISyntaxException {
		beginTest("updateTest");
		endTest("updateTest");
	}
}
