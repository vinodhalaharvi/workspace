/*
 * 
 */
package cscie97.asn4.squaredesk.provider;

/**
 * The Class EntitlementNotFoundException.
 */
public class EntitlementNotFoundException extends Exception {

	/**
	 * Instantiates a new entitlement not found exception.
	 */
	public EntitlementNotFoundException() {
		super();
	}

	/**
	 * Instantiates a new entitlement not found exception.
	 *
	 * @param message the message
	 * @param cause the cause
	 * @param enableSuppression the enable suppression
	 * @param writableStackTrace the writable stack trace
	 */
	public EntitlementNotFoundException(String message, Throwable cause,
			boolean enableSuppression, boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
	}

	/**
	 * Instantiates a new entitlement not found exception.
	 *
	 * @param message the message
	 * @param cause the cause
	 */
	public EntitlementNotFoundException(String message, Throwable cause) {
		super(message, cause);
	}

	/**
	 * Instantiates a new entitlement not found exception.
	 *
	 * @param message the message
	 */
	public EntitlementNotFoundException(String message) {
		super(message);
	}

	/**
	 * Instantiates a new entitlement not found exception.
	 *
	 * @param cause the cause
	 */
	public EntitlementNotFoundException(Throwable cause) {
		super(cause);
	}

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = 1L;

}