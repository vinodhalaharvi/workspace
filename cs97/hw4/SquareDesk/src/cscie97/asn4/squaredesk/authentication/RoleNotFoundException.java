/*
 * 
 */
package cscie97.asn4.squaredesk.authentication;

/**
 * The Class RoleNotFoundException.
 */
public class RoleNotFoundException extends Exception {

	/**
	 * Instantiates a new role not found exception.
	 */
	public RoleNotFoundException() {
		super();
	}

	/**
	 * Instantiates a new role not found exception.
	 *
	 * @param message the message
	 * @param cause the cause
	 * @param enableSuppression the enable suppression
	 * @param writableStackTrace the writable stack trace
	 */
	public RoleNotFoundException(String message, Throwable cause,
			boolean enableSuppression, boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
	}

	/**
	 * Instantiates a new role not found exception.
	 *
	 * @param message the message
	 * @param cause the cause
	 */
	public RoleNotFoundException(String message, Throwable cause) {
		super(message, cause);
	}

	/**
	 * Instantiates a new role not found exception.
	 *
	 * @param message the message
	 */
	public RoleNotFoundException(String message) {
		super(message);
	}

	/**
	 * Instantiates a new role not found exception.
	 *
	 * @param cause the cause
	 */
	public RoleNotFoundException(Throwable cause) {
		super(cause);
	}

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = 1L;

}
