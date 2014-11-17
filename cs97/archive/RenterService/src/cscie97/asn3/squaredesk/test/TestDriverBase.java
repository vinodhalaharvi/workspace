/**
 * 
 */
package cscie97.asn3.squaredesk.test;

import java.io.FileNotFoundException;
import java.net.URISyntaxException;
import java.text.ParseException;

import cscie97.asn3.squaredesk.provider.AccessException;
import cscie97.asn3.squaredesk.provider.OfficeSpaceNotFoundException;
import cscie97.asn3.squaredesk.provider.ProviderAlreadyExistException;
import cscie97.asn3.squaredesk.provider.ProviderNotFoundException;
import cscie97.asn3.squaredesk.provider.RatingNotFoundException;
import cscie97.asn3.squaredesk.renter.RenterAlreadyExistException;
import cscie97.asn3.squaredesk.renter.RenterNotFoundException;

/**
 * The Class TestDriverBase.
 */
public abstract class TestDriverBase {

	/**
	 * Instantiates a new test driver base.
	 */
	public TestDriverBase() {
	}
	
	/**
	 * Inits the.
	 */
	public void init() {
		
	}
	
	/**
	 * Creates the test.
	 *
	 * @return the object
	 * @throws URISyntaxException 
	 * @throws AccessException 
	 * @throws ProviderAlreadyExistException 
	 * @throws ProviderNotFoundException 
	 * @throws RenterNotFoundException 
	 * @throws RenterAlreadyExistException 
	 * @throws ParseException 
	 * @throws FileNotFoundException 
	 */
	public void createTest() 
			throws ProviderAlreadyExistException, AccessException, 
			URISyntaxException, ProviderNotFoundException, 
			RenterAlreadyExistException, 
			RenterNotFoundException, FileNotFoundException, ParseException{
	}
	
	/**
	 * Delete test.
	 *
	 * @throws RatingNotFoundException
	 *             the rating not found exception
	 */
	public void deleteTest() throws RatingNotFoundException{
		
	}

	/**
	 * Update test.
	 *
	 * @throws OfficeSpaceNotFoundException
	 *             the office space not found exception
	 * @throws ProviderNotFoundException
	 *             the provider not found exception
	 * @throws AccessException
	 *             the access exception
	 * @throws URISyntaxException
	 *             the URI syntax exception
	 * @throws RenterNotFoundException
	 *             the renter not found exception
	 */
	public void updateTest() 
			throws OfficeSpaceNotFoundException, ProviderNotFoundException, AccessException, URISyntaxException, RenterNotFoundException{
		
	}
	
	/**
	 * Read test.
	 */
	public void readTest(){
		
	}
	
	/**
	 * Begin test.
	 *
	 * @param method
	 *            the method
	 */
	public void beginTest(String method){
		System.out.println();
		System.out.println("Beginning " + method);
	}
	
	/**
	 * End test.
	 *
	 * @param method
	 *            the method
	 */
	public void endTest(String method){
		System.out.println();
		System.out.println("Ending " + method);
	}
}
