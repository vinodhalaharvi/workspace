/*
 * 
 */
package cscie97.asn4.squaredesk.renter;

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
	 * Instantiates a new predicate.
	 *
	 * @param identifier the identifier
	 */
	public Predicate(String identifier) {
		this.identifier = identifier; 
	}
	
	/* (non-Javadoc)
	 * @see java.lang.Object#toString()
	 */
	@Override
	public String toString() {
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
