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
import cscie97.asn3.squaredesk.provider.Feature;
import cscie97.asn3.squaredesk.provider.Image;
import cscie97.asn3.squaredesk.provider.OfficeSpace;
import cscie97.asn3.squaredesk.provider.OfficeSpaceNotFoundException;
import cscie97.asn3.squaredesk.provider.Provider;
import cscie97.asn3.squaredesk.provider.ProviderAlreadyExistException;
import cscie97.asn3.squaredesk.provider.ProviderNotFoundException;
import cscie97.asn3.squaredesk.provider.ProviderService;
import cscie97.asn3.squaredesk.provider.Rating;
import cscie97.asn3.squaredesk.provider.RatingNotFoundException;
import cscie97.asn3.squaredesk.renter.KnowledgeGraph;
import cscie97.asn3.squaredesk.renter.Triple;

/**
 * The Class ProviderTestDriver.
 */
public class ProviderTestDriver extends TestDriverBase { 
	
	/** The office space. */
	private OfficeSpace officeSpace; 
	
	/** The provider. */
	private Provider provider;
	/**
	 * @throws ParseException 
	 * @throws FileNotFoundException 
	 * 
	 */
	public ProviderTestDriver() 
			throws FileNotFoundException, ParseException { 
		//providerService = new ProviderService(); 
	}

	@Override
	public void createTest() 
			throws ProviderAlreadyExistException, AccessException, URISyntaxException, 
			FileNotFoundException, ParseException {
		beginTest("createTest");
		provider = ProviderService.createProvider(ContextProvider.getAuthToken(), "Vinod Halaharvi", 
				new ContactInfo("vinod.halaharvi@gmail.com"), 
				new Image("Amazing Picture", new URI("https://images.google.com"))
				);		
		officeSpace = new OfficeSpace("Amazon OfficeSpace!", 
				ContextProvider.getLocation(), ContextProvider.getCapacity(), ContextProvider.getFacility(), 
				ContextProvider.getRates().get(0));
		officeSpace.addRate(ContextProvider.getAuthToken(), ContextProvider.getRates().get(1));
		officeSpace = provider.addOfficeSpaceToList(officeSpace);
		for(Feature feature : ContextProvider.getFeatures()){
			officeSpace.addFeature(ContextProvider.getAuthToken(), feature.getName());
		}
		officeSpace = provider.addOfficeSpaceToKnowledgeGraph(officeSpace);
		endTest("createTest");
	}

	/* (non-Javadoc)
	 * @see cscie97.asn3.squaredesk.test.TestDriverBase#readTest()
	 */
	@Override
	public void readTest() {
		beginTest("readTest"); 
		System.out.println();
		System.out.println("Query after adding officeSpace");
		System.out.println("Features");
		String tempString = "?" + " has_feature " + "?";
		for (Triple foundTriple : KnowledgeGraph.executeQuery(new Triple(tempString))){
			System.out.println(foundTriple.getIdentifier());
		}
		System.out.println();
		System.out.println("Location");
		tempString = "?" + " has_lat_long " + "?";
		for (Triple foundTriple : KnowledgeGraph.executeQuery(new Triple(tempString))){
			System.out.println(foundTriple.getIdentifier());
		}
		for(Feature feature : ContextProvider.getFeatures()){
			officeSpace.removeFeature(ContextProvider.getAuthToken(), feature.getName());
		}	
		endTest("readTest"); 
	}

	/* (non-Javadoc)
	 * @see cscie97.asn3.squaredesk.test.TestDriverBase#init()
	 */
	@Override
	public void init() {
		//providerService = ProviderService.getInstance();
	}

	/* (non-Javadoc)
	 * @see cscie97.asn3.squaredesk.test.TestDriverBase#deleteTest()
	 */
	@Override
	public void deleteTest() 
			throws RatingNotFoundException {
		beginTest("deleteTest");
		System.out.println();
		System.out.println("Query after deleting all features");
		String tempString = "?" + " has_feature " + "?";
		for (Triple foundTriple : KnowledgeGraph.executeQuery(new Triple(tempString))){
			System.out.println(foundTriple.getIdentifier());
		}

		tempString = "?" + " ? " + "?";
		for (Triple foundTriple : KnowledgeGraph.executeQuery(new Triple(tempString))){
			System.out.println(foundTriple.getIdentifier());
		}

		//add Ratings to provider
		provider.addRatingToList(ContextProvider.getRatings().get(0));
		System.out.println("Adding a rating");
		Rating rating = provider.addRatingToList(ContextProvider.getRatings().get(1));
		System.out.println(provider.getRatings());
		//delete rating for the provider
		provider.removeRatingfromList(rating.getRatingId());
		System.out.println("After deleting rating..");
		System.out.println(provider.getRatings());
		endTest("deleteTest"); 
	}

	/* (non-Javadoc)
	 * @see cscie97.asn3.squaredesk.test.TestDriverBase#updateTest()
	 */
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
		System.out.println("After updating OfficeSpace name");
		System.out.println(officeSpace.getName());
		System.out.println(officeSpace1.getName());		
		System.out.println();	
		
		System.out.println("Provider before name change");
		System.out.println(provider.getName());
		System.out.println(provider.getContactInfo().getEmail());
		provider = ProviderService.updateProviderName(ContextProvider.getAuthToken(), 
				provider.getProviderId(), "Vinod Changed Halaharvi");
		System.out.println("Provider After name change");
		provider = ProviderService.getProvider(ContextProvider.getAuthToken(), provider.getProviderId());
		System.out.println(provider.getName());		
		System.out.println(provider.getContactInfo().getEmail());
		System.out.println();

		System.out.println("Provider before picture change ");
		System.out.println(provider.getName());		
		System.out.println(provider.getContactInfo().getEmail());
		System.out.println("Picture URI: " + provider.getImage().getURI());
		ProviderService.updateProviderPicture(ContextProvider.getAuthToken(), 
				provider.getProviderId(), 
				new Image("Amazing Picture From Yahoo", new URI("https://images.yahoo.com")));
		System.out.println("Provider After picture change ");
		System.out.println(provider.getName());		
		System.out.println(provider.getContactInfo().getEmail());
		System.out.println("Picture URI: " + provider.getImage().getURI());
		System.out.println();
		endTest("updateTest");
	}
}
