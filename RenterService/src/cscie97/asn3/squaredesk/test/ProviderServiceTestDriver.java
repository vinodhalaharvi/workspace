/**
 * 
 */
package cscie97.asn3.squaredesk.test;
import java.net.URI;
import java.net.URISyntaxException;
import cscie97.asn3.squaredesk.renter.AccessException;
import cscie97.asn3.squaredesk.renter.ContactInfo;
import cscie97.asn3.squaredesk.renter.Image;
import cscie97.asn3.squaredesk.renter.Provider;
import cscie97.asn3.squaredesk.renter.ProviderAlreadyExistException;
import cscie97.asn3.squaredesk.renter.ProviderNotFoundException;
import cscie97.asn3.squaredesk.renter.ProviderService;

/**
 * The Class ProviderServiceTestDriver.
 */
public class ProviderServiceTestDriver extends TestDriverBase {

	/** The provider. */
	private Provider provider;
	
	/** The provider service. */
	private ProviderService providerService; 

	/**
	 * Instantiates a new provider service test driver.
	 */
	public ProviderServiceTestDriver() {
		// TODO Auto-generated constructor stub
	}

	/* (non-Javadoc)
	 * @see cscie97.asn3.squaredesk.test.TestDriverBase#createTest()
	 */
	@Override
	public void createTest() throws ProviderAlreadyExistException,
	AccessException, URISyntaxException, ProviderNotFoundException {
		// TEST CASE 2
		//VERIFY DELETE OF "CRUD" OPERTIONS
		//GET PROVIDER BY GUID
		//DELETE PROVIDER, THIS DELETES ALL THE REFERENCES HELD BY PROVIDER AND 
		//THE CORRESPONDING COMPOSITION OBJECTS
		//features, category and facilityType objects are not composition, so are not deleted
		provider = providerService.createProvider(ContextProvider.getAuthToken(), "Vinod Halaharvi", 
				new ContactInfo("vinod.halaharvi@gmail.com"), 
				new Image("Amazing Picture", new URI("https://images.google.com"))
				);	
		String providerGUID = provider.getProviderId(); 
		providerService.deleteProvider(ContextProvider.getAuthToken(), providerGUID);
		try {
			provider = providerService.getProvider(ContextProvider.getAuthToken(), providerGUID);	
		} catch (ProviderNotFoundException e) {
			System.out.println("Successfully deleted the provider !!");
		} 		
	}

}
