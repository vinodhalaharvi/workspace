/**
 * 
 */
package cscie97.asn4.squaredesk.authentication;

/**
 * The Class Permission.
 *
 * @author vinodhalaharvi
 */
public class Permission extends Entitlement {

	/**
	 * Instantiates a new permission.
	 *
	 * @param entitlementId the entitlement id
	 * @param serviceId the service id
	 * @param permissionName the permission name
	 * @param permissionDescription the permission description
	 */
	public Permission(String entitlementId, String serviceId,
			String permissionName, String permissionDescription) {
		super(entitlementId);
		this.serviceId = serviceId;
		this.permissionName = permissionName;
		this.permissionDescription = permissionDescription;
	}

	/**
	 * Gets the role id.
	 *
	 * @return the role id
	 */
	public String getPermissionId() {
		return getEntitlementId();
	}

	/**
	 * Sets the role id.
	 *
	 * @param roleId the new role id
	 */
	public void setPermissionId(String roleId) {
		setEntitlementId(roleId);
	} 


	/* (non-Javadoc)
	 * @see java.lang.Object#equals(java.lang.Object)
	 */
	@Override
	public boolean equals(Object obj) {
		Permission t = (Permission) obj;
		return (
				(obj != null) &&
				(obj instanceof User) &&
				t.getPermissionId().equals((getPermissionId()))
				);

	}

	/* (non-Javadoc)
	 * @see java.lang.Object#hashCode()
	 */
	@Override
	public int hashCode() {
		return getPermissionId().hashCode();
	}




	/**
	 * Gets the service id.
	 *
	 * @return the service id
	 */
	public String getServiceId() {
		return serviceId;
	}

	/**
	 * Sets the service id.
	 *
	 * @param serviceId the new service id
	 */
	public void setServiceId(String serviceId) {
		this.serviceId = serviceId;
	}

	/**
	 * Gets the permission name.
	 *
	 * @return the permission name
	 */
	public String getPermissionName() {
		return permissionName;
	}

	/**
	 * Sets the permission name.
	 *
	 * @param permissionName the new permission name
	 */
	public void setPermissionName(String permissionName) {
		this.permissionName = permissionName;
	}

	/**
	 * Gets the permission description.
	 *
	 * @return the permission description
	 */
	public String getPermissionDescription() {
		return permissionDescription;
	}

	/**
	 * Sets the permission description.
	 *
	 * @param permissionDescription the new permission description
	 */
	public void setPermissionDescription(String permissionDescription) {
		this.permissionDescription = permissionDescription;
	}

	/** The service id. */
	private String serviceId;  

	/** The permission name. */
	private String permissionName; 

	/** The permission description. */
	private String permissionDescription; 


}
