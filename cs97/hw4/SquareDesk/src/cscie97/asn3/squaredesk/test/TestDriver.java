/**
 * 
 */
package cscie97.asn3.squaredesk.test;
import java.io.FileNotFoundException;
import java.net.URI;
import java.net.URISyntaxException;
import java.nio.file.AccessDeniedException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

import cscie97.asn3.squaredesk.authentication.AccessException;
import cscie97.asn3.squaredesk.authentication.AccessTokenException;
import cscie97.asn3.squaredesk.authentication.AuthenticationException;
import cscie97.asn3.squaredesk.authentication.PermissionAlreadyExistException;
import cscie97.asn3.squaredesk.authentication.RoleAlreadyExistException;
import cscie97.asn3.squaredesk.authentication.ServiceAlreadyExistException;
import cscie97.asn3.squaredesk.authentication.UserAlreadyExistException;
import cscie97.asn3.squaredesk.authentication.UserNotFoundException;
import cscie97.asn3.squaredesk.provider.ContactInfo;
import cscie97.asn3.squaredesk.provider.Feature;
import cscie97.asn3.squaredesk.provider.Image;
import cscie97.asn3.squaredesk.provider.OfficeSpace;
import cscie97.asn3.squaredesk.provider.OfficeSpaceNotFoundException;
import cscie97.asn3.squaredesk.provider.Provider;
import cscie97.asn3.squaredesk.provider.ProviderAlreadyExistException;
import cscie97.asn3.squaredesk.provider.ProviderNotFoundException;
import cscie97.asn3.squaredesk.provider.ProviderService;
import cscie97.asn3.squaredesk.provider.Rate;
import cscie97.asn3.squaredesk.provider.Rating;
import cscie97.asn3.squaredesk.provider.RatingNotFoundException;
import cscie97.asn3.squaredesk.renter.BookingAlreadyExistException;
import cscie97.asn3.squaredesk.renter.BookingService;
import cscie97.asn3.squaredesk.renter.Criteria;
import cscie97.asn3.squaredesk.renter.Renter;
import cscie97.asn3.squaredesk.renter.RenterAlreadyExistException;
import cscie97.asn3.squaredesk.renter.RenterNotFoundException;
import cscie97.asn3.squaredesk.renter.RenterService;

/**
 * The Class TestDriver.
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
	 * @throws BookingAlreadyExistException 
	 * @throws UserAlreadyExistException 
	 * @throws ServiceAlreadyExistException 
	 * @throws PermissionAlreadyExistException 
	 * @throws RoleAlreadyExistException 
	 * @throws UserNotFoundException 
	 * @throws AuthenticationException 
	 * @throws AccessTokenException 
	 */
	public static void main(String[] args) 
			throws FileNotFoundException, 
			ParseException, URISyntaxException, 
			ProviderAlreadyExistException, AccessException, 
			ProviderNotFoundException, RatingNotFoundException, 
			OfficeSpaceNotFoundException, RenterAlreadyExistException, 
			RenterNotFoundException, BookingAlreadyExistException, UserAlreadyExistException, ServiceAlreadyExistException, PermissionAlreadyExistException, RoleAlreadyExistException, AuthenticationException, UserNotFoundException, AccessTokenException {
		
		//AuthenticationService test cases
		AuthenticationTestDriver authenticationTestDeriver = new AuthenticationTestDriver(); 
		authenticationTestDeriver.createTest();
		System.exit(0); 

		//Import provider from provider.yaml file
		ContextProvider.importFile(args[0]); 
		
		//Import from renter.yaml file
		ContextRenter.importFile(args[1]);
		
		Provider provider = null; 
		//first insert some features
		try {
			provider = ProviderService.createProvider(ContextProvider.getAuthToken(), "Vinod Halaharvi", 
					new ContactInfo("vinod.halaharvi@gmail.com"), 
					new Image("Amazing Picture", new URI("https://images.google.com"))
					);
		} catch (AccessDeniedException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}		
		OfficeSpace officeSpace = new OfficeSpace("Amazon OfficeSpace!", 
				ContextProvider.getLocation(), 
				ContextProvider.getCapacity(), 
				ContextProvider.getFacility(), 
				ContextProvider.getRates().get(0));
		for(Rating rating : ContextProvider.getRatings()){
			officeSpace.addRating(ContextProvider.getAuthToken(), rating);
		}
		String authToken = ContextProvider.getAuthToken();
		officeSpace.addRate(ContextProvider.getAuthToken(), ContextProvider.getRates().get(1));
		ProviderService.addOfficeSpaceToProvider(authToken, provider.getProviderId(), officeSpace);
		for(Feature feature : ContextProvider.getFeatures()){
			officeSpace.addFeature(ContextProvider.getAuthToken(), feature.getName());
		}
		
		officeSpace = provider.addOfficeSpaceToKnowledgeGraph(officeSpace);
		
		//Search the officeSpaces based on the following criteria below
		System.out.println();
		System.out.println("Search using features..!!");
		for(OfficeSpace offSpace : RenterService.searchKGUsingFeatures(ContextProvider.getAuthToken(),
				ContextProvider.getFeatures())){
			System.out.println("SEARCH FOUND: " + offSpace.getOffId());
		}
		
		System.out.println();
		System.out.println("Search using location..!!");
		for(OfficeSpace offSpace : RenterService.searchKGUsingLocation(authToken, ContextProvider.getLocation())){
			System.out.println("SEARCH FOUND: " + offSpace.getOffId());
		}
		
		
		System.out.println();
		System.out.println("Search using facility..!!");
		for(OfficeSpace offSpace : RenterService.searchKGUsingFacilityAndCategory(authToken,  
				ContextProvider.getFacility())){
			System.out.println("SEARCH FOUND: " + offSpace.getOffId());
		}
		
		System.out.println();
		System.out.println("Search using Average Rating..!!");
		int minRating = 2; 
		for(OfficeSpace offSpace : RenterService.searchKGUsingRating(authToken, minRating)){
			System.out.println("SEARCH FOUND: " + offSpace.getOffId());
		}

		
		//Create a Renter
		Renter renter = RenterService.createRenter(ContextRenter.getAuthToken(), 
				ContextRenter.getName(), 
				new ContactInfo("halavin@iit.edu"), 
				ContextRenter.getImage()
				);
		
		//Create a booking
		Date startDate = new SimpleDateFormat("yyyy-mm-dd").parse((String)"2010-01-01");
		Date endDate = new SimpleDateFormat("yyyy-mm-dd").parse((String)"2015-01-01");
		BookingService.createBooking(renter, officeSpace, "week", 
				new Rate("week", 40.0), startDate, endDate, "paid");
		
		
		//Now check if the officeSpace is visible in our BookingServiceAPI
		System.out.println();
		System.out.println("Search using Dates..!!");
		for(OfficeSpace offSpace : RenterService.searchKGUsingDates(authToken, startDate, endDate)){
			System.out.println("SEARCH FOUND: " + offSpace.getOffId());
		}
		
		
		//Search for officeSpace using Criteria object 
		System.out.println();
		System.out.println("Search using Criteria object..!!");
		Criteria criteria = new Criteria(ContextProvider.getFeatures(), ContextProvider.getLocation()
				, ContextProvider.getFacility(), 2, startDate, endDate);
		for(OfficeSpace offSpace : RenterService.searchKGCriteria(authToken, criteria)){
			System.out.println("SEARCH FOUND: " + offSpace.getOffId());
		}	
				
		//Trying out few exception classes
		try {
			//Create a Renter
			RenterService.createRenter(ContextRenter.getAuthToken(), 
					ContextRenter.getName(), 
					new ContactInfo("halavin@iit.edu"), 
					ContextRenter.getImage()
					);
		} catch (RenterAlreadyExistException e) {
			System.out.println();
			System.out.println("Successfully caught RenterAlreadyExistException exception");
		}
		
		
		try {
			RenterService.getRenter(authToken, "NonExistingID"); 
		} catch (RenterNotFoundException e) {
			System.out.println();
			System.out.println("Successfully caught RenterNotFoundException exception");
		}
		
		System.exit(0); 
	}
}