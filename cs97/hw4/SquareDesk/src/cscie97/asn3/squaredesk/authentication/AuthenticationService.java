/*
 * 
 */
package cscie97.asn3.squaredesk.authentication;

import java.util.Calendar;
import java.util.Collection;
import java.util.HashSet;
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
	 * Checks if is valid user.
	 *
	 * @param userName the user name
	 * @param passwordHash the password hash
	 * @return true, if is valid user
	 */
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

	/**
	 * Login.
	 *
	 * @param user the user
	 * @return the access token
	 * @throws AuthenticationException the authentication exception
	 * @throws UserNotFoundException the user not found exception
	 */
	public static AccessToken login(User user) 
			throws AuthenticationException, UserNotFoundException{
		String loginName = user.getLoginName();
		String passwordHash = user.getPassword(); 
		if(!isValidUser(loginName, passwordHash)){
			throw new AuthenticationException("userName or Password is NOT valid!");
		}
		return createToken(user);
	}

	/**
	 * Checks if is access token timed out.
	 *
	 * @param authToken the auth token
	 * @return true, if is access token timed out
	 */
	public boolean isAccessTokenTimedOut(AccessToken authToken){
		Calendar cal = Calendar.getInstance();
		return authToken.getExpirationTime().before(cal.getTime()); 
	}

	/**
	 * Logout.
	 *
	 * @param user the user
	 * @throws AccessTokenException the access token exception
	 */
	public static void logout(User user) 
			throws AccessTokenException{
		if(user.getAuthToken() == null)
			return; 
		user.getAuthToken().setState("expired");
		return; 
	}


	/**
	 * Adds the entitlement.
	 *
	 * @param entitlement the entitlement
	 */
	public static void addEntitlement(Entitlement entitlement){
		entitlements.add(entitlement); 
	}

	/**
	 * Adds the entitlement to role.
	 *
	 * @param role the role
	 * @param entitlement the entitlement
	 */
	public static void addEntitlementToRole(Role role, Entitlement entitlement){
		for(Role roleIter : getRoles()){
			if(roleIter.getRoleId().equals(role.getRoleId()))
				roleIter.addEntitlementToList(entitlement); 
		}
	}

	/**
	 * Adds the role to user.
	 *
	 * @param user the user
	 * @param role the role
	 */
	public static void addRoleToUser(User user, Role role){
		user.addRoleToList(role); 
	}

	/**
	 * Gets the service by id.
	 *
	 * @param serviceId the service id
	 * @return the service by id
	 */
	public static Service getServiceById(String serviceId){
		for(Service service : services){
			if(service.getServiceId().equals(serviceId)){
				return service; 
			}
		}
		return null; 
	}

	/**
	 * Gets the permission by id.
	 *
	 * @param permissionId the permission id
	 * @param serviceId the service id
	 * @return the permission by id
	 */
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

	/**
	 * Checks for access.
	 *
	 * @param authToken the auth token
	 * @param serviceId the service id
	 * @param permissionId the permission id
	 * @return true, if successful
	 */
	public static boolean hasAccess(String authToken, String serviceId,
			String permissionId){
		User user = getUserByAuthToken(authToken); 
		Calendar cal = Calendar.getInstance(); 
		if (user == null){
			return false;
		}
		if (user.getAuthToken().getState() != "active" ||
				user.getAuthToken().getExpirationTime().before(cal.getTime())){
			return false;
		}
		Permission permission = getPermissionById(permissionId, serviceId);
		if (permission == null)
			return false; 
		return doesUserHasPermissions(user, permission);
	}

	/**
	 * Adds the permission.
	 *
	 * @param perimission the perimission
	 * @return the permission
	 * @throws PermissionAlreadyExistException the permission already exist exception
	 */
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


	/**
	 * Gets the services.
	 *
	 * @return the services
	 */
	public static HashSet<Service> getServices(){
		return services; 
	}

	
	/**
	 * Gets the users.
	 *
	 * @return the users
	 */
	public static HashSet<User> getUsers(){
		return users; 
	}
	
	/**
	 * Gets the entitlements.
	 *
	 * @return the entitlements
	 */
	public static HashSet<Entitlement> getEntitlements(){
		return entitlements;
	}
	

	/**
	 * Adds the user.
	 *
	 * @param user the user
	 * @return the user
	 * @throws UserAlreadyExistException the user already exist exception
	 */
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

	/**
	 * Adds the service.
	 *
	 * @param service the service
	 * @return the service
	 * @throws ServiceAlreadyExistException the service already exist exception
	 */
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
	 * @param loginName the login name
	 * @param passwordHash the password hash
	 * @return the user
	 * @throws UserAlreadyExistException             the user already exist exception
	 * @throws AccessException             the access exception
	 * @throws UserNotFoundException the user not found exception
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
	 * @param user the user
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
	 * @param user the user
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


	/**
	 * Does user has permissions.
	 *
	 * @param user the user
	 * @param permission the permission
	 * @return true, if successful
	 */
	private static boolean doesUserHasPermissions(User user, Permission permission){
		for(Role role : user.getRoles()){
			if (hasPermission(role, permission.getPermissionId())){
				return true; 
			}
		}
		return false; 
	}

	/**
	 * Checks for permission.
	 *
	 * @param role the role
	 * @param permissionId the permission id
	 * @return true, if successful
	 */
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

	/**
	 * Creates the token.
	 *
	 * @param user the user
	 * @return the access token
	 */
	private static AccessToken createToken(User user) {
		Calendar cal = Calendar.getInstance();
		cal.add(Calendar.DATE, 90); //token will expire in 90 days
		AccessToken authToken =  new AccessToken(getUUID(), cal.getTime(), "active");
		user.setAuthToken(authToken);
		return authToken;
	}

	/**
	 * Gets the user by name.
	 *
	 * @param loginName the login name
	 * @param passwordHash the password hash
	 * @return the user by name
	 * @throws UserNotFoundException the user not found exception
	 */
	private static User getUserByName(String loginName, String passwordHash) throws UserNotFoundException{
		for(User user : users){
			if(user.getLoginName().equals(loginName) && 
					user.getPassword().equals(passwordHash))
				return user;
		}
		return null;
	}

	/**
	 * Gets the user by auth token.
	 *
	 * @param authToken the auth token
	 * @return the user by auth token
	 */
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
	
	/** The services. */
	private static HashSet<Service> services = new HashSet<Service>();
	
	/** The entitlements. */
	private static HashSet<Entitlement> entitlements = new HashSet<Entitlement>();
	

	/**
	 * Gets the roles.
	 *
	 * @return the roles
	 */
	public static HashSet<Role> getRoles() {
		HashSet<Role> roles = new HashSet<Role>(); 
		for(Entitlement entitlement : entitlements){
			if (entitlement instanceof Role){
				roles.add((Role) entitlement); 
			}
		}
		return roles; 
	}

	/**
	 * Gets the permissions.
	 *
	 * @return the permissions
	 */
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