/**
 * 
 */
package cscie97.asn3.squaredesk.renter;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

/**
 * The Class Renter.
 *
 * @author Vinod Halaharvi
 */
public class Renter extends Profile{

	/** The contact info. */
	private ContactInfo contactInfo; 
	
	/** The renter id. */
	private String renterId; 
	
	/** The name. */
	private String name; 
	
	/** The picture. */
	private Image picture; 
	
	/** The account. */
	private Account account; 	

	/** The ratings. */
	private Map<String, Rating> ratings; 
	
	public String getGender() {
		return gender;
	}

	public void setGender(String gender) {
		this.gender = gender;
	}

	
	@Override
	public boolean equals(Object obj) {
		Renter t = (Renter) obj; 
		return (obj != null) &&
				(obj instanceof Renter) &&
				t.renterId.equals(renterId);
	}
	
	@Override
	public int hashCode() {
		return renterId.hashCode();  
	}
	
	public Criteria getCriteria() {
		return criteria;
	}

	public void setCriteria(Criteria criteria) {
		this.criteria = criteria;
	}

	private String gender; 
	
	
	private Criteria criteria; 
	

	/**
	 * Instantiates a new renter.
	 *
	 * @param name the name
	 * @param contactInfo the contact info
	 * @param picture the picture
	 */
	public Renter(String name, ContactInfo contactInfo, Image picture) {
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
	 * Gets the renter id.
	 *
	 * @return the renterId
	 */
	public String getRenterId() {
		return renterId;
	}

	/**
	 * Sets the renter id.
	 *
	 * @param renterId the renterId to set
	 */
	public void setRenterId(String renterId) {
		this.renterId = renterId;
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
	 * Gets the ratings.
	 *
	 * @return the ratings
	 */
	public Collection<Rating> getRatings() {
		return ratings.values();
	}

}

