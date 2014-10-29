/**
 * 
 */
package cscie97.asn3.squaredesk.test;

import java.io.FileNotFoundException;
import java.net.URI;
import java.net.URISyntaxException;
import java.text.ParseException;

import cscie97.asn3.squaredesk.renter.AccessException;
import cscie97.asn3.squaredesk.renter.ContactInfo;
import cscie97.asn3.squaredesk.renter.Feature;
import cscie97.asn3.squaredesk.renter.Image;
import cscie97.asn3.squaredesk.renter.OfficeSpace;
import cscie97.asn3.squaredesk.renter.OfficeSpaceNotFoundException;
import cscie97.asn3.squaredesk.renter.Provider;
import cscie97.asn3.squaredesk.renter.ProviderAlreadyExistException;
import cscie97.asn3.squaredesk.renter.ProviderNotFoundException;
import cscie97.asn3.squaredesk.renter.ProviderService;
import cscie97.asn3.squaredesk.renter.Rating;
import cscie97.asn3.squaredesk.renter.RatingNotFoundException;
import cscie97.asn3.squaredesk.renter.Triple;

/**
 * @author s2687
 *
 */
public class ProviderTestDriver extends TestDriverBase { 
	private ProviderService providerService;
	private OfficeSpace officeSpace; 
	private Provider provider;
	/**
	 * @throws ParseException 
	 * @throws FileNotFoundException 
	 * 
	 */
	public ProviderTestDriver() 
			throws FileNotFoundException, ParseException { 
		providerService = new ProviderService(); 
	}

	@Override
	public void createTest() 
			throws ProviderAlreadyExistException, AccessException, URISyntaxException {
		provider = providerService.createProvider(ContextProvider.getAuthToken(), "Vinod Halaharvi", 
				new ContactInfo("vinod.halaharvi@gmail.com"), 
				new Image("Amazing Picture", new URI("https://images.google.com"))
				);		
		beginTest("createTest");
		// TEST CASE 1
		// VERIFY CREATE AND READ OF THE "CRUD" OPERATIONS ON OfficeSpaceProvider and officeSpace
		//USING ProviderService
		//First create a Singleton ProviderService object
		//Add OfficeSpace to provider
		//get OfficeSpace object from provider object (and verify by printing to stdout) 
		//add rates to the OfficeSpace of this provider  (and verify by printing to stdout)
		//Mandatory fields are, location, capacity, facility, rate (at least one rate)
		officeSpace = new OfficeSpace("Amazon OfficeSpace!", 
				ContextProvider.getLocation(), ContextProvider.getCapacity(), ContextProvider.getFacility(), ContextProvider.getRates().get(0));
		//Now add more rates if available
		officeSpace.addRate(ContextProvider.getAuthToken(), ContextProvider.getRates().get(1));
		//add this officeSpace to provider
		officeSpace = provider.addOfficeSpaceToList(officeSpace);
		//Add features to office space. 
		for(Feature feature : ContextProvider.getFeatures()){
			officeSpace.addFeature(ContextProvider.getAuthToken(), feature.getName());
		}
		//Add officeSpace to KnowledgeGraph and make 
		//is searchable
		System.out.println();
		System.out.println("Adding officeSpace to KnowledgeGraph");
		officeSpace = provider.addOfficeSpaceToKnowledgeGraph(officeSpace);
		System.out.println("Ending ProviderTestDriver creatTest()");
		endTest("createTest");
	}

	@Override
	public void readTest() {
		beginTest("readTest"); 
		System.out.println();
		System.out.println("Query after adding officeSpace");
		System.out.println("Features");
		String tempString = "?" + " has_feature " + "?";
		for (Triple foundTriple : ContextProvider.getKg().executeQuery(new Triple(tempString))){
			System.out.println(foundTriple.getIdentifier());
		}

		System.out.println();
		System.out.println("Location");
		tempString = "?" + " has_lat_long " + "?";
		for (Triple foundTriple : ContextProvider.getKg().executeQuery(new Triple(tempString))){
			System.out.println(foundTriple.getIdentifier());
		}
		for(Feature feature : ContextProvider.getFeatures()){
			officeSpace.removeFeature(ContextProvider.getAuthToken(), feature.getName());
		}	
		endTest("readTest"); 
	}

	@Override
	public void init() {
		providerService = ProviderService.getInstance();
	}

	@Override
	public void deleteTest() 
			throws RatingNotFoundException {
		beginTest("deleteTest");
		System.out.println();
		System.out.println("Query after deleting all features");
		String tempString = "?" + " has_feature " + "?";
		for (Triple foundTriple : ContextProvider.getKg().executeQuery(new Triple(tempString))){
			System.out.println(foundTriple.getIdentifier());
		}

		tempString = "?" + " ? " + "?";
		for (Triple foundTriple : ContextProvider.getKg().executeQuery(new Triple(tempString))){
			System.out.println(foundTriple.getIdentifier());
		}

		//add Ratings to provider
		provider.addRatingToList(ContextProvider.getRatings().get(0));
		System.out.println("ADDING A RATING");
		Rating rating = provider.addRatingToList(ContextProvider.getRatings().get(1));
		System.out.println(provider.getRatings());
		//delete rating for the provider
		provider.removeRatingfromList(rating.getRatingId());
		System.out.println("PRINT AFTER DELETING RATING..");
		System.out.println(provider.getRatings());
		endTest("deleteTest"); 
	}

	@Override
	public void updateTest() 
			throws OfficeSpaceNotFoundException, ProviderNotFoundException, AccessException, 
			URISyntaxException {
		beginTest("updateTest");
		//update this newly added officeSpace. 
		System.out.println(officeSpace.getName());
		OfficeSpace officeSpace1 = provider.getOfficeSpacefromList(officeSpace.getOffId());
		officeSpace1.setName("Extra Amazing OfficeSpace!!");

		//These two names should be equal 
		System.out.println("AFTER UPDATING OFFICE SPACE NAME");
		System.out.println(officeSpace.getName());
		System.out.println(officeSpace1.getName());		
		System.out.println();	

		// TEST CASE 2
		//VERIFY UPDATE OF "CRUD" OPERTIONS
		//GET PROVIDER BY GUID
		//UPDATE NAME, CONTACT INFO, PICTURE OF THE PROVIDER
		System.out.println("PROVIDER BEFORE NAME CHANGE");
		System.out.println(provider.getName());
		System.out.println(provider.getContactInfo().getEmail());
		provider = providerService.updateProviderName(ContextProvider.getAuthToken(), 
				provider.getProviderId(), "Vinod Changed Halaharvi");
		System.out.println("PROVIDER AFTER THE NAME CHANGE");
		provider = providerService.getProvider(ContextProvider.getAuthToken(), provider.getProviderId());
		System.out.println(provider.getName());		
		System.out.println(provider.getContactInfo().getEmail());
		System.out.println();

		System.out.println("PROVIDER BEFORE "
				+ "PICTURE CHANGE");
		System.out.println(provider.getName());		
		System.out.println(provider.getContactInfo().getEmail());
		System.out.println("Picture URI: " + provider.getImage().getURI());
		providerService.updateProviderPicture(ContextProvider.getAuthToken(), 
				provider.getProviderId(), 
				new Image("Amazing Picture From Yahoo", new URI("https://images.yahoo.com")));
		System.out.println("PROVIDER AFTER PICTURE CHANGE");
		System.out.println(provider.getName());		
		System.out.println(provider.getContactInfo().getEmail());
		System.out.println("Picture URI: " + provider.getImage().getURI());
		System.out.println();
		endTest("updateTest");
	}
}
