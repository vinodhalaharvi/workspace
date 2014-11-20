/*
 * 
 */
package cscie97.asn3.squaredesk.authentication;

/**
 * The Class RoleAlreadyExistException.
 */
public class RoleAlreadyExistException extends Exception {

	/**
	 * Instantiates a new role already exist exception.
	 */
	public RoleAlreadyExistException() {
		super();
	}

	/**
	 * Instantiates a new role already exist exception.
	 *
	 * @param arg0 the arg0
	 * @param arg1 the arg1
	 * @param arg2 the arg2
	 * @param arg3 the arg3
	 */
	public RoleAlreadyExistException(String arg0, Throwable arg1, boolean arg2,
			boolean arg3) {
		super(arg0, arg1, arg2, arg3);
	}

	/**
	 * Instantiates a new role already exist exception.
	 *
	 * @param arg0 the arg0
	 * @param arg1 the arg1
	 */
	public RoleAlreadyExistException(String arg0, Throwable arg1) {
		super(arg0, arg1);
	}

	/**
	 * Instantiates a new role already exist exception.
	 *
	 * @param arg0 the arg0
	 */
	public RoleAlreadyExistException(String arg0) {
		super(arg0);
	}

	/**
	 * Instantiates a new role already exist exception.
	 *
	 * @param arg0 the arg0
	 */
	public RoleAlreadyExistException(Throwable arg0) {
		super(arg0);
	}

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = 1L;

}
