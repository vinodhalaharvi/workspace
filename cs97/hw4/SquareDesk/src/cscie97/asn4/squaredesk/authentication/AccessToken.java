/*
 * 
 */
package cscie97.asn4.squaredesk.authentication;

import java.util.Date;

/**
 * The Class AccessToken.
 */
public class AccessToken {

	/**
	 * Instantiates a new access token.
	 *
	 * @param accessTokenId the access token id
	 * @param expirationTime the expiration time
	 * @param state the state
	 */
	public AccessToken(String accessTokenId, Date expirationTime, String state) {
		super();
		this.accessTokenId = accessTokenId;
		this.expirationTime = expirationTime;
		this.state = state;
	}

	/**
	 * Gets the access token id.
	 *
	 * @return the access token id
	 */
	public String getAccessTokenId() {
		return accessTokenId;
	}

	/**
	 * Sets the access token id.
	 *
	 * @param accessTokenId the new access token id
	 */
	public void setAccessTokenId(String accessTokenId) {
		this.accessTokenId = accessTokenId;
	}

	/**
	 * Gets the expiration time.
	 *
	 * @return the expiration time
	 */
	public Date getExpirationTime() {
		return expirationTime;
	}

	/**
	 * Sets the expiration time.
	 *
	 * @param expirationTime the new expiration time
	 */
	public void setExpirationTime(Date expirationTime) {
		this.expirationTime = expirationTime;
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
	 * @param state the new state
	 */
	public void setState(String state) {
		this.state = state;
	}


	/* (non-Javadoc)
	 * @see java.lang.Object#equals(java.lang.Object)
	 */
	@Override
	public boolean equals(Object obj) {
		AccessToken t = (AccessToken) obj; 
		return (
				(obj != null) &&
				(obj instanceof AccessToken) &&
				t.getAccessTokenId().equals(getAccessTokenId()));				
	}

	/* (non-Javadoc)
	 * @see java.lang.Object#hashCode()
	 */
	@Override
	public int hashCode() {
		return accessTokenId.hashCode();
	}

	/** The access token id. */
	private String accessTokenId;

	/** The expiration time. */
	private Date expirationTime; 

	/** The state. */
	private String state;

}
