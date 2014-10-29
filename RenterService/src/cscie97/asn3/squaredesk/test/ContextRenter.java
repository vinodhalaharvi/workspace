/**
 * 
 */
package cscie97.asn3.squaredesk.test;

import java.io.FileNotFoundException;
import java.net.URISyntaxException;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.UUID;

import cscie97.asn3.squaredesk.renter.Facility;
import cscie97.asn3.squaredesk.renter.Feature;
import cscie97.asn3.squaredesk.renter.Image;
import cscie97.asn3.squaredesk.renter.Location;
import cscie97.asn3.squaredesk.renter.Rating;

/**
 * @author s2687
 *
 */
public class ContextRenter extends Context {

	private static ContextRenter context;
	private static Image image;
	
	public static Image getImage() {
		return image;
	}

	public static void setImage(Image image) {
		ContextRenter.image = image;
	}

	private static String name; 
	public static String getName() {
		return name;
	}

	public static void setName(String name) {
		ContextRenter.name = name;
	}

	/**
	 * generate Instance and return to the client
	 * @throws ParseException 
	 * @throws FileNotFoundException 
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


	public static ContextRenter getContext() {
		return context;
	}

	public static ArrayList<Rating> getRatings() {
		return ratings;
	}

	public static Facility getFacility() {
		return facility;
	}

	public static Location getLocation() {
		return location;
	}

	public static ArrayList<Feature> getFeatures() {
		return features;
	}

	public static String getAuthToken() {
		return authToken;
	}

	private static ArrayList<Rating> ratings;
	private static Facility facility;
	private static Location location;
	private static ArrayList<Feature> features;
	private static String authToken;
}
