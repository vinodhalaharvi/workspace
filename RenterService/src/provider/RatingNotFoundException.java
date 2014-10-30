/**
 * 
 */
package provider;

/**
 * The Class RatingNotFoundException.
 */
public class RatingNotFoundException extends Exception {

	/**
	 * Instantiates a new rating not found exception.
	 *
	 * @param message the message
	 * @param cause the cause
	 */
	public RatingNotFoundException(String message, Throwable cause) {
		super(message, cause);
	}

	/**
	 * Instantiates a new rating not found exception.
	 *
	 * @param message the message
	 */
	public RatingNotFoundException(String message) {
		super(message);
	}

	/**
	 * Instantiates a new rating not found exception.
	 *
	 * @param cause the cause
	 */
	public RatingNotFoundException(Throwable cause) {
		super(cause);
	}

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = -83967778337715361L;
	
}
