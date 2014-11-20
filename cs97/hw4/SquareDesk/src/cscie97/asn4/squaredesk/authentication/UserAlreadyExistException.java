/*
 * 
 */
package cscie97.asn4.squaredesk.authentication;

/**
 * The Class UserAlreadyExistException.
 */
public class UserAlreadyExistException extends Exception {

	/**
	 * Instantiates a new user already exist exception.
	 */
	public UserAlreadyExistException() {
		super();
	}

	/**
	 * Instantiates a new user already exist exception.
	 *
	 * @param message the message
	 * @param cause the cause
	 * @param enableSuppression the enable suppression
	 * @param writableStackTrace the writable stack trace
	 */
	public UserAlreadyExistException(String message, Throwable cause,
			boolean enableSuppression, boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
	}

	/**
	 * Instantiates a new user already exist exception.
	 *
	 * @param message the message
	 * @param cause the cause
	 */
	public UserAlreadyExistException(String message, Throwable cause) {
		super(message, cause);
	}

	/**
	 * Instantiates a new user already exist exception.
	 *
	 * @param message the message
	 */
	public UserAlreadyExistException(String message) {
		super(message);
	}

	/**
	 * Instantiates a new user already exist exception.
	 *
	 * @param cause the cause
	 */
	public UserAlreadyExistException(Throwable cause) {
		super(cause);
	}

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = 1L;

}