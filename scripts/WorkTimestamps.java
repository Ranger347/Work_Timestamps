package scripts;
import java.util.Scanner;


public class WorkTimestamps {

	public static int findTime(String[] times) {

		try {
			
			int[] startTime = new int[]{Integer.parseInt(times[0].substring(0, 2)), Integer.parseInt(times[0].substring(2))};
			int[] endTime = new int[]{Integer.parseInt(times[1].substring(0, 2)), Integer.parseInt(times[1].substring(2))};
			// System.out.println(startTime[0] + " " + startTime[1]);
			// System.out.println(endTime[0] + " " + endTime[1]);
				
			// (end_hours * 60 + end_minutes) - (start_hours * 60 + start_minutes)
			return (endTime[0] * 60 + endTime[1]) - (startTime[0] * 60 + startTime[1]);
		} catch (Exception e) {
			return 0;
		}
	}

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);

		System.out.println("""
		This program takes in times for each day and outputs the amount of time worked throughout the week
		If you did not work on that day, do not input anything.
		Please enter times in military time in the format TTTT-TTTT
		""");

		// Input times for the week from the user
		System.out.println("Sunday Times: ");
		int sundayTimes = findTime(scan.nextLine().split("-"));
		System.out.println("Monday Times: ");
		int mondayTimes = findTime(scan.nextLine().split("-"));
		System.out.println("Tuesday Times: ");
		int tuesdayTimes = findTime(scan.nextLine().split("-"));
		System.out.println("Wednesday Times: ");
		int wednesdayTimes = findTime(scan.nextLine().split("-"));
		System.out.println("Thursday Times: ");
		int thursdayTimes = findTime(scan.nextLine().split("-"));
		System.out.println("Friday Times: ");
		int fridayTimes = findTime(scan.nextLine().split("-"));
		System.out.println("Saturday Times: ");
		int saturdayTimes = findTime(scan.nextLine().split("-"));

		int sum = 0;
		sum += sundayTimes;
		sum += mondayTimes;
		sum += tuesdayTimes;
		sum += wednesdayTimes;
		sum += thursdayTimes;
		sum += fridayTimes;
		sum += saturdayTimes;

		System.out.println(sundayTimes + " + " + mondayTimes + " + " + tuesdayTimes + " + " + wednesdayTimes + " + " + thursdayTimes + " + " + fridayTimes + " + " + saturdayTimes + " = " + sum);

		int hours = sum / 60;
		int minutes = sum % 60;

		System.out.println(hours + " hours and " + minutes + " minutes");

		// Add Wage functionality
		try {
			System.out.println("How much are you paid per hour?");
			double wage = Double.parseDouble(scan.nextLine());
			double total = wage * hours + wage * ((double) minutes / 60);

			System.out.println("Your resulting amount is: $" + total);
		} catch (Exception e) {
			// do nothing
		}

		scan.close();

	}
    
}