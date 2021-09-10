import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);

		String n = keyboard.nextLine();

		if (Integer.parseInt(n) < 0 || Integer.parseInt(n) > 99)
			System.exit(0);

		String result = n;
		int cnt = 0;
		int temp = 0;

		if (result.length() == 1) {
			n = "0" + n;
			result = result + result;
			cnt++;
			if (result.equals(n)) {
				System.out.println(cnt);
				System.exit(0);
			}
		}
		while (result.length() == 2) {
			temp = (result.charAt(0) - '0') + (result.charAt(1) - '0');
			if (temp > 9)
				result = result.substring(1) + Integer.toString(temp).substring(1);
			else
				result = result.substring(1) + Integer.toString(temp);
			if (result.equals(n)) {
				cnt++;
				System.out.println(cnt);
				break;
			} else {
				cnt++;
			}
		}

	}
}
