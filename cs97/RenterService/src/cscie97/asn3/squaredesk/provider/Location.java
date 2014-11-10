/**
 * 
 */
package cscie97.asn3.squaredesk.provider;

/**
 * The Class Location.
 */
public class Location {
	
	/** The street1. */
	private String street1; 
	
	/** The street2. */
	private String street2; 
	
	/** The city. */
	private String city; 
	
	/** The state. */
	private String state; 
	
	/** The zip code. */
	private String zipCode; 
	
	/** The address. */
	private String address; 
	
	/** The country code. */
	private String countryCode; 
	
	/** The lat. */
	private Double lat; 
	
	/** The lng. */
	private Double lng; 

	
	/**
	 * Gets the street1.
	 *
	 * @return the street1
	 */
	public String getStreet1() {
		return street1;
	}

	/**
	 * Sets the street1.
	 *
	 * @param street1
	 *            the new street1
	 */
	public void setStreet1(String street1) {
		this.street1 = street1;
	}

	/**
	 * Gets the street2.
	 *
	 * @return the street2
	 */
	public String getStreet2() {
		return street2;
	}

	/**
	 * Sets the street2.
	 *
	 * @param street2
	 *            the new street2
	 */
	public void setStreet2(String street2) {
		this.street2 = street2;
	}

	/**
	 * Gets the city.
	 *
	 * @return the city
	 */
	public String getCity() {
		return city;
	}

	/**
	 * Sets the city.
	 *
	 * @param city
	 *            the new city
	 */
	public void setCity(String city) {
		this.city = city;
	}

	/**
	 * Gets the state.
	 *
	 * @return the state
	 */
	public String getState() {
		return state;
	}

	/**
	 * Sets the state.
	 *
	 * @param state
	 *            the new state
	 */
	public void setState(String state) {
		this.state = state;
	}

	/**
	 * Gets the zip code.
	 *
	 * @return the zip code
	 */
	public String getZipCode() {
		return zipCode;
	}

	/**
	 * Sets the zip code.
	 *
	 * @param zipCode
	 *            the new zip code
	 */
	public void setZipCode(String zipCode) {
		this.zipCode = zipCode;
	}

	/**
	 * Gets the country code.
	 *
	 * @return the country code
	 */
	public String getCountryCode() {
		return countryCode;
	}

	/**
	 * Sets the country code.
	 *
	 * @param countryCode
	 *            the new country code
	 */
	public void setCountryCode(String countryCode) {
		this.countryCode = countryCode;
	}

	/**
	 * Gets the lat.
	 *
	 * @return the lat
	 */
	public Double getLat() {
		return lat;
	}

	/**
	 * Sets the lat.
	 *
	 * @param lat
	 *            the new lat
	 */
	public void setLat(Double lat) {
		this.lat = lat;
	}

	/**
	 * Gets the lng.
	 *
	 * @return the lng
	 */
	public Double getlng() {
		return lng;
	}

	/**
	 * Sets the lng.
	 *
	 * @param lng the lng to set
	 */
	public void setlng(Double lng) {
		this.lng = lng;
	}

	
	/**
	 * Gets the address.
	 *
	 * @return the address
	 */
	public String getAddress() {
		return address;
	}

	/**
	 * Sets the address.
	 *
	 * @param address
	 *            the new address
	 */
	public void setAddress(String address) {
		this.address = address;
	}


	/**
	 * Instantiates a new location.
	 *
	 * @param street1 the street1
	 * @param street2 the street2
	 * @param city the city
	 * @param state the state
	 * @param zipCode the zip code
	 * @param address the address
	 * @param countryCode the country code
	 * @param lat the lat
	 * @param lng the lng
	 */
	public Location(String street1, String street2, String city, String state,
			String zipCode, String address, String countryCode, Double lat,
			Double lng) {
		super();
		this.street1 = street1;
		this.street2 = street2;
		this.city = city;
		this.state = state;
		this.zipCode = zipCode;
		this.address = address;
		this.countryCode = countryCode;
		this.lat = lat;
		this.lng = lng;
	}
	


}
