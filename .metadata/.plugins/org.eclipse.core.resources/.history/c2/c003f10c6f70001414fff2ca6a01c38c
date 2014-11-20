/*
 * 
 */
package cscie97.asn3.squaredesk.authentication;


// TODO: Auto-generated Javadoc
/**
 * A factory for creating User objects.
 */
public final class UserFactory {

	/**
	 * Instantiates a new user factory.
	 */
	public UserFactory() {
	}
	
	/**
	 * Creates a new User object.
	 *
	 * @param userName the user name
	 * @param loginName the login name
	 * @param password the password
	 * @param uuidName the uuid name
	 * @param userDescription 
	 * @return the user
	 */
	public static User createUser( String loginName, String password, String uuidName 
			) {
		User userObj = new User(loginName, password);
		userObj.setUserId(uuidName); 
		return userObj; 
	}

}
