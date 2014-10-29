/**
 * 
 */
package cscie97.asn3.squaredesk.renter;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

/**
 * The Class Provider.
 *
 * @author Vinod Halaharvi
 */
public class Provider extends Profile {

	/** The contact info. */
	private ContactInfo contactInfo; 

	/** The provider id. */
	private String providerId; 

	/** The name. */
	private String name; 

	/** The picture. */
	private Image picture; 

	/** The account. */
	private Account account; 	

	/** The office spaces. */
	private Map<String, OfficeSpace> officeSpaces; 

	/** The ratings. */
	private Map<String, Rating> ratings; 

	private KnowledgeGraph kg; 
	/**
	 * Instantiates a new provider.
	 *
	 * @param name the name
	 * @param contactInfo the contact info
	 * @param picture the picture
	 */
	public Provider(String name, ContactInfo contactInfo, Image picture) {
		kg = KnowledgeGraph.getInstance(); 
		officeSpaces = new HashMap<String, OfficeSpace>(); 
		ratings = new HashMap<String, Rating>(); 
		this.name = name; 
		this.contactInfo = contactInfo; 
		this.picture = picture; 
	}

	/**
	 * Gets the uuid.
	 *
	 * @return the uuid
	 */
	private String getUUID() {
		String uuidStr = UUID.randomUUID().toString(); 
		return uuidStr; 	
	}


	/**
	 * Gets the contact info.
	 *
	 * @return the contact info
	 */
	public ContactInfo getContactInfo() {
		return contactInfo;
	}

	/**
	 * Sets the contact info.
	 *
	 * @param contactInfo the new contact info
	 */
	public void setContactInfo(ContactInfo contactInfo) {
		this.contactInfo = contactInfo;
	}

	/**
	 * Gets the provider id.
	 *
	 * @return the providerId
	 */
	public String getProviderId() {
		return providerId;
	}

	/**
	 * Sets the provider id.
	 *
	 * @param providerId the providerId to set
	 */
	public void setProviderId(String providerId) {
		this.providerId = providerId;
	}

	/**
	 * Gets the name.
	 *
	 * @return the name
	 */
	public String getName() {
		return name;
	}

	/**
	 * Sets the name.
	 *
	 * @param name the name to set
	 */
	public void setName(String name) {
		this.name = name;
	}

	/**
	 * Gets the image.
	 *
	 * @return the picture
	 */
	public Image getImage() {
		return picture;
	}

	/**
	 * Sets the image.
	 *
	 * @param picture the picture to set
	 */
	public void setImage(Image picture) {
		this.picture = picture;
	}

	/**
	 * Gets the account.
	 *
	 * @return the account
	 */
	public Account getAccount() {
		return account;
	}

	/**
	 * Sets the account.
	 *
	 * @param account the account to set
	 */
	public void setAccount(Account account) {
		this.account = account;
	}


	/**
	 * Adds the rating to list.
	 *
	 * @param rating the rating
	 * @return the rating
	 */
	public Rating addRatingToList(Rating rating) {
		String ratingId = getUUID(); 
		rating.setRatingId(ratingId); 
		ratings.put(ratingId, rating);
		return rating; 
	}

	/**
	 * Gets the ratingfrom list.
	 *
	 * @param ratingId the rating id
	 * @return the ratingfrom list
	 * @throws RatingNotFoundException the rating not found exception
	 */
	public Rating getRatingfromList(String ratingId) 
			throws RatingNotFoundException {
		if (!ratings.containsKey(ratingId)){ 
			throw new RatingNotFoundException("Rating not found!"); 
		} else { 
			return ratings.get(ratingId); 
		}		
	}

	/**
	 * Removes the ratingfrom list.
	 *
	 * @param ratingId the rating id
	 * @throws RatingNotFoundException the rating not found exception
	 */
	public void removeRatingfromList(String ratingId) 
			throws RatingNotFoundException {
		if (!ratings.containsKey(ratingId)){ 
			throw new RatingNotFoundException("Rating not found!"); 
		} else { 
			ratings.remove(ratingId); 
		}		
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
	 * Gets the ratings.
	 *
	 * @return the ratings
	 */
	public Collection<Rating> getRatings() {
		return ratings.values();
	}

	public void makeOfficeSpaceSearchable(OfficeSpace officeSpace) {
		officeSpace.setSearchable(true); 
	}	
	
	public OfficeSpace addOfficeSpaceToKnowledgeGraph(OfficeSpace officeSpace) {
		if (officeSpace.getFacility().getCategory() == ""){
			kg.addTriple(new Triple(officeSpace.getOffId() + " has_facility_type_category " +
					officeSpace.getFacility().getType()));
		} else {
			kg.addTriple(new Triple(officeSpace.getOffId() + " has_facility_type_category " +
					officeSpace.getFacility().getType() + "_" + officeSpace.getFacility().getCategory()));
		}
		kg.addTriple(new Triple(
				officeSpace.getOffId() + " has_lat_long " + (int)Math.floor(officeSpace.getLocation().getLat()) + "_"
						+ (int)Math.floor(officeSpace.getLocation().getlng())));
		for(Feature feature : officeSpace.getFeatures()){
			kg.addTriple(new Triple(officeSpace.getOffId() + " has_feature " + feature.getName()));
		}

		for(Rating rating : officeSpace.getRatings()){
			kg.addTriple(new Triple(officeSpace.getOffId() + " has_rating " + rating));
		}
		officeSpace.setSearchable(true); 
		return officeSpace;
	}


	public OfficeSpace removeOfficeSpaceToKnowledgeGraph(OfficeSpace officeSpace) {
		if (!officeSpace.isSearchable())
			return officeSpace; 
		if (officeSpace.getFacility().getCategory() == ""){
			kg.removeTriple(new Triple(officeSpace.getOffId() + " has_facility_type_category " +
					officeSpace.getFacility().getType()));
		} else {
			kg.removeTriple(new Triple(officeSpace.getOffId() + " has_facility_type_category " +
					officeSpace.getFacility().getType() + "_" + officeSpace.getFacility().getCategory()));
		}
		kg.removeTriple(new Triple(
				officeSpace.getOffId() + " has_lat_long " + (int)Math.floor(officeSpace.getLocation().getLat()) + "_"
						+ (int)Math.floor(officeSpace.getLocation().getlng())));
		for(Feature feature : officeSpace.getFeatures()){
			kg.removeTriple(new Triple(officeSpace.getOffId() + " has_feature " + feature.getName()));
		}

		for(Rating rating : officeSpace.getRatings()){
			kg.removeTriple(new Triple(officeSpace.getOffId() + " has_rating " + rating));
		}
		return officeSpace;
	}

}
