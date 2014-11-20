/**
 * 
 */
package cscie97.asn4.squaredesk.renter;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

import cscie97.asn4.squaredesk.provider.ContactInfo;
import cscie97.asn4.squaredesk.provider.Image;
import cscie97.asn4.squaredesk.provider.Rating;
import cscie97.asn4.squaredesk.provider.RatingNotFoundException;

/**
 * The Class Profile.
 */
public abstract class Profile {

	
	/**
	 * Instantiates a new profile.
	 */
	public Profile() {
	}

	/**
	 * Instantiates a new profile.
	 *
	 * @param contactInfo
	 *            the contact info
	 * @param name
	 *            the name
	 * @param picture
	 *            the picture
	 */
	public Profile(ContactInfo contactInfo, String name, Image picture) {
		super();
		this.contactInfo = contactInfo;
		this.name = name;
		this.picture = picture;
		ratings = new HashMap<String, Rating>(); 
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
	 * @param name
	 *            the new name
	 */
	public void setName(String name) {
		this.name = name;
	}

	/**
	 * Gets the image.
	 *
	 * @return the image
	 */
	public Image getImage() {
		return picture;
	}

	/**
	 * Sets the image.
	 *
	 * @param picture
	 *            the new image
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
	 * @param account
	 *            the new account
	 */
	public void setAccount(Account account) {
		this.account = account;
	}


	/**
	 * Sets the contact info.
	 *
	 * @param contactInfo
	 *            the new contact info
	 */
	public void setContactInfo(ContactInfo contactInfo) {
		this.contactInfo = contactInfo;
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
	 * Gets the uuid.
	 *
	 * @return the uuid
	 */
	protected String getUUID() {
		String uuidStr = UUID.randomUUID().toString(); 
		return uuidStr; 	
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

	/** The contact info. */
	private ContactInfo contactInfo;

	/** The name. */
	private String name;

	/** The picture. */
	private Image picture;

	/** The account. */
	private Account account;

	/** The ratings. */
	private Map<String, Rating> ratings;

}

