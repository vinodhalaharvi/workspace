/**
 * 
 */
package cscie97.asn3.squaredesk.test;
import java.io.FileNotFoundException;
import java.net.URI;
import java.net.URISyntaxException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

import cscie97.asn3.squaredesk.renter.AccessException;
import cscie97.asn3.squaredesk.renter.BookingAlreadyExistException;
import cscie97.asn3.squaredesk.renter.BookingService;
import cscie97.asn3.squaredesk.renter.ContactInfo;
import cscie97.asn3.squaredesk.renter.Feature;
import cscie97.asn3.squaredesk.renter.Image;
import cscie97.asn3.squaredesk.renter.OfficeSpace;
import cscie97.asn3.squaredesk.renter.OfficeSpaceNotFoundException;
import cscie97.asn3.squaredesk.renter.Provider;
import cscie97.asn3.squaredesk.renter.ProviderAlreadyExistException;
import cscie97.asn3.squaredesk.renter.ProviderNotFoundException;
import cscie97.asn3.squaredesk.renter.ProviderService;
import cscie97.asn3.squaredesk.renter.Rate;
import cscie97.asn3.squaredesk.renter.Rating;
import cscie97.asn3.squaredesk.renter.RatingNotFoundException;
import cscie97.asn3.squaredesk.renter.Renter;
import cscie97.asn3.squaredesk.renter.RenterAlreadyExistException;
import cscie97.asn3.squaredesk.renter.RenterNotFoundException;
import cscie97.asn3.squaredesk.renter.RenterService;

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
	 * @throws BookingAlreadyExistException 
	 */
	public static void main(String[] args) 
			throws FileNotFoundException, 
			ParseException, URISyntaxException, 
			ProviderAlreadyExistException, AccessException, 
			ProviderNotFoundException, RatingNotFoundException, 
			OfficeSpaceNotFoundException, RenterAlreadyExistException, 
			RenterNotFoundException, BookingAlreadyExistException {
		
		//Import provider from provider.yaml file
		ContextProvider.importFile(args[0]); 
		//Import from renter.yaml file
		ContextRenter.importFile(args[1]);
		
		Provider provider; 
		//first insert some features
		provider = ProviderService.createProvider(ContextProvider.getAuthToken(), "Vinod Halaharvi", 
				new ContactInfo("vinod.halaharvi@gmail.com"), 
				new Image("Amazing Picture", new URI("https://images.google.com"))
				);		
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
		
		System.exit(0); 
	}
}