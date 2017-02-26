import java.util.Locale;
import java.util.HashMap;
import java.util.Map;
import java.util.Date;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Scanner;

public class Booking {
	public static void main(String[] args) {
		readData();
	 	System.out.println(System.getProperty("java.class.path"));
		System.out.println("Jello mello from Java.");
	}

	private static void readData() {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();

		for(int i = 0; i < T; i++) {
			int B = scanner.nextInt();
			cleaningTime = scanner.nextInt();

			// for(int j = 0; j < B; j++) {
				String dates = scanner.next();
				System.out.println(dates);
				// DateFormat format = new SimpleDateFormat(
				// 	"yyyy-mm-dd HH:mm"
				// 	Locale.ENGLISH
				// );
				// Date date = format.parse();
			// }
		}

		scanner.close();
	}

	private static Map< String, Date > bookings = new HashMap<>();
	private static int cleaningTime;
}