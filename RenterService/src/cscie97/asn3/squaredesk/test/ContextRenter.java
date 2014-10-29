/**
 * 
 */
package cscie97.asn3.squaredesk.test;

import java.io.FileNotFoundException;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.UUID;

import cscie97.asn3.squaredesk.renter.Facility;
import cscie97.asn3.squaredesk.renter.Feature;
import cscie97.asn3.squaredesk.renter.KnowledgeGraph;
import cscie97.asn3.squaredesk.renter.Location;
import cscie97.asn3.squaredesk.renter.QueryEngine;
import cscie97.asn3.squaredesk.renter.Rate;
import cscie97.asn3.squaredesk.renter.Rating;

/**
 * @author s2687
 *
 */
public class ContextRenter extends Context {

	private static ContextRenter context; 
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
		//Zeroth argument is the YAML file to create objects
		YamlImporterRenter.init(inputfilepath);
		//IMPORT YAML DATA FROM INPUT FILE
		//AND CREATE JAVA OBJECTS OUT OF THEM
		ratings = YamlImporterRenter.importRatings();
		facility  = YamlImporterRenter.importFacility();
		location = YamlImporterRenter.importLocation();
		features = YamlImporterRenter.importFeatures();
		authToken = UUID.randomUUID().toString();
		qe = new QueryEngine();
		kg = KnowledgeGraph.getInstance(); 
	}


	public static ContextRenter getContext() {
		return context;
	}

	public static ArrayList<Rating> getRatings() {
		return ratings;
	}

	public static ArrayList<Rate> getRates() {
		return rates;
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

	public static KnowledgeGraph getKg() {
		return kg;
	}

	public static QueryEngine getQe() {
		return qe;
	}


	private static ArrayList<Rating> ratings;
	private static ArrayList<Rate> rates;
	private static Facility facility;
	private static Location location;
	private static ArrayList<Feature> features;
	private static String authToken;
	private static KnowledgeGraph kg; 
	private static QueryEngine qe; 
}
