/*
 * 
 */
package cscie97.asn3.squaredesk.authentication;

/**
 * The Class AuthenticationException.
 */
public class AuthenticationException extends Exception {

	/**
	 * Instantiates a new authentication exception.
	 */
	public AuthenticationException() {
		super();
	}

	/**
	 * Instantiates a new authentication exception.
	 *
	 * @param message the message
	 * @param cause the cause
	 * @param enableSuppression the enable suppression
	 * @param writableStackTrace the writable stack trace
	 */
	public AuthenticationException(String message, Throwable cause,
			boolean enableSuppression, boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
	}

	/**
	 * Instantiates a new authentication exception.
	 *
	 * @param message the message
	 * @param cause the cause
	 */
	public AuthenticationException(String message, Throwable cause) {
		super(message, cause);
	}

	/**
	 * Instantiates a new authentication exception.
	 *
	 * @param message the message
	 */
	public AuthenticationException(String message) {
		super(message);
	}

	/**
	 * Instantiates a new authentication exception.
	 *
	 * @param cause the cause
	 */
	public AuthenticationException(Throwable cause) {
		super(cause);
	}

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = 1L;

}
