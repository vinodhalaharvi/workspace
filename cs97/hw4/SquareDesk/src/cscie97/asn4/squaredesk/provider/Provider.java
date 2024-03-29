/**
 * 
 */
package cscie97.asn4.squaredesk.provider;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

import cscie97.asn4.squaredesk.renter.KnowledgeGraph;
import cscie97.asn4.squaredesk.renter.Profile;
import cscie97.asn4.squaredesk.renter.Triple;

/**
 * The Class Provider.
 */
public class Provider extends Profile {
	
	/** The office spaces. */
	private Map<String, OfficeSpace> officeSpaces; 

	/** The provider id. */
	private String providerId; 
	
	/**
	 * Instantiates a new provider.
	 *
	 * @param name the name
	 * @param contactInfo the contact info
	 * @param picture the picture
	 */
	public Provider(String name, ContactInfo contactInfo, Image picture ) {
		super(contactInfo, name, picture); 
		officeSpaces = new HashMap<String, OfficeSpace>(); 
	}


	/**
	 * Gets the provider id.
	 *
	 * @return the provider id
	 */
	public String getProviderId() {
		return providerId;
	}

	/**
	 * Sets the provider id.
	 *
	 * @param providerId
	 *            the new provider id
	 */
	public void setProviderId(String providerId) {
		this.providerId = providerId;
	}

	/**
	 * Adds the office space to list.
	 *
	 * @param officeSpace the office space
	 * @return the office space
	 */
	public OfficeSpace addOfficeSpaceToList(OfficeSpace officeSpace) {	
		String uuidName = getUUID(); 
		officeSpace.setOffId(uuidName); 
		officeSpaces.put(uuidName, officeSpace); 
		return officeSpace;
	}


	/**
	 * Gets the office spacefrom list.
	 *
	 * @param officeSpaceId the office space id
	 * @return the office spacefrom list
	 * @throws OfficeSpaceNotFoundException the office space not found exception
	 */
	public OfficeSpace getOfficeSpacefromList(String officeSpaceId) 
			throws OfficeSpaceNotFoundException {
		if (!officeSpaces.containsKey(officeSpaceId)){ 
			throw new OfficeSpaceNotFoundException("OfficeSpace you are looking is Not Found!"); 
		} else { 
			return officeSpaces.get(officeSpaceId); 
		}		
	}

	/**
	 * Removes the office space from list.
	 *
	 * @param officeSpaceId the office space id
	 * @throws OfficeSpaceNotFoundException the office space not found exception
	 */
	public void removeOfficeSpaceFromList(String officeSpaceId)
			throws OfficeSpaceNotFoundException{
		if (!officeSpaces.containsKey(officeSpaceId)){ 
			throw new OfficeSpaceNotFoundException("OfficeSpace you are looking is Not Found!"); 
		} else { 
			officeSpaces.remove(officeSpaceId); 
		}	
	}

	/**
	 * Gets the office spaces.
	 *
	 * @return the office spaces
	 */
	public Collection<OfficeSpace> getOfficeSpaces() {
		return officeSpaces.values(); 
	}


	/**
	 * Make office space searchable.
	 *
	 * @param officeSpace the office space
	 */
	public void makeOfficeSpaceSearchable(OfficeSpace officeSpace) {
		officeSpace.setSearchable(true); 
	}	
	
	/**
	 * Adds the office space to knowledge graph.
	 *
	 * @param officeSpace the office space
	 * @return the office space
	 */
	public OfficeSpace addOfficeSpaceToKnowledgeGraph(OfficeSpace officeSpace) {
		if (officeSpace.getFacility().getCategory() == ""){
			KnowledgeGraph.addTriple(new Triple(officeSpace.getOffId() + " has_facility_type_category " +
					officeSpace.getFacility().getType()));
		} else {
			KnowledgeGraph.addTriple(new Triple(officeSpace.getOffId() + " has_facility_type_category " +
					officeSpace.getFacility().getType() + "_" + officeSpace.getFacility().getCategory().replace(' ', '_')));
		}
		KnowledgeGraph.addTriple(new Triple(
				officeSpace.getOffId() + " has_lat_long " + (int)Math.floor(officeSpace.getLocation().getLat()) + "_"
						+ (int)Math.floor(officeSpace.getLocation().getlng())));
		for(Feature feature : officeSpace.getFeatures()){
			KnowledgeGraph.addTriple(new Triple(officeSpace.getOffId() + " has_feature " + feature.getName()));
		}

		for(Rating rating : officeSpace.getRatings()){
			KnowledgeGraph.addTriple(new Triple(officeSpace.getOffId() + " has_rating " + rating.getStars()));
		}
		officeSpace.setSearchable(true); 
		return officeSpace;
	}


	/**
	 * Removes the office space to knowledge graph.
	 *
	 * @param officeSpace the office space
	 * @return the office space
	 */
	public OfficeSpace removeOfficeSpaceToKnowledgeGraph(OfficeSpace officeSpace) {
		if (!officeSpace.isSearchable())
			return officeSpace; 
		if (officeSpace.getFacility().getCategory() == ""){
			KnowledgeGraph.removeTriple(new Triple(officeSpace.getOffId() + " has_facility_type_category " +
					officeSpace.getFacility().getType()));
		} else {
			KnowledgeGraph.removeTriple(new Triple(officeSpace.getOffId() + " has_facility_type_category " +
					officeSpace.getFacility().getType() + "_" + officeSpace.getFacility().getCategory()));
		}
		KnowledgeGraph.removeTriple(new Triple(
				officeSpace.getOffId() + " has_lat_long " + (int)Math.floor(officeSpace.getLocation().getLat()) + "_"
						+ (int)Math.floor(officeSpace.getLocation().getlng())));
		for(Feature feature : officeSpace.getFeatures()){
			KnowledgeGraph.removeTriple(new Triple(officeSpace.getOffId() + " has_feature " + feature.getName()));
		}

		for(Rating rating : officeSpace.getRatings()){
			KnowledgeGraph.removeTriple(new Triple(officeSpace.getOffId() + " has_rating " + rating));
		}
		return officeSpace;
	}

}
