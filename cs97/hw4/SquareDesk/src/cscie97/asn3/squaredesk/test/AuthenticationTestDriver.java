/*
 * 
 */
package cscie97.asn3.squaredesk.test;

import java.io.FileNotFoundException;
import java.net.URISyntaxException;
import java.text.ParseException;

import cscie97.asn3.squaredesk.authentication.AccessException;
import cscie97.asn3.squaredesk.authentication.AccessTokenException;
import cscie97.asn3.squaredesk.authentication.AuthenticationDataImporter;
import cscie97.asn3.squaredesk.authentication.AuthenticationException;
import cscie97.asn3.squaredesk.authentication.AuthenticationService;
import cscie97.asn3.squaredesk.authentication.Entitlement;
import cscie97.asn3.squaredesk.authentication.Permission;
import cscie97.asn3.squaredesk.authentication.PermissionAlreadyExistException;
import cscie97.asn3.squaredesk.authentication.Role;
import cscie97.asn3.squaredesk.authentication.RoleAlreadyExistException;
import cscie97.asn3.squaredesk.authentication.Service;
import cscie97.asn3.squaredesk.authentication.ServiceAlreadyExistException;
import cscie97.asn3.squaredesk.authentication.User;
import cscie97.asn3.squaredesk.authentication.UserAlreadyExistException;
import cscie97.asn3.squaredesk.authentication.UserNotFoundException;
import cscie97.asn3.squaredesk.provider.ProviderAlreadyExistException;
import cscie97.asn3.squaredesk.provider.ProviderNotFoundException;
import cscie97.asn3.squaredesk.renter.RenterAlreadyExistException;
import cscie97.asn3.squaredesk.renter.RenterNotFoundException;

public class AuthenticationTestDriver extends TestDriverBase  {

	public AuthenticationTestDriver() {
		// TODO Auto-generated constructor stub
	}
	
	private User user; 
	private Role role;
	private Permission permission;
	
	@Override
	public void createTest() throws ProviderAlreadyExistException,
			AccessException, URISyntaxException, ProviderNotFoundException,
			RenterAlreadyExistException, RenterNotFoundException,
			FileNotFoundException, ParseException, UserAlreadyExistException, 
			ServiceAlreadyExistException, PermissionAlreadyExistException, 
			RoleAlreadyExistException, AuthenticationException, UserNotFoundException, AccessTokenException {
		
		super.createTest();
		AuthenticationDataImporter.defineServices();
		AuthenticationDataImporter.definePermissions();
		AuthenticationDataImporter.defineUsers();
		user = AuthenticationService.getUsers().iterator().next(); 
		AuthenticationDataImporter.defineRoles();
		role = AuthenticationService.getRoles().iterator().next();
		permission = AuthenticationService.getPermissions().iterator().next();
		AuthenticationService.addEntitlementToRole(role, (Entitlement) permission); 		
		for(Permission permissionIter : AuthenticationService.getPermissions()){
			AuthenticationService.addEntitlementToRole(role, (Entitlement) permissionIter); 
		}
		AuthenticationService.addRoleToUser(user, role);
		//System.out.println(AuthenticationService.doesUserHasPermissions(user, permission));
		//System.out.println("Has access to createProvider?: " 
			//	+ AuthenticationService.hasAccess(user.getAuthToken().getAccessTokenId(), "ProviderService"
			//	,"createProvider")); 
		//user will now try to create a provider
	}

	public void loginUser() throws AuthenticationException, UserNotFoundException{
		System.out.println();
		System.out.println("logging in user .. " + user.getLoginName());
		AuthenticationService.login(user);
		System.out.println("getPassword :"+ user.getPassword());
		System.out.println("getUserId :"+ user.getUserId());
		System.out.println(user.getAuthToken() + " : " + user.getAuthToken().getState());
		System.out.println("getUserDescription :"+ user.getUserDescription());
		System.out.println(user.getUserDescription());
		System.out.println("User logged in");
	}
	
	public void logoutUser() throws AccessTokenException{
		System.out.println();
		System.out.println("logging out user .. " + user.getLoginName());
		AuthenticationService.logout(user); 
		System.out.println("getPassword :"+ user.getPassword());
		System.out.println("getUserId :"+ user.getUserId());
		System.out.println(user.getAuthToken() + " : " + user.getAuthToken().getState());
		System.out.println("getUserDescription :"+ user.getUserDescription());
		System.out.println(user.getUserDescription());
		System.out.println("User logged out");
		
	}
	
	@Override
	public void readTest() throws UserNotFoundException {
		// TODO Auto-generated method stub
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

	public User getUser() {
		return user;
	}
}
