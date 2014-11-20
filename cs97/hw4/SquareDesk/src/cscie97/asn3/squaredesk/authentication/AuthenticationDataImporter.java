/*
 * 
 */
package cscie97.asn3.squaredesk.authentication;

import java.util.UUID;

// TODO: Auto-generated Javadoc
/**
 * The Class AuthenticationDataImporter.
 */
public final class AuthenticationDataImporter {

	/**
	 * Instantiates a new authentication data importer.
	 */
	public AuthenticationDataImporter() {
		// TODO Auto-generated constructor stub
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
	 * Define services.
	 *
	 * @throws ServiceAlreadyExistException the service already exist exception
	 */
	public static void defineServices() throws ServiceAlreadyExistException{
		//AuthenticationService.addService(new Service("ProviderService", "Provider Service", "The awesome provider service!!"));
		AuthenticationService.addService(ServiceFactory.createService("ProviderService", "Provider Service", "The awesome provider service!!"));
		AuthenticationService.addService(ServiceFactory.createService("RenterService", "Renter Service", "The awesome Renter service!!"));
		AuthenticationService.addService(ServiceFactory.createService("AuthenticationService", "Authentication Service", "The awesome Authentication service!!"));
	}
	
	/**
	 * Define permissions.
	 *
	 * @throws PermissionAlreadyExistException the permission already exist exception
	 */
	public static void definePermissions() throws PermissionAlreadyExistException{
				AuthenticationService.addPermission(PermissionFactory.createPermission("ProviderService", "getCategory", "get Category", "get  the Category of officeSpace"));
				AuthenticationService.addPermission(PermissionFactory.createPermission("ProviderService", "createProvider", "create the provider", "create this awesome provider!!"));
				AuthenticationService.addPermission(PermissionFactory.createPermission("ProviderService", "getFacilityType", "getFacilityType", "getFacilityType"));
				AuthenticationService.addPermission(PermissionFactory.createPermission("ProviderService", "getProvider", "getProvider" ,"getProvider"));
				AuthenticationService.addPermission(PermissionFactory.createPermission("ProviderService", "deleteProvider", "deleteProvider", "deleteProvider"));
				AuthenticationService.addPermission(PermissionFactory.createPermission("ProviderService", "updateProviderName", "updateProviderName", "updateProviderName"));
				AuthenticationService.addPermission(PermissionFactory.createPermission("ProviderService", "addRatingToProvider", "addRatingToProvider", "addRatingToProvider"));
				AuthenticationService.addPermission(PermissionFactory.createPermission("ProviderService", "removeRatingFromProvider", "removeRatingFromProvider", "removeRatingFromProvider"));
				AuthenticationService.addPermission(PermissionFactory.createPermission("ProviderService", "getRatingListForProvider", "getRatingListForProvider", "getRatingListForProvider"));
				AuthenticationService.addPermission(PermissionFactory.createPermission("ProviderService", "getProviderList", "getProviderList", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("ProviderService", "updateProviderContactInfo", "updateProviderContactInfo", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("ProviderService", "updateProviderPicture", "updateProviderPicture", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("ProviderService", "addOfficeSpaceToProvider", "addOfficeSpaceToProvider", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("ProviderService", "removeOfficeSpaceFromProvider", "removeOfficeSpaceFromProvider", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("ProviderService", "getOfficeSpaceListForProvider", "getOfficeSpaceListForProvider", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("ProviderService", "getOfficeSpace", "getOfficeSpace",""));
		
				AuthenticationService.addPermission(PermissionFactory.createPermission("RenterService", "getBookingService", "getBookingService", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("RenterService", "setBookingService", "setBookingService", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("RenterService", "createRenter", "createRenter", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("RenterService", "getRenterList", "getRenterList", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("RenterService", "getRenter", "getRenter", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("RenterService", "updateRenterName", "updateRenterName", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("RenterService", "updateRenterContactInfo", "updateRenterContactInfo", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("RenterService", "updateRenterPicture", "updateRenterPicture", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("RenterService", "deleteRemter", "deleteRemter", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("RenterService", "addRatingToRenter", "addRatingToRenter", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("RenterService", "removeRatingFromRenter", "removeRatingFromRenter", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("RenterService", "getRatingListForRenter", "getRatingListForRenter", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("RenterService", "getRatingListForRenter", "getRatingListForRenter", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("RenterService", "searchKGUsingFeatures", "searchKGUsingFeatures", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("RenterService", "searchKGUsingLocation", "searchKGUsingLocation", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("RenterService", "searchKGUsingFacilityAndCategory", "searchKGUsingFacilityAndCategory", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("RenterService", "searchKGUsingRating", "searchKGUsingRating", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("RenterService", "searchKGUsingDates", "searchKGUsingDates", ""));
				AuthenticationService.addPermission(PermissionFactory.createPermission("RenterService", "searchKGCriteria", "searchKGCriteria", ""));
		
				
	}
	
	/**
	 * Define roles.
	 *
	 * @throws RoleAlreadyExistException the role already exist exception
	 */
	public static void defineRoles() throws RoleAlreadyExistException{
		AuthenticationService.addEntitlement(RoleFactory.createRole("ProviderRole", "Provider Role", "The amazing role of a provider .. "));
		AuthenticationService.addEntitlement(RoleFactory.createRole("RenterRole", "Renter Role", "The amazing role of a Renter .. "));
		AuthenticationService.addEntitlement(RoleFactory.createRole("AuthenticationRole", "Authentication Role", "The amazing role of a Authentication .. "));
	}
	
	
	/**
	 * Define users.
	 *
	 * @throws UserAlreadyExistException the user already exist exception
	 */
	public static void defineUsers() throws UserAlreadyExistException{
		User user = AuthenticationService.addUser(UserFactory.createUser("testUser1", "JLKJLKSJLU*&(*^^&*^", getUUID()));
		user.setUserDescription("test user in the system"); 
	}
}
