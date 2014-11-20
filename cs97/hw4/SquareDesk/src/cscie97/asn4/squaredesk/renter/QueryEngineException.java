/**
 * 
 */
package cscie97.asn4.squaredesk.renter;

/**
 * The Class QueryEngineException.
 */
public class QueryEngineException extends Exception {

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = 3172907704439066607L;

	/**
	 * Instantiates a new query engine exception.
	 */
	public QueryEngineException() {
	}

	/**
	 * Instantiates a new query engine exception.
	 *
	 * @param message the message
	 */
	public QueryEngineException(String message) {
		super(message);
	}

	/**
	 * Instantiates a new query engine exception.
	 *
	 * @param cause the cause
	 */
	public QueryEngineException(Throwable cause) {
		super(cause);
	}

	/**
	 * Instantiates a new query engine exception.
	 *
	 * @param message the message
	 * @param cause the cause
	 */
	public QueryEngineException(String message, Throwable cause) {
		super(message, cause);
	}

}