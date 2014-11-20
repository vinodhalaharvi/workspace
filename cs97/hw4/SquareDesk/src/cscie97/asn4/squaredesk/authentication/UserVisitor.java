/*
 * 
 */
package cscie97.asn4.squaredesk.authentication;

/**
 * The Class UserVisitor.
 */
public abstract class UserVisitor {
	
	/**
	 * Instantiates a new user visitor.
	 */
	public UserVisitor() {
		super();
	}

	/**
	 * Visit user list.
	 */
	public void visitUserList(){
		for(User user : AuthenticationService.getUsers()){
			beforeVisitUser(user); 
			visitUser(user);
			afterVisitUser(user); 
		}
	}
	
	/**
	 * Before visit user.
	 *
	 * @param user the user
	 */
	public void beforeVisitUser(User user) {
		System.out.println("Beginning user Visit.. " + user.getLoginName());
	}
	
	/**
	 * After visit user.
	 *
	 * @param user the user
	 */
	public void afterVisitUser(User user) {
		System.out.println("Ending user Visit.. " + user.getLoginName());

	}

	/**
	 * Visit user.
	 *
	 * @param user the user
	 */
	public void visitUser(User user) {
		//this is overridden by the client
		System.out.println("At user visit.. " + user.getLoginName());
	}
}
