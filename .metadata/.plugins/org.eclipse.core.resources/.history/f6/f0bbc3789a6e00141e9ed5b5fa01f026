/*
 * 
 */
package cscie97.asn3.squaredesk.renter;
import java.util.Date;
import java.util.HashSet;
import java.util.UUID;

import cscie97.asn3.squaredesk.provider.AccessException;
import cscie97.asn3.squaredesk.provider.OfficeSpace;
import cscie97.asn3.squaredesk.provider.Rate;

/**
 * The Class BookingService.
 */
public final class BookingService {

	/** The bookings. */
	private static HashSet<Booking> bookings = new HashSet<Booking>();


	/**
	 * Gets the bookings.
	 *
	 * @return the bookings
	 */
	public static HashSet<Booking> getBookings() {
		return bookings;
	}


	/**
	 * Sets the bookings.
	 *
	 * @param bookings
	 *            the new bookings
	 */
	public static void setBookings(HashSet<Booking> bookings) {
		BookingService.bookings = bookings;
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


	public static Booking createBooking(Renter renter, 
			OfficeSpace officeSpace, String period, Rate rate, Date startDate, Date endDate, 
			String paymentStatus) throws BookingAlreadyExistException, AccessException{
		String bookingId = getUUIDFromString(renter.getRenterId() + officeSpace.getOffId()); 
		Booking bookingObj = new Booking(bookingId, renter, officeSpace, period, rate, startDate, endDate, paymentStatus);
		if (bookings.contains(bookingObj)){
			throw new BookingAlreadyExistException("This Booking Already Exists");
		} else {
			bookings.add(bookingObj);
		}
		return bookingObj;
	}

	
	public static boolean checkAvailability(OfficeSpace officeSpace, Date startDate, Date endDate){
		for (Booking booking : getBookings()){
			OfficeSpace thisOfficeSpace = booking.getOfficeSpace(); 
			if (thisOfficeSpace.equals(officeSpace)){
				if ((startDate.before(booking.getEndDate()) && endDate.after(booking.getEndDate())) || 
						(startDate.before(booking.getStartDate())  && endDate.before(booking.getEndDate()))){
					return false;
				}
			}
		}
		return true; 
	}
	
	public static void removeBooking(Booking booking){
		bookings.remove(booking);
	}
	
	public static void listBookings(){
		for(Booking booking : bookings){
			System.out.println(booking);
		}
	}

	/**
	 * Instantiates a new booking service.
	 */
	private BookingService() {
	}

}
