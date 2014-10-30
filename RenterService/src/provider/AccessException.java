/*
 * 
 */
package provider;

/**
 * The Class AccessException.
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
