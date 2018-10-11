import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		
		Scanner keyboard = new Scanner(System.in);
		
		int list[] = new int[5];
		
		for (int i = 0; i < 5; ++i) {
			list[i] = Integer.parseInt(keyboard.nextLine());
		}
		
		int total = 0;
		
		for (int j = 0; j < 5; ++j) {
			if (list[j] < 40) total += 40;
			else total += list[j];
		}
		
		System.out.println(total/5);
		
	}
}
