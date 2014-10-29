/**
 * 
 */
package cscie97.asn3.squaredesk.renter;

/**
 * @author vinodhalaharvi
 *
 */
public class Triple {
	private Node subject; 
	private Predicate predicate; 
	private Node object;
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
		return subject.toString() +
				predicate.toString() + 
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
	 * return identifier for this class
	 */
	public String getIdentifier() {
		return  this.identifier; 
	}
}
