/*
 * 
 */
package cscie97.asn3.squaredesk.renter;

import java.util.Date;

import cscie97.asn3.squaredesk.provider.OfficeSpace;
import cscie97.asn3.squaredesk.provider.Rate;

/**
 * The Class Booking.
 */
public class Booking {
	
	/**
	 * Gets the renter.
	 *
	 * @return the renter
	 */
	public Renter getRenter() {
		return renter;
	}

	/**
	 * Sets the renter.
	 *
	 * @param renter
	 *            the new renter
	 */
	public void setRenter(Renter renter) {
		this.renter = renter;
	}

	/**
	 * Gets the office space.
	 *
	 * @return the office space
	 */
	public OfficeSpace getOfficeSpace() {
		return officeSpace;
	}
	
	
	/* (non-Javadoc)
	 * @see java.lang.Object#equals(java.lang.Object)
	 */
	@Override
	public boolean equals(Object obj) {
		Booking t = (Booking) obj; 
		return (
				(obj != null) &&
				(obj instanceof Booking) &&
				t.getOfficeSpace().getOffId().equals(officeSpace.getOffId()) &&
				t.getRenter().getRenterId().equals(renter.getRenterId())
				);
				
	}
	
	/* (non-Javadoc)
	 * @see java.lang.Object#hashCode()
	 */
	@Override
	public int hashCode() {
		return renter.hashCode() + officeSpace.hashCode();  
	}
	
	
	/**
	 * Sets the office space.
	 *
	 * @param officeSpace
	 *            the new office space
	 */
	public void setOfficeSpace(OfficeSpace officeSpace) {
		this.officeSpace = officeSpace;
	}

	/**
	 * Gets the period.
	 *
	 * @return the period
	 */
	public String getPeriod() {
		return period;
	}

	/**
	 * Sets the period.
	 *
	 * @param period
	 *            the new period
	 */
	public void setPeriod(String period) {
		this.period = period;
	}

	/**
	 * Gets the rate.
	 *
	 * @return the rate
	 */
	public Rate getRate() {
		return rate;
	}

	/**
	 * Sets the rate.
	 *
	 * @param rate
	 *            the new rate
	 */
	public void setRate(Rate rate) {
		this.rate = rate;
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
	 * Gets the payment status.
	 *
	 * @return the payment status
	 */
	public String getPaymentStatus() {
		return paymentStatus;
	}

	/**
	 * Sets the payment status.
	 *
	 * @param paymentStatus
	 *            the new payment status
	 */
	public void setPaymentStatus(String paymentStatus) {
		this.paymentStatus = paymentStatus;
	}

	public Booking(String bookingId, Renter renter, OfficeSpace officeSpace, String period,
			Rate rate, Date startDate, Date endDate, String paymentStatus) {
		this.bookingId = bookingId; 
		this.renter = renter;
		this.officeSpace = officeSpace;
		this.period = period;
		this.rate = rate;
		this.startDate = startDate;
		this.endDate = endDate;
		this.paymentStatus = paymentStatus;
	}

	/** The renter. */
	private Renter renter; 
	
	/** The office space. */
	private OfficeSpace officeSpace; 
	
	/** The period. */
	private String period; 
	
	/** The rate. */
	private Rate rate; 
	
	/** The start date. */
	private Date startDate; 
	
	/** The end date. */
	private Date endDate;
	
	/** The payment status. */
	private String paymentStatus;
	
	/** The booking id. */
	private String bookingId;
	
	
	/**
	 * Gets the booking id.
	 *
	 * @return the booking id
	 */
	public String getBookingId() {
		return bookingId;
	}

	/**
	 * Sets the booking id.
	 *
	 * @param bookingId
	 *            the new booking id
	 */
	public void setBookingId(String bookingId) {
		this.bookingId = bookingId;
	} 
}
