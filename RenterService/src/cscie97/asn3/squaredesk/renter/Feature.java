/**
 * 
 */
package cscie97.asn3.squaredesk.renter;

/**
 * The Class Feature.
 *
 * @author Vinod Halaharvi
 */
public class Feature {
	
	/** The name. */
	private String name;

	/**
	 * Gets the name.
	 *
	 * @return the name
	 */
	public String getName() {
		return name;
	}

	/**
	 * Sets the name.
	 *
	 * @param name the name to set
	 */
	public void setName(String name) {
		this.name = name;
	}

	/**
	 * Instantiates a new feature.
	 *
	 * @param name the name
	 */
	public Feature(String name) {
		this.setName(name); 
	}
}
