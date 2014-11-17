/*
 * 
 */
package cscie97.asn3.squaredesk.renter;

/**
 * The Class Predicate.
 */

/**
 * @author vinodhalaharvi
 *
 */
public class Predicate {
	
	/** The identifier. */
	private String identifier; 
	
	/**
	 * @param indentifier 
	 */
	public Predicate(String identifier) {
		this.identifier = identifier; 
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return identifier; 
	}
	
	/**
	 * Gets the identifier.
	 *
	 * @return the identifier
	 */
	public String getIdentifier() {
		return this.identifier; 
	}

}
