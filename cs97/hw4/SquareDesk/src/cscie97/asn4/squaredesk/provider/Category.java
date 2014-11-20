/**
 * 
 */
package cscie97.asn4.squaredesk.provider;

/**
 * The Class Category.
 */
public class Category {
	
	/** The name. */
	private String name;

	/**
	 * Instantiates a new category.
	 */
	public Category() {
		super();
	}

	/**
	 * Instantiates a new category.
	 *
	 * @param name the name
	 */
	public Category(String name) {
		super();
		this.name = name;
	}

	/**
	 * Gets the name.
	 *
	 * @return the name
	 */
	String getName() {
		return name;
	}

	/**
	 * Sets the name.
	 *
	 * @param name
	 *            the new name
	 */
	void setName(String name) {
		this.name = name;
	} 

}
