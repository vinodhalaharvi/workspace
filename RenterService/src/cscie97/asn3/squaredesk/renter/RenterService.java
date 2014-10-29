package cscie97.asn3.squaredesk.renter;
import java.util.Collection;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

/**
 * The Class RenterService.
 *
 * @author Vinod Halaharvi
 */
public class RenterService {

	/** The renter service. */
	private static RenterService renterService;  
	/** The renters. */
	private static Map<String, Renter> renters = new HashMap<String, Renter>();
	
	private static BookingService bookingService; 

	public static BookingService getBookingService() {
		return bookingService;
	}


	public static void setBookingService(BookingService bookingService) {
		RenterService.bookingService = bookingService;
	}


	/**
	 * Gets the UUID from string.
	 *
	 * @param name the name
	 * @return the UUID from string
	 */
	public static String getUUIDFromString(String name) {
		String uuidStr = UUID.nameUUIDFromBytes(name.getBytes()).toString(); 
		return uuidStr; 	
	}


	/**
	 * Gets the single instance of RenterService.
	 *
	 * @return single instance of RenterService
	 */
	public static RenterService getInstance() {
		if (renterService == null){
			renterService = new RenterService();
			return renterService;
		} else {
			return renterService;
		}
	}


	public Renter createRenter(String authToken, String name, 
			ContactInfo contactInfo, Image picture
			) throws RenterAlreadyExistException, AccessException{ 
		//Assumption is that renter name is unique in the system
		//And servers a natural key to the renter object
		String uuidName = getUUIDFromString(name); 
		if (renters.containsKey(uuidName)){
			throw new RenterAlreadyExistException("This Renter Already Exists");
		} else {
			Renter renterObj = new Renter(name, contactInfo, picture);
			renterObj.setRenterId(uuidName); 
			renters.put(uuidName, renterObj);
			return renterObj; 
		}
	}

	/**
	 * Gets the renter.
	 *
	 * @param authToken the auth token
	 * @param renterId the renter id
	 * @return the renter
	 * @throws RenterNotFoundException the renter not found exception
	 * @throws AccessException the access exception
	 */
	public Renter getRenter(String authToken, String renterId) 
			throws RenterNotFoundException, AccessException {
		return getRenter(renterId); 
	}
	

	/**
	 * Gets the renter list.
	 *
	 * @param authToken the auth token
	 * @return the renter list
	 * @throws AccessException the access exception
	 */
	public Collection<Renter> getRenterList(String authToken)
			throws AccessException{
		return renters.values();  
	}

	/**
	 * Gets the renter.
	 *
	 * @param renterId the renter id
	 * @return the renter
	 * @throws RenterNotFoundException the renter not found exception
	 */
	private Renter getRenter(String renterId) 
			throws RenterNotFoundException {
		if (!renters.containsKey(renterId)){
			throw new RenterNotFoundException("This Renter Already Exists"); 
		} else { 
			return renters.get(renterId); 
		}
	}


	/**
	 * Update renter name.
	 *
	 * @param authToken the auth token
	 * @param renterId the renter id
	 * @param name the name
	 * @return the renter
	 * @throws RenterNotFoundException the renter not found exception
	 * @throws AccessException the access exception
	 */
	public Renter updateRenterName(String authToken, String renterId, String name) 
			throws RenterNotFoundException, AccessException{
		Renter renterObj = getRenter(renterId);
		String renterOldName = renterObj.getName(); 
		renterObj.setName(name);
		String renterNewId = getUUIDFromString(name);
		renterObj.setRenterId(renterNewId);
		//remove the mapping with old name since the renter name got changed
		renters.remove(getUUIDFromString(renterOldName)); 
		//reinsert a new entry with new renter name
		renters.put(renterNewId, renterObj); 
		return renterObj;	
	}

	/**
	 * Update renter contact info.
	 *
	 * @param authToken the auth token
	 * @param renterId the renter id
	 * @param contactInfo the contact info
	 * @return the renter
	 * @throws RenterNotFoundException the renter not found exception
	 * @throws AccessException the access exception
	 */
	public Renter updateRenterContactInfo(String authToken, String renterId, 
			ContactInfo contactInfo) throws RenterNotFoundException, AccessException{
		Renter renterObj = getRenter(renterId); 
		renterObj.setContactInfo(contactInfo);
		return renterObj;	
	}


	/**
	 * Update renter picture.
	 *
	 * @param authToken the auth token
	 * @param renterId the renter id
	 * @param picture the picture
	 * @return the renter
	 * @throws RenterNotFoundException the renter not found exception
	 * @throws AccessException the access exception
	 */
	public Renter updateRenterPicture(String authToken, String renterId, 
			Image picture) throws RenterNotFoundException, AccessException{
		Renter renterObj = getRenter(renterId); 
		renterObj.setImage(picture);  
		return renterObj;
	}

	/**
	 * Delete renter.
	 *
	 * @param authToken the auth token
	 * @param renterId the renter id
	 * @throws RenterNotFoundException the renter not found exception
	 * @throws AccessException the access exception
	 */
	public void deleteRenter(String authToken, String renterId) 
			throws RenterNotFoundException, AccessException{
		renters.remove(renterId);
	}

	/**
	 * Adds the rating to renter.
	 *
	 * @param authToken the auth token
	 * @param renterId the renter id
	 * @param rating the rating
	 * @return the rating
	 * @throws RenterNotFoundException the renter not found exception
	 */
	public Rating addRatingToRenter(String authToken, String renterId, Rating rating)
			throws RenterNotFoundException{
		Renter renterObj = getRenter(renterId); 
		renterObj.addRatingToList(rating); 
		return rating; 
	}

	/**
	 * Removes the rating from renter.
	 *
	 * @param authToken the auth token
	 * @param renterId the renter id
	 * @param ratingId the rating id
	 * @throws RenterNotFoundException the renter not found exception
	 * @throws RatingNotFoundException the rating not found exception
	 */
	public void removeRatingFromRenter(String authToken, String renterId, String ratingId) 
			throws RenterNotFoundException, RatingNotFoundException{
		Renter renterObj = getRenter(renterId); 
		renterObj.removeRatingfromList(ratingId); 
	}

	/**
	 * Gets the rating list for renter.
	 *
	 * @param authToken the auth token
	 * @param renterId the renter id
	 * @return the rating list for renter
	 * @throws RenterNotFoundException the renter not found exception
	 */
	public Collection<Rating> getRatingListForRenter(String authToken, String renterId)
			throws RenterNotFoundException{
		Renter renterObj = getRenter(renterId); 
		return renterObj.getRatings();
	}
	
	public Criteria createSearchCriteria(){
		return null;
	}
	
	
	public Collection<OfficeSpace> searchKGUsingCriteria(String authToken, Criteria criteria){ 
		return null; 
	}
	
	
	public Collection<OfficeSpace> searchKGUsingFeatures(String authToken, Collection<Feature> features){ 
		return null; 
	}
	
	public Collection<OfficeSpace> searchKGUsingLocation(String authToken, Location location){ 
		return null; 
	}
	
	
	public Collection<OfficeSpace> searchKGUsingFacilityAndCategory(String authToken, Facility facility, 
			Category category){ 
		return null; 
	}
	
	public Collection<OfficeSpace> searchKGUsingRating(String authToken, int minRating){ 
		return null; 
	}
	
	
	public Collection<OfficeSpace> searchKGUsingDates(String authToken, Date startDate, Date endDate){ 
		return null; 
	}	
	

	
	/**
	 * Instantiates a new renter service.
	 */
	public RenterService() {
	}

}
