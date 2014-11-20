/*
 * 
 */
package cscie97.asn4.squaredesk.authentication;

/**
 * The Class AccessTokenException.
 */
public class AccessTokenException extends Exception {

	/**
	 * Instantiates a new access token exception.
	 */
	public AccessTokenException() {
		super();
	}

	/**
	 * Instantiates a new access token exception.
	 *
	 * @param message the message
	 * @param cause the cause
	 * @param enableSuppression the enable suppression
	 * @param writableStackTrace the writable stack trace
	 */
	public AccessTokenException(String message, Throwable cause,
			boolean enableSuppression, boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
	}

	/**
	 * Instantiates a new access token exception.
	 *
	 * @param message the message
	 * @param cause the cause
	 */
	public AccessTokenException(String message, Throwable cause) {
		super(message, cause);
	}

	/**
	 * Instantiates a new access token exception.
	 *
	 * @param message the message
	 */
	public AccessTokenException(String message) {
		super(message);
	}

	/**
	 * Instantiates a new access token exception.
	 *
	 * @param cause the cause
	 */
	public AccessTokenException(Throwable cause) {
		super(cause);
	}

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = 1L;

}
