/**
 * 
 */
package provider;

/**
 * The Class Feature.
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
	 * @param name
	 *            the new name
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
