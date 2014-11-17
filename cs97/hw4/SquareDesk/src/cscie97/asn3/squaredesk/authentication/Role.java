/**
 * 
 */
package cscie97.asn3.squaredesk.authentication;

import java.util.Collection;
import java.util.Map;
import java.util.UUID;

import cscie97.asn3.squaredesk.provider.EntitlementNotFoundException;

/**
 * The Class Role.
 *
 * @author vinodhalaharvi
 */
public class Role extends Entitlement {
	
	/**
	 * Instantiates a new role.
	 *
	 * @param entitlementId
	 *            the entitlement id
	 * @param serviceId
	 *            the service id
	 * @param permissionName
	 *            the permission name
	 * @param permissionDescription
	 *            the permission description
	 */
	public Role(String entitlementId, String serviceId,
			String permissionName, String permissionDescription) {
		super(entitlementId);
		this.serviceId = serviceId;
		this.permissionName = permissionName;
		this.permissionDescription = permissionDescription;
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
	 * @param serviceId
	 *            the new service id
	 */
	public void setServiceId(String serviceId) {
		this.serviceId = serviceId;
	}
	
	/**
	 * Gets the role name.
	 *
	 * @return the role name
	 */
	public String getRoleName() {
		return permissionName;
	}
	
	/**
	 * Gets the role id.
	 *
	 * @return the role id
	 */
	public String getRoleId() {
		return getEntitlementId();
	}

	/**
	 * Sets the role id.
	 *
	 * @param roleId the new role id
	 */
	public void setRoleId(String roleId) {
		setEntitlementId(roleId);
	} 
	
	/**
	 * Sets the role name.
	 *
	 * @param permissionName
	 *            the new role name
	 */
	public void setRoleName(String permissionName) {
		this.permissionName = permissionName;
	}
	
	/**
	 * Gets the role description.
	 *
	 * @return the role description
	 */
	public String getRoleDescription() {
		return permissionDescription;
	}
	
	/**
	 * Sets the role description.
	 *
	 * @param permissionDescription
	 *            the new role description
	 */
	public void setRoleDescription(String permissionDescription) {
		this.permissionDescription = permissionDescription;
	}
	
	/**
	 * Adds the entitlement to list.
	 *
	 * @param entitlement the entitlement
	 * @return the entitlement
	 */
	public Entitlement addEntitlementToList(Entitlement entitlement) {	
		String uuidName = getUUID(); 
		entitlement.setEntitlementId(uuidName); 
		entitlements.put(uuidName, entitlement); 
		return entitlement;
	}

	/**
	 * Gets the uuid.
	 *
	 * @return the uuid
	 */
	protected String getUUID() {
		String uuidStr = UUID.randomUUID().toString(); 
		return uuidStr; 	
	}

	/**
	 * Gets the entitlementfrom list.
	 *
	 * @param entitlementId the entitlement id
	 * @return the entitlementfrom list
	 * @throws EntitlementNotFoundException the entitlement not found exception
	 */
	public Entitlement getEntitlementfromList(String entitlementId) 
			throws EntitlementNotFoundException {
		if (!entitlements.containsKey(entitlementId)){ 
			throw new EntitlementNotFoundException("Entitlement you are looking is Not Found!"); 
		} else { 
			return entitlements.get(entitlementId); 
		}		
	}

	/**
	 * Removes the entitlement from list.
	 *
	 * @param entitlementId the entitlement id
	 * @throws EntitlementNotFoundException the entitlement not found exception
	 */
	public void removeEntitlementFromList(String entitlementId)
			throws EntitlementNotFoundException{
		if (!entitlements.containsKey(entitlementId)){ 
			throw new EntitlementNotFoundException("Entitlement you are looking is Not Found!"); 
		} else { 
			entitlements.remove(entitlementId); 
		}	
	}

	/**
	 * Gets the entitlements.
	 *
	 * @return the entitlements
	 */
	public Collection<Entitlement> getEntitlements() {
		return entitlements.values(); 
	}

	/** The service id. */
	private String serviceId;  
	
	/** The permission name. */
	private String permissionName; 
	
	/** The permission description. */
	private String permissionDescription;

	/** The entitlements. */
	private Map<String, Entitlement> entitlements;


}

