package cscie97.asn3.squaredesk.renter;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

/**
 * The Class ProviderService.
 *
 * @author Vinod Halaharvi
 */
public class ProviderService {

	/** The provider service. */
	private static ProviderService providerService;  
	/** The providers. */
	private static Map<String, Provider> providers = new HashMap<String, Provider>();

	/** The features. */
	private static Map<String, Feature> features = new HashMap<String, Feature>(); 
	
	/** The facility types. */
	private static Map<String, FacilityType> facilityTypes = new HashMap<String, FacilityType>(); 
	
	/** The categories. */
	private static Map<String, Category> categories = new HashMap<String, Category>(); 

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
	 * Gets the single instance of ProviderService.
	 *
	 * @return single instance of ProviderService
	 */
	public static ProviderService getInstance() {
		if (providerService == null){
			providerService = new ProviderService();
			return providerService;
		} else {
			return providerService;
		}
	}


	/**
	 * Gets the feature.
	 *
	 * @param name the name
	 * @return the feature
	 */
	public Feature getFeature(String name) {
		String uuidName = getUUIDFromString(name); 
		if (features.containsKey(uuidName)){ 
			return features.get(uuidName); 
		} else { 
			Feature feature = new Feature(name);
			features.put(uuidName, feature);
			return feature; 
		}
	}

	/**
	 * Gets the category.
	 *
	 * @param name the name
	 * @return the category
	 */
	public Category getCategory(String name) {
		String uuidName = getUUIDFromString(name); 
		if (categories.containsKey(uuidName)){ 
			return categories.get(uuidName); 
		} else {
			Category category = new Category(name);
			categories.put(uuidName, category); 
			return category; 
		}
	}

	/**
	 * Gets the facility type.
	 *
	 * @param type the type
	 * @return the facility type
	 */
	public FacilityType getFacilityType(String type) {
		String uuidName = getUUIDFromString(type); 
		if (facilityTypes.containsKey(uuidName)){ 
			return facilityTypes.get(uuidName); 
		} else {
			FacilityType facilityType = new FacilityType(type);
			facilityTypes.put(uuidName, facilityType); 
			return facilityType; 
		}
	}


	/**
	 * Creates the provider.
	 *
	 * @param authToken the auth token
	 * @param name the name
	 * @param contactInfo the contact info
	 * @param picture the picture
	 * @return the provider
	 * @throws ProviderAlreadyExistException the provider already exist exception
	 * @throws AccessException the access exception
	 */
	public Provider createProvider(String authToken, String name, 
			ContactInfo contactInfo, Image picture
			) throws ProviderAlreadyExistException, AccessException{ 
		//Assumption is that provider name is unique in the system
		//And servers a natural key to the provider object
		String uuidName = getUUIDFromString(name); 
		if (providers.containsKey(uuidName)){
			throw new ProviderAlreadyExistException("This Provider Already Exists");
		} else {
			Provider providerObj = new Provider(name, contactInfo, picture);
			providerObj.setProviderId(uuidName); 
			providers.put(uuidName, providerObj);
			return providerObj; 
		}
	}

	/**
	 * Gets the provider.
	 *
	 * @param authToken the auth token
	 * @param providerId the provider id
	 * @return the provider
	 * @throws ProviderNotFoundException the provider not found exception
	 * @throws AccessException the access exception
	 */
	public Provider getProvider(String authToken, String providerId) 
			throws ProviderNotFoundException, AccessException {
		return getProvider(providerId); 
	}
	

	/**
	 * Gets the provider list.
	 *
	 * @param authToken the auth token
	 * @return the provider list
	 * @throws AccessException the access exception
	 */
	public Collection<Provider> getProviderList(String authToken)
			throws AccessException{
		return providers.values();  
	}

	/**
	 * Gets the provider.
	 *
	 * @param providerId the provider id
	 * @return the provider
	 * @throws ProviderNotFoundException the provider not found exception
	 */
	private Provider getProvider(String providerId) 
			throws ProviderNotFoundException {
		if (!providers.containsKey(providerId)){
			throw new ProviderNotFoundException("This Provider Already Exists"); 
		} else { 
			return providers.get(providerId); 
		}
	}


	/**
	 * Update provider name.
	 *
	 * @param authToken the auth token
	 * @param providerId the provider id
	 * @param name the name
	 * @return the provider
	 * @throws ProviderNotFoundException the provider not found exception
	 * @throws AccessException the access exception
	 */
	public Provider updateProviderName(String authToken, String providerId, String name) 
			throws ProviderNotFoundException, AccessException{
		Provider providerObj = getProvider(providerId);
		String providerOldName = providerObj.getName(); 
		providerObj.setName(name);
		String providerNewId = getUUIDFromString(name);
		providerObj.setProviderId(providerNewId);
		//remove the mapping with old name since the provider name got changed
		providers.remove(getUUIDFromString(providerOldName)); 
		//reinsert a new entry with new provider name
		providers.put(providerNewId, providerObj); 
		return providerObj;	
	}

	/**
	 * Update provider contact info.
	 *
	 * @param authToken the auth token
	 * @param providerId the provider id
	 * @param contactInfo the contact info
	 * @return the provider
	 * @throws ProviderNotFoundException the provider not found exception
	 * @throws AccessException the access exception
	 */
	public Provider updateProviderContactInfo(String authToken, String providerId, 
			ContactInfo contactInfo) throws ProviderNotFoundException, AccessException{
		Provider providerObj = getProvider(providerId); 
		providerObj.setContactInfo(contactInfo);
		return providerObj;	
	}


	/**
	 * Update provider picture.
	 *
	 * @param authToken the auth token
	 * @param providerId the provider id
	 * @param picture the picture
	 * @return the provider
	 * @throws ProviderNotFoundException the provider not found exception
	 * @throws AccessException the access exception
	 */
	public Provider updateProviderPicture(String authToken, String providerId, 
			Image picture) throws ProviderNotFoundException, AccessException{
		Provider providerObj = getProvider(providerId); 
		providerObj.setImage(picture);  
		return providerObj;
	}

	/**
	 * Delete provider.
	 *
	 * @param authToken the auth token
	 * @param providerId the provider id
	 * @throws ProviderNotFoundException the provider not found exception
	 * @throws AccessException the access exception
	 */
	public void deleteProvider(String authToken, String providerId) 
			throws ProviderNotFoundException, AccessException{
		providers.remove(providerId);
	}

	/**
	 * Adds the rating to provider.
	 *
	 * @param authToken the auth token
	 * @param providerId the provider id
	 * @param rating the rating
	 * @return the rating
	 * @throws ProviderNotFoundException the provider not found exception
	 */
	public Rating addRatingToProvider(String authToken, String providerId, Rating rating)
			throws ProviderNotFoundException{
		Provider providerObj = getProvider(providerId); 
		providerObj.addRatingToList(rating); 
		return rating; 
	}

	/**
	 * Removes the rating from provider.
	 *
	 * @param authToken the auth token
	 * @param providerId the provider id
	 * @param ratingId the rating id
	 * @throws ProviderNotFoundException the provider not found exception
	 * @throws RatingNotFoundException the rating not found exception
	 */
	public void removeRatingFromProvider(String authToken, String providerId, String ratingId) 
			throws ProviderNotFoundException, RatingNotFoundException{
		Provider providerObj = getProvider(providerId); 
		providerObj.removeRatingfromList(ratingId); 
	}

	/**
	 * Gets the rating list for provider.
	 *
	 * @param authToken the auth token
	 * @param providerId the provider id
	 * @return the rating list for provider
	 * @throws ProviderNotFoundException the provider not found exception
	 */
	public Collection<Rating> getRatingListForProvider(String authToken, String providerId)
			throws ProviderNotFoundException{
		Provider providerObj = getProvider(providerId); 
		return providerObj.getRatings();
	}

	/**
	 * Adds the office space to provider.
	 *
	 * @param authToken the auth token
	 * @param providerId the provider id
	 * @param officeSpace the office space
	 * @return the office space
	 * @throws ProviderNotFoundException the provider not found exception
	 */
	public OfficeSpace addOfficeSpaceToProvider(String authToken, String providerId, 
			OfficeSpace officeSpace) throws ProviderNotFoundException {
		Provider providerObj = getProvider(providerId); 
		providerObj.addOfficeSpaceToList(officeSpace); 
		return officeSpace;
	}

	/**
	 * Removes the office space from provider.
	 *
	 * @param authToken the auth token
	 * @param providerId the provider id
	 * @param officeSpaceId the office space id
	 * @throws ProviderNotFoundException the provider not found exception
	 * @throws OfficeSpaceNotFoundException the office space not found exception
	 */
	public void  removeOfficeSpaceFromProvider(String authToken, String providerId, 
			String officeSpaceId) throws ProviderNotFoundException, OfficeSpaceNotFoundException {
		Provider providerObj = getProvider(providerId); 
		providerObj.removeOfficeSpaceFromList(officeSpaceId); 

	}

	/**
	 * Gets the office space list for provider.
	 *
	 * @param authToken the auth token
	 * @param providerId the provider id
	 * @return the office space list for provider
	 * @throws ProviderNotFoundException the provider not found exception
	 */
	public Collection<OfficeSpace> getOfficeSpaceListForProvider (String authToken, String providerId) 
			throws ProviderNotFoundException {
		Provider providerObj = getProvider(providerId); 
		return providerObj.getOfficeSpaces(); 	
	}

	/**
	 * Instantiates a new provider service.
	 */
	public ProviderService() {
	}

}
