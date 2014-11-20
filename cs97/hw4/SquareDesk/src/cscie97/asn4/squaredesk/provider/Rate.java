/**
 * 
 */
package cscie97.asn4.squaredesk.provider;


/**
 * The Class Rate.
 */
public class Rate {

	/** The period. */
	private String period; 
	
	/** The cost. */
	private Double cost; 
	
	/**
	 * Gets the period.
	 *
	 * @return the period
	 */
	public String getPeriod() {
		return period;
	}


	/**
	 * Sets the period.
	 *
	 * @param period
	 *            the new period
	 */
	public void setPeriod(String period) {
		this.period = period;
	}


	/**
	 * Gets the cost.
	 *
	 * @return the cost
	 */
	public Double getCost() {
		return cost;
	}


	/**
	 * Sets the cost.
	 *
	 * @param cost
	 *            the new cost
	 */
	public void setCost(Double cost) {
		this.cost = cost;
	}


	/**
	 * Instantiates a new rate.
	 *
	 * @param period the period
	 * @param cost the cost
	 */
	public Rate(String period, Double cost) {
		this.period = period;
		this.cost = cost;
	}
}
