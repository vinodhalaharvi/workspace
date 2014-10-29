/**
 * 
 */
package cscie97.asn3.squaredesk.test;

import java.io.FileNotFoundException;
import java.net.URISyntaxException;
import java.text.ParseException;

import cscie97.asn3.squaredesk.renter.AccessException;
import cscie97.asn3.squaredesk.renter.OfficeSpaceNotFoundException;
import cscie97.asn3.squaredesk.renter.ProviderAlreadyExistException;
import cscie97.asn3.squaredesk.renter.ProviderNotFoundException;
import cscie97.asn3.squaredesk.renter.RatingNotFoundException;
import cscie97.asn3.squaredesk.renter.RenterAlreadyExistException;
import cscie97.asn3.squaredesk.renter.RenterNotFoundException;

// TODO: Auto-generated Javadoc
/**
 * The Class TestDriverBase.
 */
public abstract class TestDriverBase {

	/**
	 * Instantiates a new test driver base.
	 */
	public TestDriverBase() {
		// TODO Auto-generated constructor stub
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
	 * @param obj
	 *            the obj
	 * @throws RatingNotFoundException 
	 */
	public void deleteTest() throws RatingNotFoundException{
		
	}

	/**
	 * Update test
	 *
	 * @param obj
	 *            the obj
	 * @throws OfficeSpaceNotFoundException 
	 * @throws AccessException 
	 * @throws ProviderNotFoundException 
	 * @throws URISyntaxException 
	 * @throws RenterNotFoundException 
	 */
	public void updateTest() 
			throws OfficeSpaceNotFoundException, ProviderNotFoundException, AccessException, URISyntaxException, RenterNotFoundException{
		
	}
	
	/**
	 * Read test.
	 *
	 * @param obj
	 *            the obj
	 */
	public void readTest(){
		
	}
	
	public void beginTest(String method){
		System.out.println();
		System.out.println("Beginning " + method);
	}
	
	public void endTest(String method){
		System.out.println();
		System.out.println("Ending " + method);
	}
	
}
