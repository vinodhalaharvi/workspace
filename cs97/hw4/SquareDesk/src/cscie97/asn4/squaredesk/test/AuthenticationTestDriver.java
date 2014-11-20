/*
 * 
 */
package cscie97.asn4.squaredesk.test;

import java.io.FileNotFoundException;
import java.net.URISyntaxException;
import java.text.ParseException;

import cscie97.asn4.squaredesk.authentication.AccessException;
import cscie97.asn4.squaredesk.authentication.AccessTokenException;
import cscie97.asn4.squaredesk.authentication.AuthenticationDataImporter;
import cscie97.asn4.squaredesk.authentication.AuthenticationException;
import cscie97.asn4.squaredesk.authentication.AuthenticationService;
import cscie97.asn4.squaredesk.authentication.Entitlement;
import cscie97.asn4.squaredesk.authentication.Permission;
import cscie97.asn4.squaredesk.authentication.PermissionAlreadyExistException;
import cscie97.asn4.squaredesk.authentication.Role;
import cscie97.asn4.squaredesk.authentication.RoleAlreadyExistException;
import cscie97.asn4.squaredesk.authentication.Service;
import cscie97.asn4.squaredesk.authentication.ServiceAlreadyExistException;
import cscie97.asn4.squaredesk.authentication.User;
import cscie97.asn4.squaredesk.authentication.UserAlreadyExistException;
import cscie97.asn4.squaredesk.authentication.UserNotFoundException;
import cscie97.asn4.squaredesk.provider.ProviderAlreadyExistException;
import cscie97.asn4.squaredesk.provider.ProviderNotFoundException;
import cscie97.asn4.squaredesk.renter.RenterAlreadyExistException;
import cscie97.asn4.squaredesk.renter.RenterNotFoundException;

/**
 * The Class AuthenticationTestDriver.
 */
public class AuthenticationTestDriver extends TestDriverBase  {

	/**
	 * Instantiates a new authentication test driver.
	 */
	public AuthenticationTestDriver() {
	}
	
	/** The user. */
	private User user; 
	
	/** The role. */
	private Role role;
	
	/** The permission. */
	private Permission permission;
	
	/* (non-Javadoc)
	 * @see cscie97.asn3.squaredesk.test.TestDriverBase#createTest()
	 */
	@Override
	public void createTest() throws ProviderAlreadyExistException,
			AccessException, URISyntaxException, ProviderNotFoundException,
			RenterAlreadyExistException, RenterNotFoundException,
			FileNotFoundException, ParseException, UserAlreadyExistException, 
			ServiceAlreadyExistException, PermissionAlreadyExistException, 
			RoleAlreadyExistException, AuthenticationException, UserNotFoundException, AccessTokenException {
		
		super.createTest();
		System.out.println();
		System.out.println("Defining service, permission/roles and users in the system");
		AuthenticationDataImporter.defineServices();
		AuthenticationDataImporter.definePermissions();
		AuthenticationDataImporter.defineUsers();
		user = AuthenticationService.getUsers().iterator().next(); 
		AuthenticationDataImporter.defineRoles();
		role = AuthenticationService.getRoles().iterator().next();
		permission = AuthenticationService.getPermissions().iterator().next();
		AuthenticationService.addEntitlementToRole(role, (Entitlement) permission);
		System.out.println("Adding permisions to role");
		for(Permission permissionIter : AuthenticationService.getPermissions()){
			AuthenticationService.addEntitlementToRole(role, (Entitlement) permissionIter); 
		}
		System.out.println("Adding role to the user");
		AuthenticationService.addRoleToUser(user, role);
	}

	/**
	 * Login user.
	 *
	 * @throws AuthenticationException the authentication exception
	 * @throws UserNotFoundException the user not found exception
	 */
	public void loginUser() throws AuthenticationException, UserNotFoundException{
		System.out.println();
		System.out.println("logging in user .. " + user.getLoginName());
		AuthenticationService.login(user);
		System.out.println("\tUser attributes after login");
		System.out.println("\tgetUserId :"+ user.getUserId());
		System.out.println("\t" + user.getAuthToken() + " : " + user.getAuthToken().getState());
		System.out.println("\tgetUserDescription :"+ user.getUserDescription());
		System.out.println("\tUser logged in");
	}
	
	/**
	 * Logout user.
	 *
	 * @throws AccessTokenException the access token exception
	 */
	public void logoutUser() throws AccessTokenException{
		System.out.println();
		System.out.println("logging out user .. " + user.getLoginName());
		AuthenticationService.logout(user);
		
		System.out.println("\tgetUserId :"+ user.getUserId());
		System.out.println("\t" + user.getAuthToken() + " : " + user.getAuthToken().getState());
		System.out.println("\tgetUserDescription :"+ user.getUserDescription());
		System.out.println("\tUser logged out");
		
	}
	
	/* (non-Javadoc)
	 * @see cscie97.asn3.squaredesk.test.TestDriverBase#readTest()
	 */
	@Override
	public void readTest() throws UserNotFoundException {
		super.readTest();
		System.out.println();
		for(Service service : AuthenticationService.getServices()){
			System.out.println("ServiceId:" + service.getServiceId());
			System.out.println("serviceName: " + service.getServiceName());
			System.out.println("serviceDescription: " + service.getServiceDescription());
		}
		for(User user : AuthenticationService.getUsers()){
			System.out.println("getLoginName :"+ user.getLoginName());
			System.out.println("getPassword :"+ user.getPassword());
			System.out.println("getUserId :"+ user.getUserId());
			System.out.println("getAuthToken :" + user.getAuthToken().getAccessTokenId()); 
			System.out.println("getUserDescription :"+ user.getUserDescription());
		}
		for(Permission permission : AuthenticationService.getPermissions()){
			System.out.println("Permission");
			System.out.println("permissiongId: " + permission.getPermissionId());
			System.out.println("permissionName: " + permission.getPermissionName());
			System.out.println("permissionDescription: " + permission.getPermissionDescription());
		}		
		for(User user : AuthenticationService.getUsers()){
			System.out.println("LoginName: " + user.getLoginName());
			System.out.println("Password: " + user.getPassword());
			System.out.println("UserId: " + user.getUserId());
			System.out.println("AutToken: " + user.getAuthToken());
			System.out.println("UsesDescription: " + user.getUserDescription());
		}
		System.out.println();
		System.out.println("Role " + role.getRoleId() + " added to the user " + user.getLoginName());
		System.out.println();
		System.out.println("Following are the roles defined for the user");
		System.out.println(AuthenticationService.getRoleListForUser(user));
	}

	/**
	 * Gets the user.
	 *
	 * @return the user
	 */
	public User getUser() {
		return user;
	}
}
