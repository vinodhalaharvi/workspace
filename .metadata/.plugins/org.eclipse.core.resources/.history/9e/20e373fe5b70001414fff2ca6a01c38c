/*
 * 
 */
package cscie97.asn3.squaredesk.authentication;

import java.util.Collection;
import java.util.HashSet;
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
	public User(String loginName, String password) {
		super();
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
		roles.add(role); 
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
				t.getUserId().equals(getUserId()));
				
	}
	
	/* (non-Javadoc)
	 * @see java.lang.Object#hashCode()
	 */
	@Override
	public int hashCode() {
		return userId.hashCode();  
	}
	
	

	/**
	 * Removes the role from list.
	 *
	 * @param roleId the role id
	 * @throws RoleNotFoundException the role not found exception
	 */
	public void removeRoleFromList(Role role)
			throws RoleNotFoundException{
		if (!roles.contains(role)){ 
			throw new RoleNotFoundException("Role you are looking is Not Found!"); 
		} else { 
			roles.remove(role); 
		}	
	}
	/**
	 * Gets the roles.
	 *
	 * @return the roles
	 */
	public Collection<Role> getRoles() {
		return roles;
	}
	
	/** The user id. */
	private String userId; 
	
	/** The user description. */
	private String userDescription; 
	
	/** The login name. */
	private String loginName; 
	
	/** The password. */
	private String password;
	
	private AccessToken authToken;
	
	public AccessToken getAuthToken() {
		return authToken;
	}

	public void setAuthToken(AccessToken authToken) {
		this.authToken = authToken;
	}

	/** The roles. */
	private static HashSet<Role> roles = new HashSet<Role>();
}