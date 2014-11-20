/**
 * 
 */
package cscie97.asn4.squaredesk.renter;

/**
 * The Class Account.
 */
public class Account {
	
	/** The pay pal account number. */
	private String payPalAccountNumber; 
	
	/**
	 * Instantiates a new account.
	 *
	 * @param payPalAccountNumber the pay pal account number
	 */
	public Account(String payPalAccountNumber) {
		super();
		this.setPayPalAccountNumber(payPalAccountNumber);
	}

	/**
	 * Gets the pay pal account number.
	 *
	 * @return the pay pal account number
	 */
	public String getPayPalAccountNumber() {
		return payPalAccountNumber;
	}

	/**
	 * Sets the pay pal account number.
	 *
	 * @param payPalAccountNumber
	 *            the new pay pal account number
	 */
	public void setPayPalAccountNumber(String payPalAccountNumber) {
		this.payPalAccountNumber = payPalAccountNumber;
	}


}
