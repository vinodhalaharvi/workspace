package cscie97.asn3.squaredesk.renter;
import java.util.Date;
import java.util.HashSet;

/**
 * The Class BookingService.
 *
 * @author Vinod Halaharvi
 */
public class BookingService {

	/** The booking service. */
	private static BookingService bookingService;  
	/** The bookings. */
	private static HashSet<Booking> bookings = new HashSet<Booking>();


	public static HashSet<Booking> getBookings() {
		return bookings;
	}


	public static void setBookings(HashSet<Booking> bookings) {
		BookingService.bookings = bookings;
	}


	/**
	 * Gets the single instance of BookingService.
	 *
	 * @return single instance of BookingService
	 */
	public static BookingService getInstance() {
		if (bookingService == null){
			bookingService = new BookingService();
			return bookingService;
		} else {
			return bookingService;
		}
	}


	public Booking createBooking(Renter renter, 
			OfficeSpace officeSpace, String period, Rate rate, Date startDate, Date endDate, 
			String paymentStatus, String bookingId
			) throws BookingAlreadyExistException, AccessException{ 
		Booking bookingObj = new Booking(renter, officeSpace, period, rate, startDate, endDate, paymentStatus);
		if (bookings.contains(bookingObj)){
			throw new BookingAlreadyExistException("This Booking Already Exists");
		} else {
			bookings.add(bookingObj);
		}
		return bookingObj;
	}

	
	public boolean checkAvailability(OfficeSpace officeSpace, Date startDate, Date endDate){
		//for all bookings
		//check if that office space is present
		//if those dates are already taken then error 
		//else book
		for (Booking booking : getBookings()){
			OfficeSpace thisOfficeSpace = booking.getOfficeSpace(); 
			if (thisOfficeSpace.equals(officeSpace)){
				if ((startDate.before(booking.getEndDate()) && endDate.after(booking.getEndDate())) || 
						(startDate.before(booking.getStartDate())  && endDate.before(booking.getEndDate()))){
					return true;
				}
			}
		}
		return false; 
	}
	
	public void removeBooking(Booking booking){
		bookings.remove(booking);
	}
	
	public void listBookings(){
		for(Booking booking : bookings){
			System.out.println(booking);
		}
	}

	/**
	 * Instantiates a new booking service.
	 */
	public BookingService() {
	}

}
