package cscie97.asn3.squaredesk.renter;
/**
 * 
 */

/**
 * @author vinodhalaharvi
 *
 */
public class Predicate {
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
	 * Return the identifier for this class
	 */
	public String getIdentifier() {
		return this.identifier; 
	}

}
