package cscie97.asn3.squaredesk.renter;

import java.util.Date;
import java.util.Map;
import java.util.UUID;

public class SchedulingService {
	private Map<String, Booking> bookings; 

	public SchedulingService() {
		// TODO Auto-generated constructor stub
	}

	public void createBooking(Renter renter, OfficeSpace officeSpace, String period,
			Rate rate, Date startDate, Date endDate, String paymentStatus ) {
		new Booking(renter, officeSpace, period, 
				rate, startDate, endDate, paymentStatus); 
	}
	
	public void checkAvailability(Date startDate, Date endDate) {
		
	}
	
	/**
	 * Gets the uuid.
	 *
	 * @return the uuid
	 */
	private String getUUID() {
		String uuidStr = UUID.randomUUID().toString(); 
		return uuidStr; 	
	}
	
	
	/**
	 * Adds the booking to list.
	 *
	 * @param booking the booking
	 * @return the booking
	 */
	public Booking addBookingToList(Booking booking) {
		String bookingId = getUUID(); 
		booking.setBookingId(bookingId); 
		bookings.put(bookingId, booking);
		return booking; 
	}

	/**
	 * Gets the bookingfrom list.
	 *
	 * @param bookingId the booking id
	 * @return the bookingfrom list
	 * @throws BookingNotFoundException the booking not found exception
	 */
	public Booking getBookingfromList(String bookingId) 
			throws BookingNotFoundException {
		if (!bookings.containsKey(bookingId)){ 
			throw new BookingNotFoundException("Booking not found!"); 
		} else { 
			return bookings.get(bookingId); 
		}		
	}

	/**
	 * Removes the bookingfrom list.
	 *
	 * @param bookingId the booking id
	 * @throws BookingNotFoundException the booking not found exception
	 */
	public void removeBookingfromList(String bookingId) 
			throws BookingNotFoundException {
		if (!bookings.containsKey(bookingId)){ 
			throw new BookingNotFoundException("Booking not found!"); 
		} else { 
			bookings.remove(bookingId); 
		}		
	}

	
	
}
