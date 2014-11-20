/**
 * 
 */
package cscie97.asn4.squaredesk.renter;

/**
 * The Class RenterAlreadyExistException.
 */
public class RenterAlreadyExistException extends Exception {

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = 5827507850203009048L;

	/**
	 * Instantiates a new renter already exist exception.
	 */
	public RenterAlreadyExistException() {
	}

	/**
	 * Instantiates a new renter already exist exception.
	 *
	 * @param arg0 the arg0
	 */
	public RenterAlreadyExistException(String arg0) {
		super(arg0);
	}

	/**
	 * Instantiates a new renter already exist exception.
	 *
	 * @param arg0 the arg0
	 */
	public RenterAlreadyExistException(Throwable arg0) {
		super(arg0);
	}

	/**
	 * Instantiates a new renter already exist exception.
	 *
	 * @param arg0 the arg0
	 * @param arg1 the arg1
	 */
	public RenterAlreadyExistException(String arg0, Throwable arg1) {
		super(arg0, arg1);
	}

	/**
	 * Instantiates a new renter already exist exception.
	 *
	 * @param arg0 the arg0
	 * @param arg1 the arg1
	 * @param arg2 the arg2
	 * @param arg3 the arg3
	 */
	public RenterAlreadyExistException(String arg0, Throwable arg1,
			boolean arg2, boolean arg3) {
		super();
	}

}
