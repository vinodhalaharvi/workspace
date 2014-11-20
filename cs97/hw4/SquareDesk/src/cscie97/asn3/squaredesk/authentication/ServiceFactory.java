/*
 * 
 */
package cscie97.asn3.squaredesk.authentication;


// TODO: Auto-generated Javadoc
/**
 * A factory for creating Service objects.
 */
public final class ServiceFactory {

	/**
	 * Instantiates a new service factory.
	 */
	public ServiceFactory() {
	}
	
	/**
	 * Creates a new Service object.
	 *
	 * @param serviceName the service name
	 * @param loginName the login name
	 * @param password the password
	 * @param uuidName the uuid name
	 * @param serviceDescription 
	 * @return the service
	 */
	public static Service createService( String serviceId, String serviceName,
			String serviceDescription ) {
		Service serviceObj = new Service(serviceId, serviceName, serviceDescription);
		return serviceObj; 
	}

}
