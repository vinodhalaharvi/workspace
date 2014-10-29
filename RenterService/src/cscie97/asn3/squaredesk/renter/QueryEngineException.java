/**
 * 
 */
package cscie97.asn3.squaredesk.renter;

/**
 * @author vinodhalaharvi
 * This is just a place holder Exception class. 
 * For this assignment this class's behavior is no different than it's parent class's
 */
public class QueryEngineException extends Exception {

	/**
	 * 
	 */
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
