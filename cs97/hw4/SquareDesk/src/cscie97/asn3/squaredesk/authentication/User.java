/*
 * 
 */
package cscie97.asn3.squaredesk.authentication;

import java.util.Collection;
import java.util.Map;
/**
 * 
 */
import java.util.UUID;

// TODO: Auto-generated Javadoc
/**
 * The Class User.
 *
 * @author vinodhalaharvi
 */
public class User {
	
	/**
	 * Instantiates a new user.
	 */
	public User() {
		super();
	}

	/**
	 * Instantiates a new user.
	 *
	 * @param userName the user name
	 * @param loginName the login name
	 * @param password the password
	 */
	public User(String userName,
			String loginName, String password) {
		super();
		this.userName = userName;
		this.loginName = loginName;
		this.password = password;
	}

	/**
	 * Gets the user id.
	 *
	 * @return the user id
	 */
	public String getUserId() {
		return userId;
	}
	
	/**
	 * Sets the user id.
	 *
	 * @param userId the new user id
	 */
	public void setUserId(String userId) {
		this.userId = userId;
	}
	
	/**
	 * Gets the user name.
	 *
	 * @return the user name
	 */
	public String getUserName() {
		return userName;
	}
	
	/**
	 * Sets the user name.
	 *
	 * @param userName the new user name
	 */
	public void setUserName(String userName) {
		this.userName = userName;
	}
	
	/**
	 * Gets the user description.
	 *
	 * @return the user description
	 */
	public String getUserDescription() {
		return userDescription;
	}
	
	/**
	 * Sets the user description.
	 *
	 * @param userDescription the new user description
	 */
	public void setUserDescription(String userDescription) {
		this.userDescription = userDescription;
	}
	
	/**
	 * Gets the login name.
	 *
	 * @return the login name
	 */
	public String getLoginName() {
		return loginName;
	}
	
	/**
	 * Sets the login name.
	 *
	 * @param loginName the new login name
	 */
	public void setLoginName(String loginName) {
		this.loginName = loginName;
	}
	
	/**
	 * Gets the password.
	 *
	 * @return the password
	 */
	public String getPassword() {
		return password;
	}
	
	/**
	 * Sets the password.
	 *
	 * @param password the new password
	 */
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
	
	
	/* (non-Javadoc)
	 * @see java.lang.Object#equals(java.lang.Object)
	 */
	@Override
	public boolean equals(Object obj) {
		User t = (User) obj; 
		return (
				(obj != null) &&
				(obj instanceof User) &&
				t.getUserName().equals(getUserName()) &&
				t.getPassword().equals(getPassword())
				);
				
	}
	
	/* (non-Javadoc)
	 * @see java.lang.Object#hashCode()
	 */
	@Override
	public int hashCode() {
		return userName.hashCode() + password.hashCode();  
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
	
	/** The user id. */
	private String userId; 
	
	/** The user name. */
	private String userName; 
	
	/** The user description. */
	private String userDescription; 
	
	/** The login name. */
	private String loginName; 
	
	/** The password. */
	private String password;
	/** The roles. */
	private Map<String, Role> roles; 
}