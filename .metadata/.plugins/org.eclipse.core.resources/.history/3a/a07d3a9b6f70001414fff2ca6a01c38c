/*
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

import cscie97.asn3.squaredesk.provider.Facility;
import cscie97.asn3.squaredesk.provider.Feature;
import cscie97.asn3.squaredesk.provider.Image;
import cscie97.asn3.squaredesk.provider.Location;
import cscie97.asn3.squaredesk.provider.Rating;
import cscie97.asn3.squaredesk.renter.Account;


// TODO: Auto-generated Javadoc
/**
 * The Class YamlImporterRenter.
 */
public class YamlImporterRenter {

	/** The yaml. */
	private static Yaml yaml; 
	
	/** The features yaml. */
	private static ArrayList<String> featuresYaml; 
	
	/** The location yaml. */
	private static Map<Object, Object> locationYaml; 
	
	/** The ratings yaml. */
	private static ArrayList<Map<Object, Object>> ratingsYaml; 
	
	/** The yaml importer renter. */
	private static YamlImporterRenter yamlImporterRenter;

	/** The renter yaml. */
	private static Map<Object, Object> renterYaml;

	/** The account yaml. */
	private static Map<Object, Object> accountYaml;

	/** The search criteria yaml. */
	private static Map<Object, Object> searchCriteriaYaml;

	/** The facility yaml. */
	private static Map<Object, Object> facilityYaml;

	/**
	 * Gets the single instance of YamlImporterRenter.
	 *
	 * @return single instance of YamlImporterRenter
	 */
	public static YamlImporterRenter getInstance() {
		if (yamlImporterRenter == null){
			yamlImporterRenter = new YamlImporterRenter();
			return yamlImporterRenter;
		} else {
			return yamlImporterRenter;
		}
	}
	
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
		renterYaml = (Map<Object, Object>)  yaml.load(input); 
		
		accountYaml = (Map<Object, Object>) renterYaml.get("account");
		ratingsYaml = (ArrayList<Map<Object, Object>>) renterYaml.get("ratings");
		searchCriteriaYaml = (Map<Object, Object>) renterYaml.get("searchCriteria");
		featuresYaml = (ArrayList<String>) searchCriteriaYaml.get("features");
		locationYaml = (Map<Object, Object>) searchCriteriaYaml.get("location");
		facilityYaml = (Map<Object, Object>) searchCriteriaYaml.get("facility");
		accountYaml = (Map<Object, Object>) renterYaml.get("account");
	}
	
	
	/**
	 * Import name.
	 *
	 * @return the string
	 */
	public static String importName(){
		return (String) renterYaml.get("name"); 
	}
	
	/**
	 * Import gender.
	 *
	 * @return the string
	 */
	public static String importGender(){
		return (String) renterYaml.get("gender"); 
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
	 * Import account.
	 *
	 * @return the account
	 */
	public static Account importAccount(){
		Account account = new Account((String) accountYaml.get("payPalAccountNumber")); 
		return account; 
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
	 * Import images.
	 *
	 * @return the array list
	 * @throws URISyntaxException the URI syntax exception
	 */
	public static Image importImage() 
			throws URISyntaxException {
			Image image = new Image(
					"Amazing Renter!",
					new URI((String) renterYaml.get("picture"))
					);    
			return image;
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
}

