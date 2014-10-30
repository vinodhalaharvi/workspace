/**
 * 
 */
package cscie97.asn3.squaredesk.test;

import java.io.FileNotFoundException;
import java.net.URISyntaxException;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.UUID;

import cscie97.asn3.squaredesk.provider.Facility;
import cscie97.asn3.squaredesk.provider.Feature;
import cscie97.asn3.squaredesk.provider.Image;
import cscie97.asn3.squaredesk.provider.Location;
import cscie97.asn3.squaredesk.provider.Rating;

/**
 * The Class ContextRenter.
 */
public class ContextRenter extends Context {

	/** The context. */
	private static ContextRenter context;
	
	/** The image. */
	private static Image image;
	
	/**
	 * Gets the image.
	 *
	 * @return the image
	 */
	public static Image getImage() {
		return image;
	}

	/**
	 * Sets the image.
	 *
	 * @param image
	 *            the new image
	 */
	public static void setImage(Image image) {
		ContextRenter.image = image;
	}

	/** The name. */
	private static String name; 
	
	/**
	 * Gets the name.
	 *
	 * @return the name
	 */
	public static String getName() {
		return name;
	}

	/**
	 * Sets the name.
	 *
	 * @param name
	 *            the new name
	 */
	public static void setName(String name) {
		ContextRenter.name = name;
	}

	/**
	 * Gets the single instance of ContextRenter.
	 *
	 * @return single instance of ContextRenter
	 * @throws FileNotFoundException
	 *             the file not found exception
	 * @throws ParseException
	 *             the parse exception
	 */
	public static ContextRenter getInstance() 
			throws FileNotFoundException, ParseException {
		if (context == null){ 
			context = new ContextRenter();  
			return context; 
		} else {
			return context; 
		}
	}

	/**
	 * @throws ParseException 
	 * @throws FileNotFoundException 
	 * 
	 */
	public ContextRenter() 
			throws FileNotFoundException, ParseException {
	}


	public static void importFile(String inputfilepath) 
			throws FileNotFoundException, ParseException{
		@SuppressWarnings("unused")
		YamlImporterRenter yaml = YamlImporterRenter.getInstance(); 
		YamlImporterRenter.init(inputfilepath);
		name = YamlImporterRenter.importName();
		try {
			image = YamlImporterRenter.importImage();
		} catch (URISyntaxException e) {
			e.printStackTrace();
		} 
		ratings = YamlImporterRenter.importRatings();
		facility  = YamlImporterRenter.importFacility();
		location = YamlImporterRenter.importLocation();
		features = YamlImporterRenter.importFeatures();
		authToken = UUID.randomUUID().toString();
	}


	/**
	 * Gets the context.
	 *
	 * @return the context
	 */
	public static ContextRenter getContext() {
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
	 * Gets the facility.
	 *
	 * @return the facility
	 */
	public static Facility getFacility() {
		return facility;
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
	
	/** The facility. */
	private static Facility facility;
	
	/** The location. */
	private static Location location;
	
	/** The features. */
	private static ArrayList<Feature> features;
	
	/** The auth token. */
	private static String authToken;
}
