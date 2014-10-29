/**
 * 
 */
package cscie97.asn3.squaredesk.test;

import java.io.FileNotFoundException;
import java.text.ParseException;

/**
 * @author s2687
 *
 */
public class Context {

	private static Context context; 


	/**
	 * @throws ParseException 
	 * @throws FileNotFoundException 
	 * 
	 */
	public Context() 
			throws FileNotFoundException, ParseException {
	}


	public static void importFile(String inputfilepath) 
			throws FileNotFoundException, ParseException{
	}


	public static Context getContext() {
		return context;
	}
}
