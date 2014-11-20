/*
 * 
 */
package cscie97.asn3.squaredesk.authentication;


// TODO: Auto-generated Javadoc
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
	 * @param entitlementId the entitlement id
	 * @param serviceId the service id
	 * @param permissionName the permission name
	 * @param permissionDescription the permission description
	 * @return the Permission
	 */
	public static Permission createPermission( String entitlementId, String serviceId,
			String permissionName, String permissionDescription 
			) {
		Permission PermissionObj = new Permission(entitlementId, serviceId, permissionName, permissionDescription);
		return PermissionObj; 
	}

}
