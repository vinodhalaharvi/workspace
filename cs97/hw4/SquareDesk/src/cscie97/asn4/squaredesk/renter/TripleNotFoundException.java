/**
 * 
 */
package cscie97.asn4.squaredesk.renter;

/**
 * The Class TripleNotFoundException.
 */
public class TripleNotFoundException extends Exception {

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = -2446226948529625952L;

	/**
	 * Instantiates a new triple not found exception.
	 */

	/**
	 * 
	 */
	public TripleNotFoundException() {
	}

	/**
	 * Instantiates a new triple not found exception.
	 *
	 * @param arg0 the arg0
	 */
	public TripleNotFoundException(String arg0) {
		super(arg0);
	}

	/**
	 * Instantiates a new triple not found exception.
	 *
	 * @param arg0 the arg0
	 */
	public TripleNotFoundException(Throwable arg0) {
		super(arg0);
	}

	/**
	 * Instantiates a new triple not found exception.
	 *
	 * @param arg0 the arg0
	 * @param arg1 the arg1
	 */
	public TripleNotFoundException(String arg0, Throwable arg1) {
		super(arg0, arg1);
	}

	/**
	 * Instantiates a new triple not found exception.
	 *
	 * @param arg0 the arg0
	 * @param arg1 the arg1
	 * @param arg2 the arg2
	 * @param arg3 the arg3
	 */
	public TripleNotFoundException(String arg0, Throwable arg1, boolean arg2,
			boolean arg3) {
		super();
	}

}
