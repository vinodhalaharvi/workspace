/**
 * 
 */
package cscie97.asn3.squaredesk.test;

import java.net.URISyntaxException;

import cscie97.asn3.squaredesk.authentication.AccessException;
import cscie97.asn3.squaredesk.provider.Feature;
import cscie97.asn3.squaredesk.provider.OfficeSpace;
import cscie97.asn3.squaredesk.provider.ProviderAlreadyExistException;
import cscie97.asn3.squaredesk.renter.KnowledgeGraph;
import cscie97.asn3.squaredesk.renter.Triple;

// TODO: Auto-generated Javadoc
/**
 * The Class OfficeSpaceTestDriver.
 */
public class OfficeSpaceTestDriver extends TestDriverBase {

	/** The office space. */
	private OfficeSpace officeSpace;

	/**
	 * Instantiates a new office space test driver.
	 */
	public OfficeSpaceTestDriver() {
	}

	/* (non-Javadoc)
	 * @see cscie97.asn3.squaredesk.test.TestDriverBase#createTest()
	 */
	@Override
	public void createTest() throws ProviderAlreadyExistException,
	AccessException, URISyntaxException {
		beginTest("createTest");
		System.out.println("Creating OfficeSpace");
		officeSpace = new OfficeSpace("Amazon OfficeSpace!", 
				ContextProvider.getLocation(), ContextProvider.getCapacity(), ContextProvider.getFacility(), ContextProvider.getRates().get(0));
		System.out.println("Adding rates");
		officeSpace.addRate(ContextProvider.getAuthToken(), ContextProvider.getRates().get(1));
		System.out.println("Adding features");
		for(Feature feature : ContextProvider.getFeatures()){
			officeSpace.addFeature(ContextProvider.getAuthToken(), feature.getName());
		}
		endTest("createTest");
	}

	/* (non-Javadoc)
	 * @see cscie97.asn3.squaredesk.test.TestDriverBase#updateTest()
	 */
	@Override
	public void updateTest() {
		//update this newly added officespace. 
	}

	/* (non-Javadoc)
	 * @see cscie97.asn3.squaredesk.test.TestDriverBase#readTest()
	 */
	@Override
	public void readTest() {
		beginTest("readTest");
		System.out.println("Reading features using QueryEngine.");
		String tempString = "?" + " has_feature " + "?";
		for (Triple foundTriple : KnowledgeGraph.executeQuery(new Triple(tempString))){
			System.out.println(foundTriple.getIdentifier());
		}
		endTest("readTest");
	}

	/* (non-Javadoc)
	 * @see cscie97.asn3.squaredesk.test.TestDriverBase#deleteTest()
	 */
	@Override
	public void deleteTest() {
		beginTest("deleteTest");
		System.out.println("Deleting features .. ");
		for(Feature feature : ContextProvider.getFeatures()){
			officeSpace.removeFeature(ContextProvider.getAuthToken(), feature.getName());
		}
		System.out.println("Reading features using QueryEngine.");
		String tempString = "?" + " has_feature " + "?";
		for (Triple foundTriple : KnowledgeGraph.executeQuery(new Triple(tempString))){
			System.out.println(foundTriple.getIdentifier());
		}
		endTest("deleteTest");
	}
}
