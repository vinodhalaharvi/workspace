/**
 * 
 */
package cscie97.asn3.squaredesk.renter;

/**
 * @author vinodhalaharvi
 * This is just a place holder Exception class. 
 * For this assignment this class's behavior is no different than it's parent class's
 */
public class ImportExecption extends Exception {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1140072623702558238L;

	/**
	 * 
	 */
	public ImportExecption() {
	}

	/**
	 * @param arg0
	 */
	public ImportExecption(String arg0) {
		super(arg0);
	}

	/**
	 * @param arg0
	 */
	public ImportExecption(Throwable arg0) {
		super(arg0);
	}

	/**
	 * @param arg0
	 * @param arg1
	 */
	public ImportExecption(String arg0, Throwable arg1) {
		super(arg0, arg1);
	}

}
