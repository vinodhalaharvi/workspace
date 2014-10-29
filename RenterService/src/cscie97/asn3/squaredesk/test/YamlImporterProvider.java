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

import cscie97.asn3.squaredesk.renter.Capacity;
import cscie97.asn3.squaredesk.renter.Facility;
import cscie97.asn3.squaredesk.renter.Feature;
import cscie97.asn3.squaredesk.renter.Image;
import cscie97.asn3.squaredesk.renter.Location;
import cscie97.asn3.squaredesk.renter.Rate;
import cscie97.asn3.squaredesk.renter.Rating;


/**
 * The Class YamlImporter.
 *
 * @author Vinod Halaharvi
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

	
	public static YamlImporterProvider getInstance() {
		if (yamlImporterProvider == null){
			yamlImporterProvider = new YamlImporterProvider();
			return yamlImporterProvider;
		} else {
			return yamlImporterProvider;
		}
	}
	
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
	 * Prints the features.
	 *
	 * @param features the features
	 */
	public static void printFeatures(ArrayList<Feature> features) {
		System.out.println("FEATURES!!");
		for(Feature feature : features){
			System.out.println(feature.getName());
			System.out.println();
		}
	}


	/**
	 * Import location.
	 *
	 * @return the location
	 */
	
	//String street1, String street2, String city, String state,
	//String zipCode, String address, String countryCode, Double lat,
	//Double lng
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
	 * Prints the location.
	 *
	 * @param location the location
	 */
	public static void printLocation(Location location) {
		System.out.println("LOCATION!!");
		System.out.println(location.getStreet1());
		System.out.println(location.getCity());
		System.out.println(location.getState());
		System.out.println(location.getZipCode());
		System.out.println(location.getCountryCode());
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
	 * Prints the capacity.
	 *
	 * @param capacity the capacity
	 */
	public static void printCapacity(Capacity capacity) {
		System.out.println("CAPACITY!!");
		System.out.println(capacity.getNumOfPeople());
		System.out.println(capacity.getNumOfWorkSpaces());
		System.out.println(capacity.getSquareFootage());
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
	 * Prints the facility.
	 *
	 * @param facility the facility
	 */
	public static void printFacility(Facility facility) {
		System.out.println("FACILITY!!");
		System.out.println("Type: " + facility.getType());
		System.out.println("Category: " + facility.getCategory());
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
	 * Prints the rates.
	 *
	 * @param rates the rates
	 */
	public static void printRates(ArrayList<Rate> rates) {
		System.out.println("RATES!!");
		for(Rate rate : rates){
			System.out.println(rate.getPeriod());
			System.out.println(rate.getCost());
			System.out.println();
		}
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
	 * Prints the images.
	 *
	 * @param images the images
	 */
	public static void printImages(ArrayList<Image> images) {
		System.out.println("IMAGES!!");
		for(Image image : images){
			System.out.println(image.getName());
			System.out.println(image.getDescription());
			System.out.println(image.getURI());     
			System.out.println();
		}
	}



	/**
	 * Import ratings.
	 *
	 * @return the array list
	 * @throws ParseException the parse exception
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


	/**
	 * Prints the ratings.
	 *
	 * @param ratings the ratings
	 */
	public static void printRatings(ArrayList<Rating> ratings) {
		System.out.println("RATINGS!!");
		for(Rating rating : ratings){
			System.out.println(rating.getStars());
			System.out.println(rating.getComment());
			System.out.println(rating.getDate());
			System.out.println(rating.getAuthorsId());		
			System.out.println();
		}
	}
}

