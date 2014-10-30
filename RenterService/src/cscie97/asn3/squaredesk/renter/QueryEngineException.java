/**
 * 
 */
package cscie97.asn3.squaredesk.renter;

/**
 * The Class QueryEngineException.
 */
public class QueryEngineException extends Exception {

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = 3172907704439066607L;

	/**
	 * 
	 */
	public QueryEngineException() {
	}

	/**
	 * @param message
	 */
	public QueryEngineException(String message) {
		super(message);
	}

	/**
	 * @param cause
	 */
	public QueryEngineException(Throwable cause) {
		super(cause);
	}

	/**
	 * @param message
	 * @param cause
	 */
	public QueryEngineException(String message, Throwable cause) {
		super(message, cause);
	}

}
