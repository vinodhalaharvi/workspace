/**
 * 
 */
package cscie97.asn3.squaredesk.test;
import java.net.URI;
import java.net.URISyntaxException;

import cscie97.asn3.squaredesk.authentication.AccessException;
import cscie97.asn3.squaredesk.provider.ContactInfo;
import cscie97.asn3.squaredesk.provider.Image;
import cscie97.asn3.squaredesk.renter.Renter;
import cscie97.asn3.squaredesk.renter.RenterAlreadyExistException;
import cscie97.asn3.squaredesk.renter.RenterNotFoundException;
import cscie97.asn3.squaredesk.renter.RenterService;

// TODO: Auto-generated Javadoc
/**
 * The Class RenterServiceTestDriver.
 */
public class RenterServiceTestDriver extends TestDriverBase {

	/**
	 * Instantiates a new renter service test driver.
	 */
	public RenterServiceTestDriver() {
	}

	/* (non-Javadoc)
	 * @see cscie97.asn3.squaredesk.test.TestDriverBase#createTest()
	 */
	@Override
	public void createTest() throws RenterAlreadyExistException,
	AccessException, URISyntaxException, RenterNotFoundException {
		beginTest("createTest");
		Renter renter = RenterService.createRenter(ContextRenter.getAuthToken(), "Vinod Halaharvi", 
				new ContactInfo("vinod.halaharvi@gmail.com"), 
				new Image("Amazing Picture", new URI("https://images.google.com"))
				);	
		System.out.println(renter);
		String RenterGUID = renter.getRenterId(); 
		RenterService.deleteRenter(ContextRenter.getAuthToken(), RenterGUID);
		try {
			renter = RenterService.getRenter(ContextRenter.getAuthToken(), RenterGUID);	
		} catch (RenterNotFoundException e) {
			System.out.println("Successfully deleted the Renter !!");
		}
		endTest("createTest");
	}
}
