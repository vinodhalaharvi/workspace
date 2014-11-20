/**
 * 
 */
package cscie97.asn3.squaredesk.authentication;

import java.util.HashSet;

import cscie97.asn3.squaredesk.provider.EntitlementNotFoundException;

// TODO: Auto-generated Javadoc
/**
 * The Class Role.
 *
 * @author vinodhalaharvi
 */
public class Role extends Entitlement {

	/**
	 * Instantiates a new role.
	 *
	 * @param roleId the role id
	 * @param roleName            the role name
	 * @param roleDescription            the role description
	 */
	public Role(String roleId, String roleName, String roleDescription) {
		super(roleId);
		this.roleName = roleName;
		this.roleDescription = roleDescription;
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
	 * Gets the role name.
	 *
	 * @return the role name
	 */
	public String getRoleName() {
		return roleName;
	}


	/* (non-Javadoc)
	 * @see java.lang.Object#equals(java.lang.Object)
	 */
	@Override
	public boolean equals(Object obj) {
		Role t = (Role) obj; 
		return (
				(obj != null) &&
				(obj instanceof User) &&
				t.getRoleId().equals((getRoleId()))
				);

	}

	/* (non-Javadoc)
	 * @see java.lang.Object#hashCode()
	 */
	@Override
	public int hashCode() {
		return getRoleId().hashCode();  
	}


	/**
	 * Sets the role name.
	 *
	 * @param roleName
	 *            the new role name
	 */
	public void setRoleName(String roleName) {
		this.roleName = roleName;
	}


	/**
	 * Gets the role description.
	 *
	 * @return the role description
	 */
	public String getRoleDescription() {
		return roleDescription;
	}

	/**
	 * Sets the role description.
	 *
	 * @param roleDescription
	 *            the new role description
	 */
	public void setRoleDescription(String roleDescription) {
		this.roleDescription = roleDescription;
	}

	/**
	 * Adds the entitlement to list.
	 *
	 * @param entitlement the entitlement
	 * @return the entitlement
	 */
	public Entitlement addEntitlementToList(Entitlement entitlement) {	
		entitlements.add(entitlement);
		return entitlement;
	}

	/**
	 * Removes the entitlement from list.
	 *
	 * @param entitlement the entitlement
	 * @throws EntitlementNotFoundException the entitlement not found exception
	 */
	public void removeEntitlementFromList(Entitlement entitlement)
			throws EntitlementNotFoundException{
		if (!entitlements.contains(entitlement)){ 
			throw new EntitlementNotFoundException("Entitlement you are looking is Not Found!"); 
		} else { 
			entitlements.remove(entitlement); 
		}	
	}


	/**
	 * Gets the entitlements.
	 *
	 * @return the entitlements
	 */
	public HashSet<Entitlement> getEntitlements() {
		return entitlements; 
	}


	/** The role name. */
	private String roleName; 
	
	/** The role description. */
	private String roleDescription; 

	

	/**
	 * Gets the roles.
	 *
	 * @return the roles
	 */
	public HashSet<Role> getRoles() {
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
	public  HashSet<Permission> getPermissions() {
		HashSet<Permission> permissions = new HashSet<Permission>();
		for(Entitlement entitlement : entitlements){
			if (entitlement instanceof Permission){
				permissions.add((Permission) entitlement);
			}
		}
		return permissions;
	}

	
	/** The entitlements. */
	private static HashSet<Entitlement> entitlements = new HashSet<Entitlement>();


}

