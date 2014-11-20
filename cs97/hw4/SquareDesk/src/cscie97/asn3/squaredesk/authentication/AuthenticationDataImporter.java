/*
 * 
 */
package cscie97.asn3.squaredesk.authentication;

import java.util.UUID;

public final class AuthenticationDataImporter {

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
	
	
	
	public static void defineServices() throws ServiceAlreadyExistException{
		//AuthenticationService.addService(new Service("ProviderService", "Provider Service", "The awesome provider service!!"));
		AuthenticationService.addService(ServiceFactory.createService("ProviderService", "Provider Service", "The awesome provider service!!"));
		//new Service(getUUID(), "RenterService"," RenterService");
		//new Service(getUUID(), "AuthenticationService","AuthenticationService");
	}
	
	public static void definePermissions() throws PermissionAlreadyExistException{
		//AuthenticationService.addPermission(new Permission("getCategory", "ProviderService", "get Category", "get  the Category of officeSpace"));
		AuthenticationService.addPermission(PermissionFactory.createPermission("getCategory", "ProviderService", "get Category", "get  the Category of officeSpace"));
		AuthenticationService.addPermission(PermissionFactory.createPermission("createProvider", "ProviderService", "create the provider", "create this awesome provider!!"));
//		new Permission(getUUID(), AuthenticationService.getServiceByName("ProviderService", "getFacilityType", "getFacilityType");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("ProviderService", "getProvider", "getProvider");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("ProviderService", "deleteProvider", "deleteProvider");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("ProviderService", "updateProviderName", "updateProviderName");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("ProviderService", "addRatingToProvider", "addRatingToProvider");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("ProviderService", "removeRatingFromProvider", "removeRatingFromProvider");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("ProviderService", "getRatingListForProvider", "getRatingListForProvider");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("ProviderService", "getProviderList", "getProviderList");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("ProviderService", "updateProviderContactInfo", "updateProviderContactInfo");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("ProviderService", "updateProviderPicture", "updateProviderPicture");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("ProviderService", "addOfficeSpaceToProvider", "addOfficeSpaceToProvider");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("ProviderService", "removeOfficeSpaceFromProvider", "removeOfficeSpaceFromProvider");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("ProviderService", "getOfficeSpaceListForProvider", "getOfficeSpaceListForProvider");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("ProviderService", "getOfficeSpace", "getOfficeSpace");
//
//		new Permission(getUUID(), AuthenticationService.getServiceByName("RenterService", "getBookingService", "getBookingService");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("RenterService", "setBookingService", "setBookingService");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("RenterService", "createRenter", "createRenter");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("RenterService", "getRenterList", "getRenterList");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("RenterService", "updateRenterName", "updateRenterName");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("RenterService", "updateRenterContactInfo", "updateRenterContactInfo");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("RenterService", "updateRenterPicture", "updateRenterPicture");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("RenterService", "deleteRemter", "deleteRemter");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("RenterService", "addRatingToRenter", "addRatingToRenter");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("RenterService", "removeRatingFromRenter", "removeRatingFromRenter");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("RenterService", "getRatingListForRenter", "getRatingListForRenter");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("RenterService", "getRatingListForRenter", "getRatingListForRenter");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("RenterService", "searchKGUsingFeatures", "searchKGUsingFeatures");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("RenterService", "searchKGUsingLocation", "searchKGUsingLocation");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("RenterService", "searchKGUsingFacilityAndCategory", "searchKGUsingFacilityAndCategory");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("RenterService", "searchKGUsingRating", "searchKGUsingRating");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("RenterService", "searchKGUsingDates", "searchKGUsingDates");
//		new Permission(getUUID(), AuthenticationService.getServiceByName("RenterService", "searchKGCriteria", "searchKGCriteria");

		
	}
	
	public static void defineRoles() throws RoleAlreadyExistException{
		//AuthenticationService.addRole(new Role(getUUID(), AuthenticationService.getServiceByName("ProviderService",  "ProviderRole", "ProviderRole"));
		//AuthenticationService.addEntitlement(new Role("ProviderRole", "Provider Role", "The amazing role of a provider .. "));
		AuthenticationService.addEntitlement(RoleFactory.createRole("ProviderRole", "Provider Role", "The amazing role of a provider .. "));
		//new Role(getUUID(), AuthenticationService.getServiceByName("RenterService",  "RenterRole", "RenterRole");
		//new Role(getUUID(), AuthenticationService.getServiceByName("AuthenticationService",  "AuthenticationRole", "AuthenticationRole");		
	}
	
	
	public static void defineUsers() throws UserAlreadyExistException{
		User user = AuthenticationService.addUser(UserFactory.createUser("testUser1", "testPassword1", getUUID()));
		user.setUserDescription("test user in the system"); 
		//AuthenticationService.addUser(UserFactory.createUser("testUser2", "testPassword2", getUUID()));
		//AuthenticationService.addUser(UserFactory.createUser("testUser3", "testPassword3", getUUID()));
	}
}
