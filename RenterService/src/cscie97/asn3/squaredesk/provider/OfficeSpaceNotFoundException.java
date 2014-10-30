/*
 * 
 */
package cscie97.asn3.squaredesk.provider;

/**
 * The Class OfficeSpaceNotFoundException.
 */
public class OfficeSpaceNotFoundException extends Exception {

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = -2472223134923925391L;

	/**
	 * Instantiates a new office space not found exception.
	 *
	 * @param message the message
	 * @param cause the cause
	 */
	public OfficeSpaceNotFoundException(String message, Throwable cause) {
		super(message, cause);
	}
	
	
	/**
	 * Instantiates a new office space not found exception.
	 *
	 * @param message the message
	 */
	public OfficeSpaceNotFoundException(String message) {
		super(message);
	}

	
	/**
	 * Instantiates a new office space not found exception.
	 *
	 * @param throwable the throwable
	 */
	public OfficeSpaceNotFoundException(Throwable throwable) {
		super(throwable);
	}

}
