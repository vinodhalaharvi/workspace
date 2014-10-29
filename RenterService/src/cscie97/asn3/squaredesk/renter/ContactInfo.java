/**
 * 
 */
package cscie97.asn3.squaredesk.renter;

/**
 * The Class ContactInfo.
 *
 * @author Vinod Halaharvi
 */
public class ContactInfo {
	
	/**
	 * Instantiates a new contact info.
	 *
	 * @param email the email
	 * @param phoneNumber the phone number
	 */
	public ContactInfo(String email, String phoneNumber) {
		this.email = email;
		this.phoneNumber = phoneNumber;
	}
	
	
	/**
	 * Instantiates a new contact info.
	 *
	 * @param email the email
	 */
	public ContactInfo(String email) {
		this.email = email;
	}
	
	/** The email. */
	private String email; 
	
	/** The phone number. */
	private String phoneNumber; 
	
	/**
	 * Gets the email.
	 *
	 * @return the email
	 */
	public String getEmail() {
		return email;
	}
	
	/**
	 * Sets the email.
	 *
	 * @param email the email to set
	 */
	public void setEmail(String email) {
		this.email = email;
	}
	
	/**
	 * Gets the phone number.
	 *
	 * @return the phoneNumber
	 */
	public String getPhoneNumber() {
		return phoneNumber;
	}
	
	/**
	 * Sets the phone number.
	 *
	 * @param phoneNumber the phoneNumber to set
	 */
	public void setPhoneNumber(String phoneNumber) {
		this.phoneNumber = phoneNumber;
	}
}
