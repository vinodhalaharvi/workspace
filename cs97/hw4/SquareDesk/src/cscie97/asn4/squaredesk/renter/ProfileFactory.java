/*
 * 
 */
package cscie97.asn4.squaredesk.renter;

import cscie97.asn4.squaredesk.provider.ContactInfo;
import cscie97.asn4.squaredesk.provider.Image;
import cscie97.asn4.squaredesk.provider.Provider;

/**
 * A factory for creating Profile objects.
 */
public final class ProfileFactory {

	/**
	 * Instantiates a new profile factory.
	 */
	public ProfileFactory() {
	}
	
	/**
	 * Creates a new Profile object.
	 *
	 * @param profile
	 *            the profile
	 * @param name
	 *            the name
	 * @param contactInfo
	 *            the contact info
	 * @param picture
	 *            the picture
	 * @param uuidName
	 *            the uuid name
	 * @return the profile
	 */
	public static Profile createProfile(String profile, String name, 
			ContactInfo contactInfo, Image picture, String uuidName
			) {
		if (profile.equals("renter")){
			Renter renterObj = new Renter(name, contactInfo, picture);
			renterObj.setRenterId(uuidName); 
			return renterObj; 
		} else {
			Provider providerObj = new Provider(name, contactInfo, picture);
			providerObj.setProviderId(uuidName); 
			return providerObj; 
		}
	}

}
