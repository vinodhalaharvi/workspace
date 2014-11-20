/*
 * 
 */
package cscie97.asn4.squaredesk.authentication;


/**
 * A factory for creating Permission objects.
 */
public final class PermissionFactory {

	/**
	 * Instantiates a new Permission factory.
	 */
	public PermissionFactory() {
	}
	
	/**
	 * Creates a new Permission object.
	 *
	 * @param serviceId the service id
	 * @param entitlementId the entitlement id
	 * @param permissionName the permission name
	 * @param permissionDescription the permission description
	 * @return the Permission
	 */
	public static Permission createPermission( String serviceId, String entitlementId, 
			String permissionName, String permissionDescription 
			) {
		Permission PermissionObj = new Permission(entitlementId, serviceId, permissionName, permissionDescription);
		return PermissionObj; 
	}

}
