/**
 * 
 */
package cscie97.asn3.squaredesk.test;

import java.io.FileNotFoundException;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.UUID;

import cscie97.asn3.squaredesk.provider.Capacity;
import cscie97.asn3.squaredesk.provider.Facility;
import cscie97.asn3.squaredesk.provider.Feature;
import cscie97.asn3.squaredesk.provider.Location;
import cscie97.asn3.squaredesk.provider.Rate;
import cscie97.asn3.squaredesk.provider.Rating;

/**
 * The Class ContextProvider.
 */
public final class ContextProvider extends Context {

	/** The context. */
	private static ContextProvider context; 

	/**
	 * @throws ParseException 
	 * @throws FileNotFoundException 
	 * 
	 */
	public ContextProvider() 
			throws FileNotFoundException, ParseException {
	}


	/**
	 * Import file.
	 *
	 * @param inputfilepath
	 *            the inputfilepath
	 * @throws FileNotFoundException
	 *             the file not found exception
	 * @throws ParseException
	 *             the parse exception
	 */
	public static void importFile(String inputfilepath) 
			throws FileNotFoundException, ParseException{
		@SuppressWarnings("unused")
		YamlImporterProvider yaml = YamlImporterProvider.getInstance(); 
		YamlImporterProvider.init(inputfilepath);
		ratings = YamlImporterProvider.importRatings();
		rates = YamlImporterProvider.importRates();
		facility  = YamlImporterProvider.importFacility();
		capacity = YamlImporterProvider.importCapacity();
		location = YamlImporterProvider.importLocation();
		features = YamlImporterProvider.importFeatures();
		authToken = UUID.randomUUID().toString();
	}


	/**
	 * Gets the context.
	 *
	 * @return the context
	 */
	public static ContextProvider getContext() {
		return context;
	}

	/**
	 * Gets the ratings.
	 *
	 * @return the ratings
	 */
	public static ArrayList<Rating> getRatings() {
		return ratings;
	}

	/**
	 * Gets the rates.
	 *
	 * @return the rates
	 */
	public static ArrayList<Rate> getRates() {
		return rates;
	}

	/**
	 * Gets the facility.
	 *
	 * @return the facility
	 */
	public static Facility getFacility() {
		return facility;
	}

	/**
	 * Gets the capacity.
	 *
	 * @return the capacity
	 */
	public static Capacity getCapacity() {
		return capacity;
	}

	/**
	 * Gets the location.
	 *
	 * @return the location
	 */
	public static Location getLocation() {
		return location;
	}

	/**
	 * Gets the features.
	 *
	 * @return the features
	 */
	public static ArrayList<Feature> getFeatures() {
		return features;
	}

	/**
	 * Gets the auth token.
	 *
	 * @return the auth token
	 */
	public static String getAuthToken() {
		return authToken;
	}

	/** The ratings. */
	private static ArrayList<Rating> ratings;
	
	/** The rates. */
	private static ArrayList<Rate> rates;
	
	/** The facility. */
	private static Facility facility;
	
	/** The capacity. */
	private static Capacity capacity;
	
	/** The location. */
	private static Location location;
	
	/** The features. */
	private static ArrayList<Feature> features;
	
	/** The auth token. */
	private static String authToken;
}