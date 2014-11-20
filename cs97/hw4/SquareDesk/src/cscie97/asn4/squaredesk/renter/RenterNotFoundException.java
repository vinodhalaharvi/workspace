/**
 * 
 */
package cscie97.asn4.squaredesk.renter;

/**
 * The Class RenterNotFoundException.
 */
public class RenterNotFoundException extends Exception {

	/** The Constant serialVersionUID. */

	/**
	 * 
	 */
	private static final long serialVersionUID = 1150723028383550802L;

	/**
	 * Instantiates a new renter not found exception.
	 */
	public RenterNotFoundException() {
	}

	/**
	 * Instantiates a new renter not found exception.
	 *
	 * @param arg0 the arg0
	 */
	public RenterNotFoundException(String arg0) {
		super(arg0);
	}

	/**
	 * Instantiates a new renter not found exception.
	 *
	 * @param arg0 the arg0
	 */
	public RenterNotFoundException(Throwable arg0) {
		super(arg0);
	}

	/**
	 * Instantiates a new renter not found exception.
	 *
	 * @param arg0 the arg0
	 * @param arg1 the arg1
	 */
	public RenterNotFoundException(String arg0, Throwable arg1) {
		super(arg0, arg1);
	}

}
