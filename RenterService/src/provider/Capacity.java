/**
 * 
 */
package provider;

/**
 * The Class Capacity.
 */
public class Capacity {
	
	/** The num of people. */
	private int numOfPeople; 
	
	/** The square footage. */
	private Double squareFootage; 
	
	/** The num of work spaces. */
	private int numOfWorkSpaces; 
	
	/**
	 * Instantiates a new capacity.
	 *
	 * @param numOfPeople the num of people
	 * @param squareFootage the square footage
	 * @param numOfWorkSpaces the num of work spaces
	 */
	public Capacity(int numOfPeople, Double squareFootage, int numOfWorkSpaces) {
		this.numOfPeople = numOfPeople;
		this.squareFootage = squareFootage;
		this.numOfWorkSpaces = numOfWorkSpaces;
	}
	
	/**
	 * Gets the num of people.
	 *
	 * @return the num of people
	 */
	public int getNumOfPeople() {
		return numOfPeople;
	}
	
	/**
	 * Sets the num of people.
	 *
	 * @param numOfPeople
	 *            the new num of people
	 */
	public void setNumOfPeople(int numOfPeople) {
		this.numOfPeople = numOfPeople;
	}
	
	/**
	 * Gets the square footage.
	 *
	 * @return the square footage
	 */
	public Double getSquareFootage() {
		return squareFootage;
	}
	
	/**
	 * Sets the square footage.
	 *
	 * @param squareFootage
	 *            the new square footage
	 */
	public void setSquareFootage(Double squareFootage) {
		this.squareFootage = squareFootage;
	}
	
	/**
	 * Gets the num of work spaces.
	 *
	 * @return the num of work spaces
	 */
	public int getNumOfWorkSpaces() {
		return numOfWorkSpaces;
	}
	
	/**
	 * Sets the num of work spaces.
	 *
	 * @param numOfWorkSpaces
	 *            the new num of work spaces
	 */
	public void setNumOfWorkSpaces(int numOfWorkSpaces) {
		this.numOfWorkSpaces = numOfWorkSpaces;
	}

	/**
	 * Instantiates a new capacity.
	 */

	public Capacity() {
		// TODO Auto-generated constructor stub
	}
}
