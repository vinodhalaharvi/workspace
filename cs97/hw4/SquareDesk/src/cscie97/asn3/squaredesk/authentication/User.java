package cscie97.asn3.squaredesk.authentication;

import java.util.Collection;
import java.util.Map;
/**
 * 
 */
import java.util.UUID;

/**
 * @author vinodhalaharvi
 *
 */
public class User {
	public User() {
		super();
	}

	public User(String userName,
			String loginName, String password) {
		super();
		this.userName = userName;
		this.loginName = loginName;
		this.password = password;
	}

	public String getUserId() {
		return userId;
	}
	public void setUserId(String userId) {
		this.userId = userId;
	}
	public String getUserName() {
		return userName;
	}
	public void setUserName(String userName) {
		this.userName = userName;
	}
	public String getUserDescription() {
		return userDescription;
	}
	public void setUserDescription(String userDescription) {
		this.userDescription = userDescription;
	}
	public String getLoginName() {
		return loginName;
	}
	public void setLoginName(String loginName) {
		this.loginName = loginName;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	/**
	 * Adds the role to list.
	 *
	 * @param role the role
	 * @return the role
	 */
	public Role addRoleToList(Role role) {	
		String uuidName = getUUID(); 
		role.setEntitlementId(uuidName); 
		roles.put(uuidName, role); 
		return role;
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
	 * Gets the rolefrom list.
	 *
	 * @param roleId the role id
	 * @return the rolefrom list
	 * @throws RoleNotFoundException the role not found exception
	 */
	public Role getRolefromList(String roleId) 
			throws RoleNotFoundException {
		if (!roles.containsKey(roleId)){ 
			throw new RoleNotFoundException("Role you are looking is Not Found!"); 
		} else { 
			return roles.get(roleId); 
		}		
	}
	/**
	 * Removes the role from list.
	 *
	 * @param roleId the role id
	 * @throws RoleNotFoundException the role not found exception
	 */
	public void removeRoleFromList(String roleId)
			throws RoleNotFoundException{
		if (!roles.containsKey(roleId)){ 
			throw new RoleNotFoundException("Role you are looking is Not Found!"); 
		} else { 
			roles.remove(roleId); 
		}	
	}
	/**
	 * Gets the roles.
	 *
	 * @return the roles
	 */
	public Collection<Role> getRoles() {
		return roles.values(); 
	}
	private String userId; 
	private String userName; 
	private String userDescription; 
	private String loginName; 
	private String password;
	/** The roles. */
	private Map<String, Role> roles; 
}