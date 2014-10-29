/*
 * ProviderService package provides Provider Service API.
 * This API handles OfficeSpaceProvider and OfficeSpace related CRUD operations
 */
package cscie97.asn3.squaredesk.renter;

/**
 * The Class AccessException. 
 * Create AccessException if the user does not have rights to perform this Access
 */
public class AccessException extends Exception {

	/**
	 * Instantiates a new access exception.
	 *
	 * @param message the message
	 */
	public AccessException(String message) {
		super(message);
	}

	/**
	 * Instantiates a new access exception.
	 *
	 * @param throwable the throwable
	 */
	public AccessException(Throwable throwable) {
		super(throwable);
	}

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = 1L;
}
