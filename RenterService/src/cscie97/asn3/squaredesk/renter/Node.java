/*
 * 
 */
package cscie97.asn3.squaredesk.renter;

/**
 * The Class Node.
 */

/**
 * @author vinodhalaharvi
 *
 */
public class Node {
	
	/** The identifier. */
	private String identifier; 

	/**
	 * 
	 */
	public Node(String identifier) {
		// TODO Auto-generated constructor stub
		this.identifier = identifier; 
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return identifier; 
	}
	
	
	@Override
	public boolean equals(Object obj) {
		Node t = (Node) obj; 
		return (obj != null) &&
				(obj instanceof Triple) &&
				t.identifier.equals(identifier);
	}
	
	@Override
	public int hashCode() {
		return identifier.hashCode();  
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
