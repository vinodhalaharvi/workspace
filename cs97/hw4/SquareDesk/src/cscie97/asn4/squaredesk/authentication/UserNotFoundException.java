/*
 * 
 */
package cscie97.asn4.squaredesk.authentication;

/**
 * The Class UserNotFoundException.
 */
public class UserNotFoundException extends Exception {

	/**
	 * Instantiates a new user not found exception.
	 */
	public UserNotFoundException() {
		super();
	}

	/**
	 * Instantiates a new user not found exception.
	 *
	 * @param message the message
	 * @param cause the cause
	 * @param enableSuppression the enable suppression
	 * @param writableStackTrace the writable stack trace
	 */
	public UserNotFoundException(String message, Throwable cause,
			boolean enableSuppression, boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
	}

	/**
	 * Instantiates a new user not found exception.
	 *
	 * @param message the message
	 * @param cause the cause
	 */
	public UserNotFoundException(String message, Throwable cause) {
		super(message, cause);
	}

	/**
	 * Instantiates a new user not found exception.
	 *
	 * @param cause the cause
	 */
	public UserNotFoundException(Throwable cause) {
		super(cause);
	}

	/**
	 * Instantiates a new user not found exception.
	 *
	 * @param string the string
	 */
	public UserNotFoundException(String string) {
	}

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = 1L;

}
