/**
 * 
 */
package cscie97.asn3.squaredesk.renter;

import cscie97.asn3.squaredesk.provider.ContactInfo;
import cscie97.asn3.squaredesk.provider.Image;

/**
 * The Class Renter.
 */
public class Renter extends Profile{

	/**
	 * Gets the gender.
	 *
	 * @return the gender
	 */
	public String getGender() {
		return gender;
	}

	/**
	 * Sets the gender.
	 *
	 * @param gender
	 *            the new gender
	 */
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

	/**
	 * Gets the criteria.
	 *
	 * @return the criteria
	 */
	public Criteria getCriteria() {
		return criteria;
	}

	/**
	 * Sets the criteria.
	 *
	 * @param criteria
	 *            the new criteria
	 */
	public void setCriteria(Criteria criteria) {
		this.criteria = criteria;
	}

	/**
	 * Instantiates a new renter.
	 *
	 * @param name the name
	 * @param contactInfo the contact info
	 * @param picture the picture
	 */
	public Renter(String name, ContactInfo contactInfo, Image picture) {
		super(contactInfo, name, picture); 
	}

	/**
	 * Gets the renter id.
	 *
	 * @return the renter id
	 */
	public String getRenterId() {
		return renterId;
	}

	/**
	 * Sets the renter id.
	 *
	 * @param renterId
	 *            the new renter id
	 */
	public void setRenterId(String renterId) {
		this.renterId = renterId;
	}

	/** The renter id. */
	private String renterId;

	/** The gender. */
	private String gender;

	/** The criteria. */
	private Criteria criteria;

}

