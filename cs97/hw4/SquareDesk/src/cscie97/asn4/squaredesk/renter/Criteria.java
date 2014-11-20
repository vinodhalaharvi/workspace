/*
 * 
 */
package cscie97.asn4.squaredesk.renter;

import java.util.Date;
import java.util.List;

import cscie97.asn4.squaredesk.provider.Facility;
import cscie97.asn4.squaredesk.provider.Feature;
import cscie97.asn4.squaredesk.provider.Location;

/**
 * The Class Criteria.
 */

/**
 * @author vinodhalaharvi
 *
 */
public class Criteria {
	
	/**
	 * Gets the features.
	 *
	 * @return the features
	 */
	public List<Feature> getFeatures() {
		return features;
	}

	/**
	 * Sets the features.
	 *
	 * @param features
	 *            the new features
	 */
	public void setFeatures(List<Feature> features) {
		this.features = features;
	}



	/**
	 * Gets the location.
	 *
	 * @return the location
	 */
	public Location getLocation() {
		return location;
	}



	/**
	 * Sets the location.
	 *
	 * @param location
	 *            the new location
	 */
	public void setLocation(Location location) {
		this.location = location;
	}


	/**
	 * Gets the facility.
	 *
	 * @return the facility
	 */
	public Facility getFacility() {
		return facility;
	}



	/**
	 * Sets the facility.
	 *
	 * @param facility
	 *            the new facility
	 */
	public void setFacility(Facility facility) {
		this.facility = facility;
	}



	/**
	 * Gets the min rating.
	 *
	 * @return the min rating
	 */
	public int getMinRating() {
		return minRating;
	}



	/**
	 * Sets the min rating.
	 *
	 * @param minRating
	 *            the new min rating
	 */
	public void setMinRating(int minRating) {
		this.minRating = minRating;
	}


	/**
	 * Gets the start date.
	 *
	 * @return the start date
	 */
	public Date getStartDate() {
		return startDate;
	}


	/**
	 * Sets the start date.
	 *
	 * @param startDate
	 *            the new start date
	 */
	public void setStartDate(Date startDate) {
		this.startDate = startDate;
	}



	/**
	 * Gets the end date.
	 *
	 * @return the end date
	 */
	public Date getEndDate() {
		return endDate;
	}



	/**
	 * Sets the end date.
	 *
	 * @param endDate
	 *            the new end date
	 */
	public void setEndDate(Date endDate) {
		this.endDate = endDate;
	}



	/**
	 * Instantiates a new criteria.
	 *
	 * @param features the features
	 * @param location the location
	 * @param facility the facility
	 * @param minRating the min rating
	 * @param startDate the start date
	 * @param endDate the end date
	 */
	public Criteria(List<Feature> features, Location location,
			Facility facility, int minRating, Date startDate, Date endDate) {
		super();
		this.features = features;
		this.location = location;
		this.facility = facility;
		this.minRating = minRating;
		this.startDate = startDate;
		this.endDate = endDate;
	}



	/** The features. */
	private List<Feature> features;

	/** The location. */
	private Location location;

	/** The facility. */
	private Facility facility; 
	
	/** The min rating. */
	private int minRating; 


	/** The start date. */
	private Date startDate; 
	
	/** The end date. */
	private Date endDate; 
	
	
	/**
	 * Instantiates a new criteria.
	 */
	public Criteria() {
	}

}
