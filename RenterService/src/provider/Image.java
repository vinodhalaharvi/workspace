/**
 * 
 */
package provider;

import java.net.URI;

/**
 * The Class Image.
 */
public class Image {
	
	/** The name. */
	private String name; 
	
	/** The description. */
	private String description; 
	
	/** The uri. */
	private URI uri; 
	
	/**
	 * Instantiates a new image.
	 *
	 * @param name the name
	 * @param description the description
	 * @param uri the uri
	 */
	public Image(String name, String description, URI uri) {
		super();
		this.name = name;
		this.description = description;
		this.uri = uri;
	}

	
	/**
	 * Instantiates a new image.
	 *
	 * @param name the name
	 * @param uri the uri
	 */
	public Image(String name, URI uri) {
		super();
		this.name = name;
		this.uri = uri;
	}

	
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
	
	/**
	 * Gets the description.
	 *
	 * @return the description
	 */
	public String getDescription() {
		return description;
	}
	
	/**
	 * Sets the description.
	 *
	 * @param description
	 *            the new description
	 */
	public void setDescription(String description) {
		this.description = description;
	}
	
	/**
	 * Gets the uri.
	 *
	 * @return the uri
	 */
	public URI getURI() {
		return uri;
	}
	
	/**
	 * Sets the uri.
	 *
	 * @param uri
	 *            the new uri
	 */
	public void setURI(URI uri) {
		this.uri = uri;
	}

	
}
