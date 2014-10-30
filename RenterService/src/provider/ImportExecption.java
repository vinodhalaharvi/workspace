/**
 * 
 */
package provider;

/**
 * The Class ImportExecption.
 */
public class ImportExecption extends Exception {

	/** The Constant serialVersionUID. */
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
