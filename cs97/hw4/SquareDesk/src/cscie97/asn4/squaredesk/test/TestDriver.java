/**
 * 
 */
package cscie97.asn4.squaredesk.test;
import java.io.FileNotFoundException;
import java.net.URI;
import java.net.URISyntaxException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

import cscie97.asn4.squaredesk.authentication.AccessException;
import cscie97.asn4.squaredesk.authentication.AccessTokenException;
import cscie97.asn4.squaredesk.authentication.AuthenticationException;
import cscie97.asn4.squaredesk.authentication.AuthenticationService;
import cscie97.asn4.squaredesk.authentication.PermissionAlreadyExistException;
import cscie97.asn4.squaredesk.authentication.Role;
import cscie97.asn4.squaredesk.authentication.RoleAlreadyExistException;
import cscie97.asn4.squaredesk.authentication.RoleVisitor;
import cscie97.asn4.squaredesk.authentication.ServiceAlreadyExistException;
import cscie97.asn4.squaredesk.authentication.User;
import cscie97.asn4.squaredesk.authentication.UserAlreadyExistException;
import cscie97.asn4.squaredesk.authentication.UserNotFoundException;
import cscie97.asn4.squaredesk.authentication.UserVisitor;
import cscie97.asn4.squaredesk.provider.ContactInfo;
import cscie97.asn4.squaredesk.provider.Feature;
import cscie97.asn4.squaredesk.provider.Image;
import cscie97.asn4.squaredesk.provider.OfficeSpace;
import cscie97.asn4.squaredesk.provider.OfficeSpaceNotFoundException;
import cscie97.asn4.squaredesk.provider.Provider;
import cscie97.asn4.squaredesk.provider.ProviderAlreadyExistException;
import cscie97.asn4.squaredesk.provider.ProviderNotFoundException;
import cscie97.asn4.squaredesk.provider.ProviderService;
import cscie97.asn4.squaredesk.provider.Rate;
import cscie97.asn4.squaredesk.provider.Rating;
import cscie97.asn4.squaredesk.provider.RatingNotFoundException;
import cscie97.asn4.squaredesk.renter.BookingAlreadyExistException;
import cscie97.asn4.squaredesk.renter.BookingService;
import cscie97.asn4.squaredesk.renter.Criteria;
import cscie97.asn4.squaredesk.renter.Renter;
import cscie97.asn4.squaredesk.renter.RenterAlreadyExistException;
import cscie97.asn4.squaredesk.renter.RenterNotFoundException;
import cscie97.asn4.squaredesk.renter.RenterService;

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
	 * @throws RenterAlreadyExistException the renter already exist exception
	 * @throws RenterNotFoundException the renter not found exception
	 * @throws BookingAlreadyExistException the booking already exist exception
	 * @throws UserAlreadyExistException the user already exist exception
	 * @throws ServiceAlreadyExistException the service already exist exception
	 * @throws PermissionAlreadyExistException the permission already exist exception
	 * @throws RoleAlreadyExistException the role already exist exception
	 * @throws AuthenticationException the authentication exception
	 * @throws UserNotFoundException the user not found exception
	 * @throws AccessTokenException the access token exception
	 */
	public static void main(String[] args) 
			throws FileNotFoundException, 
			ParseException, URISyntaxException, 
			ProviderAlreadyExistException, AccessException, 
			ProviderNotFoundException, RatingNotFoundException, 
			OfficeSpaceNotFoundException, RenterAlreadyExistException, 
			RenterNotFoundException, BookingAlreadyExistException, UserAlreadyExistException, ServiceAlreadyExistException, 
			PermissionAlreadyExistException, RoleAlreadyExistException, AuthenticationException, 
			UserNotFoundException, AccessTokenException {
		
		//AuthenticationService test cases
		AuthenticationTestDriver authenticationTestDeriver = new AuthenticationTestDriver(); 
		authenticationTestDeriver.createTest();
		authenticationTestDeriver.loginUser();
		User user = authenticationTestDeriver.getUser();

		//Import provider from provider.yaml file
		ContextProvider.importFile(args[0]); 
		
		//Import from renter.yaml file
		ContextRenter.importFile(args[1]);
		
		Provider provider = null; 
		//first insert some features
		
		//this call will be successful since the token is valid
		provider = ProviderService.createProvider(user.getAuthToken().getAccessTokenId(), "Vinod Halaharvi", 
				new ContactInfo("vinod.halaharvi@gmail.com"), 
				new Image("Amazing Picture", new URI("https://images.google.com")));
		System.out.println();
		System.out.println("Successfully created the provider using valid token from User " + user.getLoginName());

		//this call will fail since the token is invalid
		System.out.println();
		System.out.println("Providing invalid token to createProvider: " + "wrongToken");
		try {
			provider = ProviderService.createProvider("wrongToken", "Sheldon Cooper", 
					new ContactInfo("sheldon.cooper@gmail.com"), 
					new Image("Amazing Picture", new URI("https://images.google.com")));
				
		} catch (AccessException e) {
			System.out.println("Successfully captured the Access Denied Exception, where the token value is invalid");
		}

		OfficeSpace officeSpace = new OfficeSpace("Amazon OfficeSpace!", 
				ContextProvider.getLocation(), 
				ContextProvider.getCapacity(), 
				ContextProvider.getFacility(), 
				ContextProvider.getRates().get(0));
		for(Rating rating : ContextProvider.getRatings()){
			officeSpace.addRating(user.getAuthToken().getAccessTokenId(), rating);
		}
		officeSpace.addRate(user.getAuthToken().getAccessTokenId(), ContextProvider.getRates().get(1));
		ProviderService.addOfficeSpaceToProvider(user.getAuthToken().getAccessTokenId(), provider.getProviderId(), officeSpace);
		for(Feature feature : ContextProvider.getFeatures()){
			officeSpace.addFeature(user.getAuthToken().getAccessTokenId(), feature.getName());
		}
		
		officeSpace = provider.addOfficeSpaceToKnowledgeGraph(officeSpace);
				
		//Search the officeSpaces based on the following criteria below
		System.out.println();
		System.out.println("Search using features..!!");
		for(OfficeSpace offSpace : RenterService.searchKGUsingFeatures(user.getAuthToken().getAccessTokenId(),
				ContextProvider.getFeatures())){
			System.out.println("SEARCH FOUND: " + offSpace.getOffId());
		}
		
		System.out.println();
		System.out.println("Search using location..!!");
		for(OfficeSpace offSpace : RenterService.searchKGUsingLocation(user.getAuthToken().getAccessTokenId(), ContextProvider.getLocation())){
			System.out.println("SEARCH FOUND: " + offSpace.getOffId());
		}
		
		System.out.println();
		System.out.println("Search using facility..!!");
		for(OfficeSpace offSpace : RenterService.searchKGUsingFacilityAndCategory(user.getAuthToken().getAccessTokenId(),  
				ContextProvider.getFacility())){
			System.out.println("SEARCH FOUND: " + offSpace.getOffId());
		}
		
		System.out.println();
		System.out.println("Search using Average Rating..!!");
		int minRating = 2; 
		for(OfficeSpace offSpace : RenterService.searchKGUsingRating(user.getAuthToken().getAccessTokenId(), minRating)){
			System.out.println("SEARCH FOUND: " + offSpace.getOffId());
		}
		
		//Create a Renter
		Renter renter = RenterService.createRenter(user.getAuthToken().getAccessTokenId(), 
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
		for(OfficeSpace offSpace : RenterService.searchKGUsingDates(user.getAuthToken().getAccessTokenId(), startDate, endDate)){
			System.out.println("SEARCH FOUND: " + offSpace.getOffId());
		}
		
		
		//Search for officeSpace using Criteria object 
		System.out.println();
		System.out.println("Search using Criteria object..!!");
		Criteria criteria = new Criteria(ContextProvider.getFeatures(), ContextProvider.getLocation()
				, ContextProvider.getFacility(), 2, startDate, endDate);
		for(OfficeSpace offSpace : RenterService.searchKGCriteria(user.getAuthToken().getAccessTokenId(), criteria)){
			System.out.println("SEARCH FOUND: " + offSpace.getOffId());
		}	
				
		//Trying out few exception classes
		try {
			//Create a Renter
			RenterService.createRenter(user.getAuthToken().getAccessTokenId(), 
					ContextRenter.getName(), 
					new ContactInfo("halavin@iit.edu"), 
					ContextRenter.getImage()
					);
		} catch (RenterAlreadyExistException e) {
			System.out.println();
			System.out.println("Successfully caught RenterAlreadyExistException exception");
		}
		
		try {
			RenterService.getRenter(user.getAuthToken().getAccessTokenId(), "NonExistingID"); 
		} catch (RenterNotFoundException e) {
			System.out.println();
			System.out.println("Successfully caught RenterNotFoundException exception");
		}
		
		System.out.println();
		//some tests for visitor pattern
		//Simple anonymous UserVisitor client that overrides the visitUser() method
		new UserVisitor(){
			@Override
			public void visitUser(User user) {
				super.visitUser(user);
				System.out.println();
				System.out.println("\tgetLoginName :"+ user.getLoginName());
				System.out.println("\tgetPassword :"+ "XXXXXXXXXX");
				System.out.println("\tgetUserId :"+ user.getUserId());
				System.out.println("\tgetAuthToken :" + user.getAuthToken().getAccessTokenId()); 
				System.out.println("\tgetUserDescription :"+ user.getUserDescription());
			}
		}.visitUserList();
        //some tests for visitor pattern
        //Simple anonymous RoleVisitor client that overrides the visitRole() method
		System.out.println();
        new RoleVisitor(){
                @Override
                public void visitRole(Role role) {
                        super.visitRole(role);
                        System.out.println();
                        System.out.println("\tgetRoleId :"+ role.getRoleId());
                        System.out.println("\tgetRoleId :"+ role.getRoleName());
                        System.out.println("\tgetRoleDescription :" + role.getRoleDescription());
                }
        }.visitRoleList();

	
		System.out.println();
		System.out.println("Logging user out and then trying to createProvider");
		AuthenticationService.logout(user);
		//this will fail since the user is logged out
		try {
			provider = ProviderService.createProvider(user.getAuthToken().getAccessTokenId(), "Sheldon Cooper", 
					new ContactInfo("sheldon.cooper@gmail.com"), 
					new Image("Amazing Picture", new URI("https://images.google.com")));
				
		} catch (AccessException e) {
			System.out.println("Successfully captured the Access Denied Exception, where the user was already logged out");
		}
		
	}
}
