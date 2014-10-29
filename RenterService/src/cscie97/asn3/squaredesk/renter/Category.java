/**
 * 
 */
package cscie97.asn3.squaredesk.renter;

/**
 * The Class Category.
 *
 * @author Vinod Halaharvi
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
	 * @param name the name to set
	 */
	void setName(String name) {
		this.name = name;
	} 

}
