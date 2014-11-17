/*
 * 
 */
package cscie97.asn3.squaredesk.authentication;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

// TODO: Auto-generated Javadoc
/**
 * The Class AuthenticationService.
 */
public final class AuthenticationService {

	/**
	 * Creates the user.
	 */
	public static void createUser(){
		
	}
	
	/**
	 * Adds the entitlement.
	 */
	public static void addEntitlement(){
		
	}
	
	/**
	 * Adds the entitlement to role.
	 */
	public static void addEntitlementToRole(){
		
	}
	
	/**
	 * Adds the role to user.
	 */
	public static void addRoleToUser(){
		
	}
	
	/**
	 * Gets the UUID from string.
	 *
	 * @param name the name
	 * @return the UUID from string
	 */
	protected static String getUUIDFromString(String name) {
		String uuidStr = UUID.nameUUIDFromBytes(name.getBytes()).toString(); 
		return uuidStr; 	
	}

	/**
	 * Creates the user.
	 *
	 * @param authToken            the auth token
	 * @param name            the name
	 * @param loginName the login name
	 * @param password the password
	 * @return the user
	 * @throws UserAlreadyExistException             the user already exist exception
	 * @throws AccessException             the access exception
	 */
	public static User createUser(String authToken, String name, 
			String loginName, String password
			) throws UserAlreadyExistException, AccessException{ 
		String uuidName = getUUIDFromString(name); 
		if (users.containsKey(uuidName)){
			throw new UserAlreadyExistException("This User Already Exists");
		} else {
			User userObj = (User) UserFactory.createUser(uuidName,
					name, loginName, password); 
			users.put(uuidName, userObj);
			return userObj; 
		}
	}

	/**
	 * Gets the user.
	 *
	 * @param authToken the auth token
	 * @param userId the user id
	 * @return the user
	 * @throws UserNotFoundException the user not found exception
	 * @throws AccessException the access exception
	 */
	public static User getUser(String authToken, String userId) 
			throws UserNotFoundException, AccessException {
		return getUser(userId); 
	}

	/**
	 * Delete user.
	 *
	 * @param authToken the auth token
	 * @param userId the user id
	 * @throws UserNotFoundException the user not found exception
	 * @throws AccessException the access exception
	 */
	public static void deleteUser(String authToken, String userId) 
			throws UserNotFoundException, AccessException{
		users.remove(userId);
	}

	/**
	 * Update user name.
	 *
	 * @param authToken the auth token
	 * @param userId the user id
	 * @param name the name
	 * @return the user
	 * @throws UserNotFoundException the user not found exception
	 * @throws AccessException the access exception
	 */
	public static User updateUserName(String authToken, String userId, String name) 
			throws UserNotFoundException, AccessException{
		User userObj = getUser(userId);
		String userOldName = userObj.getLoginName(); 
		userObj.setLoginName(name);
		String userNewId = getUUIDFromString(name);
		userObj.setUserId(userNewId);
		//remove the mapping with old name since the user name got changed
		users.remove(getUUIDFromString(userOldName)); 
		//reinsert a new entry with new user name
		users.put(userNewId, userObj); 
		return userObj;	
	}

	/**
	 * Adds the rating to user.
	 *
	 * @param authToken the auth token
	 * @param userId the user id
	 * @param rating the rating
	 * @return the rating
	 * @throws UserNotFoundException the user not found exception
	 */
	public static Role addRoleToUser(String authToken, String userId, Role rating)
			throws UserNotFoundException{
		User userObj = getUser(userId); 
		userObj.addRoleToList(rating); 
		return rating; 
	}

	/**
	 * Removes the rating from user.
	 *
	 * @param authToken the auth token
	 * @param userId the user id
	 * @param ratingId the rating id
	 * @throws UserNotFoundException the user not found exception
	 * @throws RoleNotFoundException the rating not found exception
	 */
	public static void removeRoleFromUser(String authToken, String userId, String ratingId) 
			throws UserNotFoundException, RoleNotFoundException{
		User userObj = getUser(userId); 
		userObj.removeRoleFromList(ratingId); 
	}

	/**
	 * Gets the rating list for user.
	 *
	 * @param authToken the auth token
	 * @param userId the user id
	 * @return the rating list for user
	 * @throws UserNotFoundException the user not found exception
	 */
	public static Collection<Role> getRoleListForUser(String authToken, String userId)
			throws UserNotFoundException{
		User userObj = getUser(userId); 
		return userObj.getRoles();
	}

	/**
	 * Gets the user list.
	 *
	 * @param authToken the auth token
	 * @return the user list
	 * @throws AccessException the access exception
	 */
	public static Collection<User> getUserList(String authToken)
			throws AccessException{
		return users.values();  
	}

	/**
	 * Gets the user.
	 *
	 * @param userId the user id
	 * @return the user
	 * @throws UserNotFoundException the user not found exception
	 */
	private static User getUser(String userId) 
			throws UserNotFoundException {
		if (!users.containsKey(userId)){
			throw new UserNotFoundException("This User Already Exists"); 
		} else { 
			return users.get(userId); 
		}
	}

	/** The users. */
	private static Map<String, User> users = new HashMap<String, User>();
}