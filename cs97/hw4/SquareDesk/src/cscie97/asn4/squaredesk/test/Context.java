/**
 * 
 */
package cscie97.asn4.squaredesk.test;

import java.io.FileNotFoundException;
import java.text.ParseException;

/**
 * The Class Context.
 */
public class Context {

	/** The context. */
	private static Context context; 


	/**
	 * Instantiates a new context.
	 *
	 * @throws FileNotFoundException the file not found exception
	 * @throws ParseException the parse exception
	 */
	public Context() 
			throws FileNotFoundException, ParseException {
	}


	/**
	 * Import file.
	 *
	 * @param inputfilepath the inputfilepath
	 * @throws FileNotFoundException the file not found exception
	 * @throws ParseException the parse exception
	 */
	public static void importFile(String inputfilepath) 
			throws FileNotFoundException, ParseException{
	}


	/**
	 * Gets the context.
	 *
	 * @return the context
	 */
	public static Context getContext() {
		return context;
	}
}
