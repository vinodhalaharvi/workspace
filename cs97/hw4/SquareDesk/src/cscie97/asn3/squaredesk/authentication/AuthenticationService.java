/*
 * 
 */
package cscie97.asn3.squaredesk.authentication;

import java.util.Calendar;
import java.util.Collection;
import java.util.HashSet;
import java.util.UUID;

/**
 * The Class AuthenticationService.
 */
public final class AuthenticationService {

	/**
	 * Creates the user.
	 */
	public static void createUser(){

	}

	public static boolean isValidUser(String userName, String passwordHash){
		for(User user : users){
			if(user.getLoginName().equals(userName) 
					&& user.getPassword().equals(passwordHash))
				return true; 
		}
		return false; 	
	}	

	//check user name and password
	//and create a authToken with an expiration and state set to active

	public static AccessToken login(User user) 
			throws AuthenticationException, UserNotFoundException{
		String loginName = user.getLoginName();
		String passwordHash = user.getPassword(); 
		if(!isValidUser(loginName, passwordHash)){
			throw new AuthenticationException("userName or Password is NOT valid!");
		}
		return createToken(user);
	}

	public boolean isAccessTokenTimedOut(AccessToken authToken){
		Calendar cal = Calendar.getInstance();
		return authToken.getExpirationTime().before(cal.getTime()); 
	}

	public static void logout(User user) 
			throws AccessTokenException{
		if(user.getAuthToken() == null)
			return; 
		user.getAuthToken().setState("expired");
		return; 
	}


	/**
	 * Adds the entitlement.
	 */
	public static void addEntitlement(Entitlement entitlement){
		entitlements.add(entitlement); 
	}

	/**
	 * Adds the entitlement to role.
	 */
	public static void addEntitlementToRole(Role role, Entitlement entitlement){
		for(Role roleIter : getRoles()){
			if(roleIter.getRoleId().equals(role.getRoleId()))
				roleIter.addEntitlementToList(entitlement); 
		}
	}

	/**
	 * Adds the role to user.
	 */
	public static void addRoleToUser(User user, Role role){
		user.addRoleToList(role); 
	}

	public static Service getServiceById(String serviceId){
		for(Service service : services){
			if(service.getServiceId().equals(serviceId)){
				return service; 
			}
		}
		return null; 
	}

	public static Permission getPermissionById(String permissionId, String serviceId){
		Service service = getServiceById(serviceId);  
		for(Permission permission : getPermissions()){
			if(permission.getPermissionId().equals(permissionId) &&
					permission.getServiceId().equals(service.getServiceId())){
				return permission;
			}
		}
		return null;
	}

	public static boolean hasAccess(String authToken, String serviceId,
			String permissionId){
		User user = getUserByAuthToken(authToken); 
		if (user == null)
			return false;
		Permission permission = getPermissionById(permissionId, serviceId);
		if (permission == null)
			return false; 
		return doesUserHasPermissions(user, permission);
	}

	public static Permission addPermission(Permission perimission)
			throws PermissionAlreadyExistException{
		for(Entitlement entitlement : entitlements){
			Permission perimissionIter = (Permission) entitlement;
			if(perimissionIter.equals(perimission)){
				throw new PermissionAlreadyExistException();
			}
		}
		entitlements.add(perimission);
		return perimission;
	}


	public static HashSet<Service> getServices(){
		return services; 
	}

	
	public static HashSet<User> getUsers(){
		return users; 
	}
	
	public static HashSet<Entitlement> getEntitlements(){
		return entitlements;
	}
	

	public static User addUser(User user) 
			throws UserAlreadyExistException{
		for(User userIter : users){
			if(userIter.equals(user)){
				throw new UserAlreadyExistException(); 
			}	
		}
		users.add(user);
		return user;
	}

	public static Service addService(Service service)
			throws ServiceAlreadyExistException{
		for(Service serviceIter : services){
			if(serviceIter.equals(service)){
				throw new ServiceAlreadyExistException();
			}
		}
		services.add(service);
		return service;
	}

	

    /**
     * Gets the uuid.
     *
     * @return the uuid
     */
    protected static String getUUID() {
            String uuidStr = UUID.randomUUID().toString();
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
	 * @throws UserNotFoundException 
	 */
	public static User createUser(String authToken, String loginName, String passwordHash
			) throws UserAlreadyExistException, AccessException, UserNotFoundException{ 
		User user = getUserByName(loginName, passwordHash);
		if (user != null){
			throw new UserAlreadyExistException("This User Already Exists");
		} else {
			String uuidName = getUUIDFromString(loginName); 
			User userObj = (User) UserFactory.createUser(loginName, passwordHash, uuidName); 
			users.add(userObj);
			return userObj; 
		}
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
	 * Delete user.
	 *
	 * @param authToken the auth token
	 * @param userId the user id
	 * @throws UserNotFoundException the user not found exception
	 * @throws AccessException the access exception
	 */
	public static void deleteUser(String authToken, User user) 
			throws UserNotFoundException, AccessException{
		users.remove(user);
	}

	/**
	 * Gets the rating list for user.
	 *
	 * @param authToken the auth token
	 * @param userId the user id
	 * @return the rating list for user
	 * @throws UserNotFoundException the user not found exception
	 */
	public static Collection<Role> getRoleListForUser(User user)
			throws UserNotFoundException{
		return user.getRoles();
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
		return users;  
	}


	private static boolean doesUserHasPermissions(User user, Permission permission){
		for(Role role : user.getRoles()){
			if (hasPermission(role, permission.getPermissionId())){
				return true; 
			}
		}
		return false; 
	}

	private static boolean hasPermission(Role role, String permissionId){
		if (role.getPermissions() != null) {
			for(Permission permission : role.getPermissions()){ 
				if (permission.getPermissionId().equals(permissionId)){
					return true;
				}
			}
			
		}
		if (role.getRoles() != null){
			for (Role roleIter : role.getRoles()){
				if (hasPermission(roleIter, permissionId))
					return true; //call recursively 
			}
		}
		return false; //return default as false 
	}

	private static AccessToken createToken(User user) {
		Calendar cal = Calendar.getInstance();
		AccessToken authToken =  new AccessToken(getUUID(), cal.getTime(), "active");
		user.setAuthToken(authToken);
		return authToken;
	}

	private static User getUserByName(String loginName, String passwordHash) throws UserNotFoundException{
		for(User user : users){
			if(user.getLoginName().equals(loginName) && 
					user.getPassword().equals(passwordHash))
				return user;
		}
		return null;
	}

	private static User getUserByAuthToken(String authToken){
		for(User user : users){
			if(user.getAuthToken().getAccessTokenId().equals(authToken)){ 
				return user; 
			}
		}
		return null; 
	}


	/** The users. */
	private static HashSet<User> users = new HashSet<User>();
	private static HashSet<Service> services = new HashSet<Service>();
	private static HashSet<Entitlement> entitlements = new HashSet<Entitlement>();
	

	public static HashSet<Role> getRoles() {
		HashSet<Role> roles = new HashSet<Role>(); 
		for(Entitlement entitlement : entitlements){
			if (entitlement instanceof Role){
				roles.add((Role) entitlement); 
			}
		}
		return roles; 
	}

	public static  HashSet<Permission> getPermissions() {
		HashSet<Permission> permissions = new HashSet<Permission>();
		for(Entitlement entitlement : entitlements){
			if (entitlement instanceof Permission){
				permissions.add((Permission) entitlement);
			}
		}
		return permissions;
	}
}