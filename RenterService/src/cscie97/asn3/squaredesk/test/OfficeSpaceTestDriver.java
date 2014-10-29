/**
 * 
 */
package cscie97.asn3.squaredesk.test;

import java.net.URISyntaxException;

import cscie97.asn3.squaredesk.renter.AccessException;
import cscie97.asn3.squaredesk.renter.Feature;
import cscie97.asn3.squaredesk.renter.KnowledgeGraph;
import cscie97.asn3.squaredesk.renter.OfficeSpace;
import cscie97.asn3.squaredesk.renter.ProviderAlreadyExistException;
import cscie97.asn3.squaredesk.renter.Triple;

/**
 * @author s2687
 *
 */
public class OfficeSpaceTestDriver extends TestDriverBase {

	private OfficeSpace officeSpace;

	/**
	 * 
	 */
	public OfficeSpaceTestDriver() {
		// TODO Auto-generated constructor stub
	}

	@Override
	public void createTest() throws ProviderAlreadyExistException,
	AccessException, URISyntaxException {
		System.out.println("STARTING createTest");

		// TEST CASE 1
		// VERIFY CREATE AND READ OF THE "CRUD" OPERATIONS ON OfficeSpaceProvider and officeSpace
		//USING ProviderService
		//First create a Singleton ProviderService object
		//Add OfficeSpace to provider
		//get OfficeSpace object from provider object (and verify by printing to stdout) 
		//add rates to the OfficeSpace of this provider  (and verify by printing to stdout)
		//Mandatory fields are, location, capacity, facility, rate (at least one rate)
		System.out.println("Creating OfficeSpace");
		officeSpace = new OfficeSpace("Amazon OfficeSpace!", 
				ContextProvider.getLocation(), ContextProvider.getCapacity(), ContextProvider.getFacility(), ContextProvider.getRates().get(0));
		//add more rates if available
		System.out.println("Adding rates");
		officeSpace.addRate(ContextProvider.getAuthToken(), ContextProvider.getRates().get(1));
		//add this officeSpace to provider
		//Add features to office space. 
		System.out.println("Adding features");
		for(Feature feature : ContextProvider.getFeatures()){
			officeSpace.addFeature(ContextProvider.getAuthToken(), feature.getName());
		}
		System.out.println("ENDING createTest");

	}
	
	@Override
	public void updateTest() {
		//update this newly added officespace. 
		}

	@Override
	public void readTest() {
		System.out.println("STARTING readTest");
		//TEST THE KNOWLEDGE GRAPH QUERY FOR FEATURES	
		System.out.println("Reading features using QueryEngine.");
		String tempString = "?" + " has_feature " + "?";
		for (Triple foundTriple : KnowledgeGraph.executeQuery(new Triple(tempString))){
			System.out.println(foundTriple.getIdentifier());
		}
		System.out.println("ENDING readTest");

	}

	@Override
	public void deleteTest() {
		System.out.println("STARTING deleteTest");
		System.out.println("Deleting features .. ");
		for(Feature feature : ContextProvider.getFeatures()){
			officeSpace.removeFeature(ContextProvider.getAuthToken(), feature.getName());
		}
		System.out.println("Reading features using QueryEngine.");
		String tempString = "?" + " has_feature " + "?";
		for (Triple foundTriple : KnowledgeGraph.executeQuery(new Triple(tempString))){
			System.out.println(foundTriple.getIdentifier());
		}
		System.out.println("ENDING deleteTest");
	}
}
