/**
 * 
 */
package cscie97.asn3.squaredesk.authentication;

// TODO: Auto-generated Javadoc
/**
 * The Class Entitlement.
 *
 * @author vinodhalaharvi
 */
public abstract class Entitlement {
	
	/**
	 * Instantiates a new entitlement.
	 */
	public Entitlement() {
		super();
	}

	/**
	 * Instantiates a new entitlement.
	 *
	 * @param entitlementId the entitlement id
	 */
	public Entitlement(String entitlementId) {
		super();
		this.entitlementId = entitlementId;
	}

	/** The entitlement id. */
	private String entitlementId;

	/**
	 * Gets the entitlement id.
	 *
	 * @return the entitlement id
	 */
	public String getEntitlementId() {
		return entitlementId;
	}

	/**
	 * Sets the entitlement id.
	 *
	 * @param entitlementId the new entitlement id
	 */
	public void setEntitlementId(String entitlementId) {
		this.entitlementId = entitlementId;
	} 
	
}
