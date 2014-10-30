/**
 * 
 */
package cscie97.asn3.squaredesk.test;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.net.URI;
import java.net.URISyntaxException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.Map;

import org.yaml.snakeyaml.Yaml;

import cscie97.asn3.squaredesk.provider.Capacity;
import cscie97.asn3.squaredesk.provider.Facility;
import cscie97.asn3.squaredesk.provider.Feature;
import cscie97.asn3.squaredesk.provider.Image;
import cscie97.asn3.squaredesk.provider.Location;
import cscie97.asn3.squaredesk.provider.Rate;
import cscie97.asn3.squaredesk.provider.Rating;


/**
 * The Class YamlImporterProvider.
 */
public class YamlImporterProvider {

	/** The yaml. */
	private static Yaml yaml; 
	
	/** The provider yaml. */
	private static Map<Object, Object> providerYaml; 
	
	/** The office spaces yaml. */
	private static Map<Object, Object> officeSpacesYaml; 
	
	/** The features yaml. */
	private static ArrayList<String> featuresYaml; 
	
	/** The location yaml. */
	private static Map<Object, Object> locationYaml; 
	
	/** The capacity yaml. */
	private static Map<Object, Object> capacityYaml; 
	
	/** The facility yaml. */
	private static Map<Object, Object> facilityYaml; 
	
	/** The rates yaml. */
	private static ArrayList<Map<Object, Object>> ratesYaml;
	
	/** The images yaml. */
	private static ArrayList<Map<Object, Object>> imagesYaml; 
	
	/** The ratings yaml. */
	private static ArrayList<Map<Object, Object>> ratingsYaml; 
	
	private static YamlImporterProvider yamlImporterProvider;   

	/**
	 * Inits the.
	 *
	 * @param filename
	 *            the filename
	 * @throws FileNotFoundException
	 *             the file not found exception
	 */
	@SuppressWarnings("unchecked")
	public static void init(String filename) 
			throws FileNotFoundException{
		FileInputStream input = new FileInputStream(filename); 
		yaml = new Yaml();
		providerYaml = (Map<Object, Object>)  yaml.load(input); 
		officeSpacesYaml = (Map<Object, Object>) providerYaml.get("officeSpaces");
		featuresYaml = (ArrayList<String>) officeSpacesYaml.get("features");
		locationYaml = (Map<Object, Object>) officeSpacesYaml.get("location");
		capacityYaml = (Map<Object, Object>) officeSpacesYaml.get("capacity"); 
		facilityYaml = (Map<Object, Object>) officeSpacesYaml.get("facility"); 
		ratesYaml = (ArrayList<Map<Object, Object>>) officeSpacesYaml.get("rates"); 
		imagesYaml = (ArrayList<Map<Object, Object>>) officeSpacesYaml.get("images"); 
		ratingsYaml = (ArrayList<Map<Object, Object>>) officeSpacesYaml.get("ratings");
	}

	
	public static YamlImporterProvider getInstance() {
		if (yamlImporterProvider == null){
			yamlImporterProvider = new YamlImporterProvider();
			return yamlImporterProvider;
		} else {
			return yamlImporterProvider;
		}
	}
	
	
	/**
	 * Import features.
	 *
	 * @return the array list
	 */
	public static ArrayList<Feature> importFeatures() {
		ArrayList<Feature> features = new ArrayList<Feature>();
		for(String featureYaml: featuresYaml){
			features.add(new Feature((String) featureYaml));
		}       
		return features; 
	}


	/**
	 * Import location.
	 *
	 * @return the location
	 */
	public static Location importLocation() {
		Location location = new Location( 
				(String) locationYaml.get("street1"),
				null,
				(String) locationYaml.get("city"), 
				(String) locationYaml.get("state"), 
				(String) locationYaml.get("zipCode"), 
				null,
				(String) locationYaml.get("countryCode"),
				(Double) locationYaml.get("lat"),
				(Double) locationYaml.get("lng")
				);
		return location;
	}


	/**
	 * Import capacity.
	 *
	 * @return the capacity
	 */
	public static Capacity importCapacity() {
		Capacity capacity = new Capacity(
				(Integer) capacityYaml.get("numOfPeople"), 
				(Double) capacityYaml.get("squareFootage"),
				(Integer) capacityYaml.get("numOfWorkSpaces")
				);
		return capacity; 
	}


	/**
	 * Import facility.
	 *
	 * @return the facility
	 */
	public static Facility importFacility() {
		Facility facility = new Facility(
				(String) facilityYaml.get("type"), 
				(String) facilityYaml.get("category")
				);
		return facility; 
	}


	/**
	 * Import rates.
	 *
	 * @return the array list
	 */
	public static ArrayList<Rate> importRates() {
		ArrayList<Rate> rates = new ArrayList<Rate>();
		for(Map<Object, Object> rateYaml: ratesYaml){ 
			@SuppressWarnings("unchecked")
			Map<Object, Object> rateYamlItem = ((Map<Object, Object>) rateYaml.get("rate")); 
			rates.add(new Rate(
					(String) rateYamlItem.get("period"), 
					(Double) rateYamlItem.get("cost")
					));     
		}       
		return rates; 
	}

	/**
	 * Import images.
	 *
	 * @return the array list
	 * @throws URISyntaxException the URI syntax exception
	 */
	public static ArrayList<Image> importImages() throws URISyntaxException {
		ArrayList<Image> images = new ArrayList<Image>();
		for(Map<Object, Object> imageYaml: imagesYaml){ 
			@SuppressWarnings("unchecked")
			Map<Object, Object> imageYamlItem = ((Map<Object, Object>) imageYaml.get("image")); 
				images.add(new Image((String)imageYamlItem.get("name"), 
						new URI((String)imageYamlItem.get("uri"))
				));  
		}  
		return images; 
	}

	/**
	 * Import ratings.
	 *
	 * @return the array list
	 * @throws ParseException
	 *             the parse exception
	 */
	public static ArrayList<Rating> importRatings() throws ParseException {
		ArrayList<Rating> ratings = new ArrayList<Rating>();
		for(Map<Object, Object> ratingYaml: ratingsYaml){ 
			@SuppressWarnings("unchecked")
			Map<Object, Object> ratingYamlItem = ((Map<Object, Object>) ratingYaml.get("rating")); 
			Date date = new SimpleDateFormat("yyyy-mm-dd").parse((String)ratingYamlItem.get("date"));
			ratings.add(new Rating(
					(Integer) ratingYamlItem.get("stars"), 
					(String) ratingYamlItem.get("comment"), 
					date, 
					(String) ratingYamlItem.get("authorsId")
					));	
		}
		return ratings; 
	}
}

