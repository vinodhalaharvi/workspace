/**
 * 
 */

/**
 * @author vinodhalaharvi
 *
 */
package cscie97.asn3.squaredesk.renter;

public class User {
	public Profile getRenter() {
		return renter;
	}

	public void setRenter(Profile renter) {
		this.renter = renter;
	}

	public Profile getProvider() {
		return provider;
	}

	public void setProvider(Profile provider) {
		this.provider = provider;
	}

	private Profile renter;
	private Profile provider; 
	
	/**
	 * 
	 */
	public User() {
	}

}
