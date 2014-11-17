/**
 * 
 */
package cscie97.asn3.squaredesk.test;

import java.io.FileNotFoundException;
import java.text.ParseException;

/**
 * The Class Context.
 */
public class Context {

	/** The context. */
	private static Context context; 


	/**
	 * @throws ParseException 
	 * @throws FileNotFoundException 
	 * 
	 */
	public Context() 
			throws FileNotFoundException, ParseException {
	}


	/**
	 * @param inputfilepath
	 * @throws FileNotFoundException
	 * @throws ParseException
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