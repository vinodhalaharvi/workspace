/**
 * 
 */
package cscie97.asn4.squaredesk.test;
import java.net.URI;
import java.net.URISyntaxException;

import cscie97.asn4.squaredesk.authentication.AccessException;
import cscie97.asn4.squaredesk.provider.ContactInfo;
import cscie97.asn4.squaredesk.provider.Image;
import cscie97.asn4.squaredesk.provider.Provider;
import cscie97.asn4.squaredesk.provider.ProviderAlreadyExistException;
import cscie97.asn4.squaredesk.provider.ProviderNotFoundException;
import cscie97.asn4.squaredesk.provider.ProviderService;

/**
 * The Class ProviderServiceTestDriver.
 */
public class ProviderServiceTestDriver extends TestDriverBase {

	/** The provider. */
	private Provider provider;

	/**
	 * Instantiates a new provider service test driver.
	 */
	public ProviderServiceTestDriver() {
	}

	/* (non-Javadoc)
	 * @see cscie97.asn3.squaredesk.test.TestDriverBase#createTest()
	 */
	@Override
	public void createTest() throws ProviderAlreadyExistException,
	AccessException, URISyntaxException, ProviderNotFoundException {
		beginTest("createTest");
		provider = ProviderService.createProvider(ContextProvider.getAuthToken(), "Vinod Halaharvi", 
				new ContactInfo("vinod.halaharvi@gmail.com"), 
				new Image("Amazing Picture", new URI("https://images.google.com"))
				);
		String providerGUID = provider.getProviderId(); 
		ProviderService.deleteProvider(ContextProvider.getAuthToken(), providerGUID);
		try {
			provider = ProviderService.getProvider(ContextProvider.getAuthToken(), providerGUID);	
		} catch (ProviderNotFoundException e) {
			System.out.println("Successfully deleted the provider !!");
		} 	
		endTest("createTest");
	}

}