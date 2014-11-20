/**
 * 
 */
package cscie97.asn3.squaredesk.renter;

/**
 * The Class BookingAlreadyExistException.
 */
public class BookingAlreadyExistException extends Exception {

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = 603942381714967996L;
	
	/**
	 * Instantiates a new booking already exist exception.
	 */
	public BookingAlreadyExistException() {
	}

	/**
	 * Instantiates a new booking already exist exception.
	 *
	 * @param message the message
	 */
	public BookingAlreadyExistException(String message) {
		super(message);
	}

	/**
	 * Instantiates a new booking already exist exception.
	 *
	 * @param cause the cause
	 */
	public BookingAlreadyExistException(Throwable cause) {
		super(cause);
	}

	/**
	 * Instantiates a new booking already exist exception.
	 *
	 * @param message the message
	 * @param cause the cause
	 */
	public BookingAlreadyExistException(String message, Throwable cause) {
		super(message, cause);
	}

	/**
	 * Instantiates a new booking already exist exception.
	 *
	 * @param message the message
	 * @param cause the cause
	 * @param enableSuppression the enable suppression
	 * @param writableStackTrace the writable stack trace
	 */
	public BookingAlreadyExistException(String message, Throwable cause,
			boolean enableSuppression, boolean writableStackTrace) {
		super();
	}

}
