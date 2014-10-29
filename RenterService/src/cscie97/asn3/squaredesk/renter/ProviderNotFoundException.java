/**
 * 
 */
package cscie97.asn3.squaredesk.renter;

/**
 * The Class ProviderNotFoundException.
 *
 * @author Vinod Halaharvi
 */
public class ProviderNotFoundException extends Exception {

	/**
	 * Instantiates a new provider not found exception.
	 *
	 * @param message the message
	 * @param cause the cause
	 */
	public ProviderNotFoundException(String message, Throwable cause) {
		super(message, cause);
	}

	/**
	 * Instantiates a new provider not found exception.
	 *
	 * @param message the message
	 */
	public ProviderNotFoundException(String message) {
		super(message);
	}

	/**
	 * Instantiates a new provider not found exception.
	 *
	 * @param cause the cause
	 */
	public ProviderNotFoundException(Throwable cause) {
		super(cause);
	}

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = -3997693268379396482L;

}
