package cscie97.asn3.squaredesk.renter;

import java.util.Collection;
import java.util.Date;

/**
 * @author vinodhalaharvi
 *
 */
public class Booking {
	
	public Renter getRenter() {
		return renter;
	}

	public void setRenter(Renter renter) {
		this.renter = renter;
	}

	public OfficeSpace getOfficeSpace() {
		return officeSpace;
	}

	
	
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
	
	@Override
	public int hashCode() {
		return renter.hashCode() + officeSpace.hashCode();  
	}
	
	
	public void setOfficeSpace(OfficeSpace officeSpace) {
		this.officeSpace = officeSpace;
	}

	public String getPeriod() {
		return period;
	}

	public void setPeriod(String period) {
		this.period = period;
	}

	public Rate getRate() {
		return rate;
	}

	public void setRate(Rate rate) {
		this.rate = rate;
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

	public String getPaymentStatus() {
		return paymentStatus;
	}

	public void setPaymentStatus(String paymentStatus) {
		this.paymentStatus = paymentStatus;
	}

	public Booking(Renter renter, OfficeSpace officeSpace, String period,
			Rate rate, Date startDate, Date endDate, String paymentStatus) {
		this.renter = renter;
		this.officeSpace = officeSpace;
		this.period = period;
		this.rate = rate;
		this.startDate = startDate;
		this.endDate = endDate;
		this.paymentStatus = paymentStatus;
	}

	private Renter renter; 
	private OfficeSpace officeSpace; 
	private String period; 
	private Rate rate; 
	private Date startDate; 
	private Date endDate;
	private String paymentStatus;
	private String bookingId;
	public String getBookingId() {
		return bookingId;
	}

	public void setBookingId(String bookingId) {
		this.bookingId = bookingId;
	} 
	
	public void createBooking(String authToken, Renter renter, Collection<OfficeSpace> officeSpaces, Criteria criteria){
		return; 
	}
	
	public void checkAvailability(OfficeSpace officeSpace, Date startDate, Date endDate){
		
	}
	
	public void deleteBooking(String bookingId){
		
	}
	
	public Collection<Booking> listBookings(){
		return null;
	}
	

}
