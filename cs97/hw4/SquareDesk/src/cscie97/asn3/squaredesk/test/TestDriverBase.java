/**
 * 
 */
package cscie97.asn3.squaredesk.test;

import java.io.FileNotFoundException;
import java.net.URISyntaxException;
import java.text.ParseException;

import cscie97.asn3.squaredesk.authentication.AccessException;
import cscie97.asn3.squaredesk.authentication.AccessTokenException;
import cscie97.asn3.squaredesk.authentication.AuthenticationException;
import cscie97.asn3.squaredesk.authentication.PermissionAlreadyExistException;
import cscie97.asn3.squaredesk.authentication.RoleAlreadyExistException;
import cscie97.asn3.squaredesk.authentication.ServiceAlreadyExistException;
import cscie97.asn3.squaredesk.authentication.UserAlreadyExistException;
import cscie97.asn3.squaredesk.authentication.UserNotFoundException;
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
	 * @throws ProviderAlreadyExistException the provider already exist exception
	 * @throws AccessException the access exception
	 * @throws URISyntaxException the URI syntax exception
	 * @throws ProviderNotFoundException the provider not found exception
	 * @throws RenterAlreadyExistException the renter already exist exception
	 * @throws RenterNotFoundException the renter not found exception
	 * @throws FileNotFoundException the file not found exception
	 * @throws ParseException the parse exception
	 * @throws UserAlreadyExistException the user already exist exception
	 * @throws ServiceAlreadyExistException the service already exist exception
	 * @throws PermissionAlreadyExistException the permission already exist exception
	 * @throws RoleAlreadyExistException the role already exist exception
	 * @throws AuthenticationException the authentication exception
	 * @throws UserNotFoundException the user not found exception
	 * @throws AccessTokenException the access token exception
	 */
	public void createTest() 
			throws ProviderAlreadyExistException, AccessException, 
			URISyntaxException, ProviderNotFoundException, 
			RenterAlreadyExistException, 
			RenterNotFoundException, 
			FileNotFoundException, ParseException, UserAlreadyExistException, 
			ServiceAlreadyExistException, PermissionAlreadyExistException, 
			RoleAlreadyExistException, AuthenticationException, UserNotFoundException, 
			AccessTokenException{
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
	 *
	 * @throws UserNotFoundException the user not found exception
	 */
	public void readTest() throws UserNotFoundException{
		
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
