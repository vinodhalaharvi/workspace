/**
 * 
 */
package cscie97.asn3.squaredesk.renter;


/**
 * The Class FacilityType.
 *
 * @author vinod Halaharvi
 */
public class FacilityType {
	
	/**
	 * Instantiates a new facility type.
	 *
	 * @param type the type
	 */
	public FacilityType(String type) {
		super();
		this.type = type;
	}

	/**
	 * Gets the type.
	 *
	 * @return the type
	 */
	public String getType() {
		return type;
	}

	/**
	 * Sets the type.
	 *
	 * @param type the new type
	 */
	public void setType(String type) {
		this.type = type;
	}

	/** The type. */
	private String type; 
}
