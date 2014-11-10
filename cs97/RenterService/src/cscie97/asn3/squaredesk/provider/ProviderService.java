/*
 * 
 */
package cscie97.asn3.squaredesk.provider;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

import cscie97.asn3.squaredesk.renter.ProfileFactory;
import cscie97.asn3.squaredesk.renter.RenterAlreadyExistException;

/**
 * The Class ProviderService.
 */
public final class ProviderService {

	/**
	 * Gets the office spaces.
	 *
	 * @return the office spaces
	 */
	public static Collection<OfficeSpace> getOfficeSpaces() {
		return officeSpaces.values();
	}

	/**
	 * Sets the office spaces.
	 *
	 * @param officeSpaces
	 *            the new office spaces
	 */
	public static void setOfficeSpaces(Map<String, OfficeSpace> officeSpaces) {
		ProviderService.officeSpaces = officeSpaces;
	}

	/**
	 * Gets the feature.
	 *
	 * @param name the name
	 * @return the feature
	 */
	public static Feature getFeature(String name) {
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
	public static Category getCategory(String name) {
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
	public static FacilityType getFacilityType(String type) {
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
	 * Gets the UUID from string.
	 *
	 * @param name the name
	 * @return the UUID from string
	 */
	protected static String getUUIDFromString(String name) {
		String uuidStr = UUID.nameUUIDFromBytes(name.getBytes()).toString(); 
		return uuidStr; 	
	}


	/**
	 * Creates the provider.
	 *
	 * @param authToken
	 *            the auth token
	 * @param name
	 *            the name
	 * @param contactInfo
	 *            the contact info
	 * @param picture
	 *            the picture
	 * @return the provider
	 * @throws ProviderAlreadyExistException
	 *             the provider already exist exception
	 * @throws AccessException
	 *             the access exception
	 * @throws RenterAlreadyExistException 
	 * @throws ProfileAlreadyExistsException 
	 */
	public static Provider createProvider(String authToken, String name, 
			ContactInfo contactInfo, Image picture
			) throws ProviderAlreadyExistException, AccessException{ 
		String uuidName = getUUIDFromString(name); 
		if (providers.containsKey(uuidName)){
			throw new ProviderAlreadyExistException("This Provider Already Exists");
		} else {
			Provider providerObj = (Provider) ProfileFactory.createProfile("provider", 
					name, contactInfo, picture, uuidName); 
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
	public static Provider getProvider(String authToken, String providerId) 
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
	public static Collection<Provider> getProviderList(String authToken)
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
	private static Provider getProvider(String providerId) 
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
	public static Provider updateProviderName(String authToken, String providerId, String name) 
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
	public static Provider updateProviderContactInfo(String authToken, String providerId, 
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
	public static Provider updateProviderPicture(String authToken, String providerId, 
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
	public static void deleteProvider(String authToken, String providerId) 
			throws ProviderNotFoundException, AccessException{
		Provider provider = getProvider(providerId); 
		//first remove all office space mappings
		for(OfficeSpace officeSpace : provider.getOfficeSpaces()){
			officeSpaces.remove(officeSpace.getOffId());
		}
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
	public static Rating addRatingToProvider(String authToken, String providerId, Rating rating)
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
	public static void removeRatingFromProvider(String authToken, String providerId, String ratingId) 
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
	public static Collection<Rating> getRatingListForProvider(String authToken, String providerId)
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
	public static OfficeSpace addOfficeSpaceToProvider(String authToken, String providerId, 
			OfficeSpace officeSpace) throws ProviderNotFoundException {
		Provider providerObj = getProvider(providerId); 
		providerObj.addOfficeSpaceToList(officeSpace); 
		System.out.println("ADDING office space ");
		System.out.println(officeSpace.getOffId());
		officeSpaces.put(officeSpace.getOffId(), officeSpace); 
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
	public static void  removeOfficeSpaceFromProvider(String authToken, String providerId, 
			String officeSpaceId) throws ProviderNotFoundException, OfficeSpaceNotFoundException {
		Provider providerObj = getProvider(providerId); 
		providerObj.removeOfficeSpaceFromList(officeSpaceId);
		officeSpaces.remove(officeSpaceId);
	}

	/**
	 * Gets the office space list for provider.
	 *
	 * @param authToken the auth token
	 * @param providerId the provider id
	 * @return the office space list for provider
	 * @throws ProviderNotFoundException the provider not found exception
	 */
	public static Collection<OfficeSpace> getOfficeSpaceListForProvider(String authToken, String providerId) 
			throws ProviderNotFoundException {
		Provider providerObj = getProvider(providerId); 
		return providerObj.getOfficeSpaces(); 	
	}


	public static OfficeSpace getOfficeSpace(String offId){
		return officeSpaces.get(offId); 
	}

	/** The features. */
	private static Map<String, Feature> features = new HashMap<String, Feature>();

	/** The facility types. */
	private static Map<String, FacilityType> facilityTypes = new HashMap<String, FacilityType>();

	/** The categories. */
	private static Map<String, Category> categories = new HashMap<String, Category>();

	/** The providers. */
	private static Map<String, Provider> providers = new HashMap<String, Provider>();

	/** The office spaces. */
	private static Map<String, OfficeSpace> officeSpaces = new HashMap<String, OfficeSpace>();

	/**
	 * Instantiates a new provider service.
	 */
	private ProviderService() {
	}

}