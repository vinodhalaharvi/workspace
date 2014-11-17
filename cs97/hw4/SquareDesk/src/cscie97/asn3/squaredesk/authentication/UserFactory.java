/*
 * 
 */
package cscie97.asn3.squaredesk.authentication;


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
	 * @param user
	 *            the user
	 * @param name
	 *            the name
	 * @param contactInfo
	 *            the contact info
	 * @param picture
	 *            the picture
	 * @param uuidName
	 *            the uuid name
	 * @return the user
	 */
	public static User createUser(String userName, 
			String loginName, String password, String uuidName
			) {
		User userObj = new User(userName, loginName, password);
		userObj.setUserId(uuidName); 
		return userObj; 
	}

}
