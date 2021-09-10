import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner keyboard = new Scanner(System.in);

		char ascii = keyboard.nextLine().charAt(0);
		
		System.out.println((int) ascii);
	}
}
