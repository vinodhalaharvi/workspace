/*
 * 
 */
package cscie97.asn3.squaredesk.renter;

// TODO: Auto-generated Javadoc
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
	 * Instantiates a new node.
	 *
	 * @param identifier the identifier
	 */
	public Node(String identifier) {
		// TODO Auto-generated constructor stub
		this.identifier = identifier; 
	}
	
	/* (non-Javadoc)
	 * @see java.lang.Object#toString()
	 */
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return identifier; 
	}
	
	
	/* (non-Javadoc)
	 * @see java.lang.Object#equals(java.lang.Object)
	 */
	@Override
	public boolean equals(Object obj) {
		Node t = (Node) obj; 
		return (obj != null) &&
				(obj instanceof Triple) &&
				t.identifier.equals(identifier);
	}
	
	/* (non-Javadoc)
	 * @see java.lang.Object#hashCode()
	 */
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
