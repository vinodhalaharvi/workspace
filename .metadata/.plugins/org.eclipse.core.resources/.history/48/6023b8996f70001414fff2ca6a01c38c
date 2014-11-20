/**
 * 
 */
package cscie97.asn3.squaredesk.provider;

import java.util.ArrayList;
import java.util.List;

import cscie97.asn3.squaredesk.renter.KnowledgeGraph;
import cscie97.asn3.squaredesk.renter.Triple;

// TODO: Auto-generated Javadoc
/**
 * The Class OfficeSpace.
 */
public class OfficeSpace {

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

	

	/* (non-Javadoc)
	 * @see java.lang.Object#equals(java.lang.Object)
	 */
	@Override
	public boolean equals(Object obj) {
		OfficeSpace t = (OfficeSpace) obj; 
		return (obj != null) &&
				(obj instanceof OfficeSpace) &&
				t.offId.equals(offId);
	}
	
	/* (non-Javadoc)
	 * @see java.lang.Object#hashCode()
	 */
	@Override
	public int hashCode() {
		return offId.hashCode();  
	}
	
	
	/**
	 * Gets the location.
	 *
	 * @return the location
	 */
	/**
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

		if(isSearchable()){
			KnowledgeGraph.removeTriple(new Triple(
					offId + " has_lat_long " + (int)Math.floor(this.location.getLat()) + "_"
							+ (int)Math.floor(this.location.getlng())));
			this.location = location;
			//now go ahead and add the new one
			KnowledgeGraph.addTriple(new Triple(
					offId + " has_lat_long " + (int)Math.floor(location.getLat()) + "_"
							+ (int)Math.floor(location.getlng())));
		} else {
			this.location = location;	
		}
	}

	/**
	 * Gets the capacity.
	 *
	 * @return the capacity
	 */
	public Capacity getCapacity() {
		return capacity;
	}

	/**
	 * Sets the capacity.
	 *
	 * @param capacity
	 *            the new capacity
	 */
	public void setCapacity(Capacity capacity) {
		this.capacity = capacity;
	}


	/**
	 * Gets the off id.
	 *
	 * @return the off id
	 */
	public String getOffId() {
		return offId;
	}

	/**
	 * Sets the off id.
	 *
	 * @param offId
	 *            the new off id
	 */
	public void setOffId(String offId) {
		this.offId = offId;
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
		if(isSearchable()){
			if (facility.getCategory() == ""){
				KnowledgeGraph.addTriple(new Triple(offId + " has_facility_type_category " +
						facility.getType()));
			} else {
				KnowledgeGraph.addTriple(new Triple(offId + " has_facility_type_category " +
						facility.getType() + "_" + facility.getCategory().replace(' ', '_')));
			}
			this.facility = facility;
			if (facility.getCategory() == ""){
				KnowledgeGraph.addTriple(new Triple(offId + " has_facility_type_category " +
						facility.getType()));
			} else {
				KnowledgeGraph.addTriple(new Triple(offId + " has_facility_type_category " +
						facility.getType() + "_" + facility.getCategory().replace(' ', '_')));
			}
		} else {
			this.facility = facility;
		}
	}

	/** The off id. */
	private String offId;

	/** The name. */
	private String name; 

	/** The searchable. */
	private boolean searchable; 

	/**
	 * Checks if is the searchable.
	 *
	 * @return the searchable
	 */
	public boolean isSearchable() {
		return searchable;
	}

	/**
	 * Sets the searchable.
	 *
	 * @param searchable
	 *            the new searchable
	 */
	public void setSearchable(boolean searchable) {
		this.searchable = searchable;
	}

	/** The location. */
	private Location location;

	/** The capacity. */
	private Capacity capacity; 

	/** The facility. */
	private Facility facility; 

	/** The features. */
	private List<Feature> features;

	/** The rates. */
	private List<Rate> rates;

	/** The common access. */
	private List<Feature> commonAccess;

	/** The images. */
	private List<Image> images; 

	/** The ratings. */
	private List<Rating> ratings; 
	
	/** The avg rating. */
	private Double avgRating; 
	

	/**
	 * Gets the avg rating.
	 *
	 * @return the avg rating
	 */
	public Double getAvgRating() {
		return avgRating;
	}

	/**
	 * Instantiates a new office space.
	 *
	 * @param name the name
	 * @param location the location
	 * @param capacity the capacity
	 * @param facility the facility
	 * @param rate the rate
	 */
	public OfficeSpace(String name, Location location, Capacity capacity,
			Facility facility, Rate rate) {
		this.rates = new ArrayList<Rate>();
		setName(name);
		setLocation(location);
		setCapacity(capacity);
		setFacility(facility);
		this.rates.add(rate); 
		setSearchable(false);
		this.features = new ArrayList<Feature>();
		this.commonAccess = new ArrayList<Feature>(); 
		this.images = new ArrayList<Image>(); 
		this.ratings = new ArrayList<Rating>(); 
	}
	

	
	/**
	 * Adds the feature.
	 *
	 * @param authToken the auth token
	 * @param feature the feature
	 * @return the feature
	 */
	public Feature addFeature(String authToken,  String feature){
		//ProviderService.getInstance(); 
		Feature featureObj = ProviderService.getFeature(feature);
		features.add(featureObj);
		if(isSearchable()){ 
			KnowledgeGraph.addTriple(new Triple(offId + " has_feature " + feature));
		}
		return featureObj;
	}

	/**
	 * Removes the feature.
	 *
	 * @param authToken the auth token
	 * @param feature the feature
	 */
	public void removeFeature(String authToken, String feature){
		//ProviderService providerService = ProviderService.getInstance(); 
		Feature featureObj = ProviderService.getFeature(feature);
		features.remove(featureObj); 
		if(isSearchable()){ 
			KnowledgeGraph.removeTriple(new Triple(offId + " has_feature " + featureObj.getName()));
		}
	}

	/**
	 * Gets the feature.
	 *
	 * @param authToken the auth token
	 * @param feature the feature
	 * @return the feature
	 */
	public Feature getFeature(String authToken, String feature){ 
		//ProviderService.getInstance(); 
		Feature featureObj = ProviderService.getFeature(feature);
		return featureObj; 
	}

	/**
	 * Gets the features.
	 *
	 * @return the features
	 */
	public List<Feature> getFeatures() {
		return features; 
	}

	/**
	 * Adds the rate.
	 *
	 * @param authToken the auth token
	 * @param rate the rate
	 * @return the rate
	 */
	public Rate addRate(String authToken,  Rate rate){
		rates.add(rate);
		return rate;
	}

	/**
	 * Removes the rate.
	 *
	 * @param authToken the auth token
	 * @param rate the rate
	 */
	public void removeRate(String authToken, Rate rate){ 
		rates.remove(rate); 
	}

	/**
	 * Gets the rates.
	 *
	 * @return the rates
	 */
	public List<Rate> getRates() {
		return rates;
	}

	/**
	 * Adds the image.
	 *
	 * @param authToken the auth token
	 * @param image the image
	 * @return the image
	 */
	public Image addImage(String authToken,  Image image){
		images.add(image);
		return image;
	}

	/**
	 * Removes the image.
	 *
	 * @param authToken the auth token
	 * @param image the image
	 */
	public void removeImage(String authToken, Image image){
		images.remove(image);
	}

	/**
	 * Gets the images.
	 *
	 * @return the images
	 */
	public List<Image> getImages() {
		return images;
	}

	/**
	 * Adds the feature to common access.
	 *
	 * @param authToken the auth token
	 * @param feature the feature
	 * @return the feature
	 */
	public Feature addFeatureToCommonAccess(String authToken,  Feature feature){
		commonAccess.add(feature);
		return feature;
	}

	/**
	 * Removes the feature from common access.
	 *
	 * @param authToken the auth token
	 * @param feature the feature
	 */
	public void removeFeatureFromCommonAccess(String authToken, Feature feature){
		commonAccess.remove(feature);
	}

	/**
	 * Gets the feature list from common access.
	 *
	 * @return the feature list from common access
	 */
	public List<Feature> getFeatureListFromCommonAccess() {
		return commonAccess;
	}

	/**
	 * Adds the rating.
	 *
	 * @param authToken the auth token
	 * @param rating the rating
	 * @return the rating
	 */
	public Rating addRating(String authToken,  Rating rating){
		ratings.add(rating);
		Double sum = 0.0; 
		for(Rating iterRating : getRatings()){
			sum += iterRating.getStars(); 
		}
		avgRating = (sum*1.0)/getRatings().size(); 
		if(isSearchable()){
			KnowledgeGraph.addTriple(new Triple(offId + " has_rating " + rating.getStars()));	
		}
		return rating;
	}

	/**
	 * Removes the rating.
	 *
	 * @param authToken the auth token
	 * @param rating the rating
	 */
	public void removeRating(String authToken, Rating rating){
		ratings.remove(rating);
		Double sum = 0.0; 
		for(Rating iterRating : getRatings()){
			sum += iterRating.getStars(); 
		}
		avgRating = (sum*1.0)/getRatings().size(); 
		if(isSearchable()){
			KnowledgeGraph.removeTriple(new Triple(offId + " has_rating " + rating.getStars()));	
		}
	}

	/**
	 * Gets the ratings.
	 *
	 * @return the ratings
	 */
	public List<Rating> getRatings() {
		return ratings;
	}	

}