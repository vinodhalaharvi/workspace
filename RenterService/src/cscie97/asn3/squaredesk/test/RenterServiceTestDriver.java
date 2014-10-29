/**
 * 
 */
package cscie97.asn3.squaredesk.test;
import java.net.URI;
import java.net.URISyntaxException;

import cscie97.asn3.squaredesk.renter.AccessException;
import cscie97.asn3.squaredesk.renter.ContactInfo;
import cscie97.asn3.squaredesk.renter.Image;
import cscie97.asn3.squaredesk.renter.OfficeSpace;
import cscie97.asn3.squaredesk.renter.OfficeSpaceNotFoundException;
import cscie97.asn3.squaredesk.renter.ProviderNotFoundException;
import cscie97.asn3.squaredesk.renter.RatingNotFoundException;
import cscie97.asn3.squaredesk.renter.Renter;
import cscie97.asn3.squaredesk.renter.RenterAlreadyExistException;
import cscie97.asn3.squaredesk.renter.RenterNotFoundException;
import cscie97.asn3.squaredesk.renter.RenterService;

/**
 * The Class RenterServiceTestDriver.
 */
public class RenterServiceTestDriver extends TestDriverBase {

	/** The Renter. */
	private Renter renter;
	
	/** The Renter service. */
	private RenterService RenterService; 

	/**
	 * Instantiates a new Renter service test driver.
	 */
	public RenterServiceTestDriver() {
		// TODO Auto-generated constructor stub
	}

	/* (non-Javadoc)
	 * @see cscie97.asn3.squaredesk.test.TestDriverBase#createTest()
	 */
	@Override
	public void createTest() throws RenterAlreadyExistException,
	AccessException, URISyntaxException, RenterNotFoundException {
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
		
		OfficeSpace officeSpace; 
		
		/*Booking booking = new Booking(renter, officeSpace, rate, startDate, new Date(), "paid");
		BookingService bookingService = new BookingService();
		bookingService.addBooking(booking); 
		System.out.println("Ending RenterTestDriver creatTest()");*/	
	}
	
	
	@Override
	public void readTest() {
	}
	
	@Override
	public void deleteTest() throws RatingNotFoundException {
	}
	
	
	@Override
	public void updateTest() throws OfficeSpaceNotFoundException,
			ProviderNotFoundException, AccessException, URISyntaxException,
			RenterNotFoundException {
	}

}
