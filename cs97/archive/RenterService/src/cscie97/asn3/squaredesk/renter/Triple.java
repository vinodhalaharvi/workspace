/**
 * 
 */
package cscie97.asn3.squaredesk.renter;

/**
 * The Class Triple.
 */
public class Triple {
	
	/**
	 * Gets the subject.
	 *
	 * @return the subject
	 */
	public Node getSubject() {
		return subject;
	}


	/**
	 * Sets the subject.
	 *
	 * @param subject
	 *            the new subject
	 */
	public void setSubject(Node subject) {
		this.subject = subject;
	}


	/**
	 * Gets the predicate.
	 *
	 * @return the predicate
	 */
	public Predicate getPredicate() {
		return predicate;
	}


	/**
	 * Sets the predicate.
	 *
	 * @param predicate
	 *            the new predicate
	 */
	public void setPredicate(Predicate predicate) {
		this.predicate = predicate;
	}


	/**
	 * Gets the object.
	 *
	 * @return the object
	 */
	public Node getObject() {
		return object;
	}


	/**
	 * Sets the object.
	 *
	 * @param object
	 *            the new object
	 */
	public void setObject(Node object) {
		this.object = object;
	}


	/**
	 * Sets the identifier.
	 *
	 * @param identifier
	 *            the new identifier
	 */
	public void setIdentifier(String identifier) {
		this.identifier = identifier;
	}

	/** The subject. */
	private Node subject; 
	
	/** The predicate. */
	private Predicate predicate; 
	
	/** The object. */
	private Node object;
	
	/** The identifier. */
	private String identifier; 

	/**
	 * @param subject
	 * @param predicate
	 * @param object
	 */
	public Triple(Node subject, Predicate predicate, Node object) {
		// TODO Auto-generated constructor stub
		this.subject = subject; 
		this.predicate = predicate; 
		this.object = object; 
		this.identifier = this.subject.getIdentifier() 
				+ " " + this.predicate.getIdentifier() 
				+ " " + this.object.getIdentifier();
	}
	
	
	@Override
	public boolean equals(Object obj) {
		Triple t = (Triple) obj; 
		return (obj != null) &&
				(obj instanceof Triple) &&
				t.identifier.equals(identifier);
	}
	
	@Override
	public int hashCode() {
		return identifier.hashCode();  
	}
	
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return subject.toString() + " " + 
				predicate.toString() + " " + 
				object.toString();
	}
	
	/**
	 * @param identifier
	 */
	public Triple(String identifier) {
		this.identifier = identifier; 
		String [] tokens =  identifier.split(" ");
		subject = new Node(tokens[0]);
		predicate = new Predicate(tokens[1]); 
		object = new Node(tokens[2]); 
	}
	
	/**
	 * Gets the identifier.
	 *
	 * @return the identifier
	 */
	public String getIdentifier() {
		return  this.identifier; 
	}
}