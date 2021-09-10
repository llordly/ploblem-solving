import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		
		Scanner keyboard = new Scanner(System.in);
		
		String line = keyboard.nextLine();
		
		int num = Integer.parseInt(line);
		
		if (num > 1000 || num < 1)
			System.exit(0);
	
		int count = 0;
		
		for (int i = 1; i <= num; ++i) {
			if (sequence(i)) count++;
		}
		System.out.println(count);
	}
	
	static boolean sequence(int num) {
		
		String a = String.valueOf(num);
		int sub = 0;
		int diff = 0;
		if (a.length() == 1 || a.length() == 2)
			return true;
		else {
			diff = a.charAt(0) - a.charAt(1);
		}
		
		
		for (int i = 1; i < a.length()-1; ++i) {
			int first = a.charAt(i) - '0';
			int second = a.charAt(i+1) - '0';
			
			sub = first - second;
			
			if (sub != diff) return false;
		}
		return true;		
	}
}
