/**
 * 
 */
package cscie97.asn3.squaredesk.renter;

/**
 * @author s2687
 *
 */
public class BookingAlreadyExistException extends Exception {

	/**
	 * 
	 */
	private static final long serialVersionUID = 603942381714967996L;

	/**
	 * 
	 */
	public BookingAlreadyExistException() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param message
	 */
	public BookingAlreadyExistException(String message) {
		super(message);
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param cause
	 */
	public BookingAlreadyExistException(Throwable cause) {
		super(cause);
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param message
	 * @param cause
	 */
	public BookingAlreadyExistException(String message, Throwable cause) {
		super(message, cause);
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param message
	 * @param cause
	 * @param enableSuppression
	 * @param writableStackTrace
	 */
	public BookingAlreadyExistException(String message, Throwable cause,
			boolean enableSuppression, boolean writableStackTrace) {
		super();
		// TODO Auto-generated constructor stub
	}

}
