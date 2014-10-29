package cscie97.asn3.squaredesk.renter;

import java.util.Date;
import java.util.List;
/**
 * 
 */

/**
 * @author vinodhalaharvi
 *
 */
public class Criteria {
	/** The features. */
	private List<Feature> features;
	
	public List<Feature> getFeatures() {
		return features;
	}



	public void setFeatures(List<Feature> features) {
		this.features = features;
	}



	public Location getLocation() {
		return location;
	}



	public void setLocation(Location location) {
		this.location = location;
	}



	public Facility getFacility() {
		return facility;
	}



	public void setFacility(Facility facility) {
		this.facility = facility;
	}



	public int getMinRating() {
		return minRating;
	}



	public void setMinRating(int minRating) {
		this.minRating = minRating;
	}



	public Date getStartDate() {
		return startDate;
	}



	public void setStartDate(Date startDate) {
		this.startDate = startDate;
	}



	public Date getEndDate() {
		return endDate;
	}



	public void setEndDate(Date endDate) {
		this.endDate = endDate;
	}



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



	/** The location. */
	private Location location;

	/** The facility. */
	private Facility facility; 
	
	/** The ratings. */
	private int minRating; 


	private Date startDate; 
	
	private Date endDate; 
	
	
	/**
	 * 
	 */
	public Criteria() {
		// TODO Auto-generated constructor stub
	}

}
