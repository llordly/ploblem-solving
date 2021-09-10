import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		
		Scanner keyboard = new Scanner(System.in);
		
		String line = keyboard.nextLine();
		
		StringTokenizer st = new StringTokenizer(line);
		
		int count = st.countTokens();
		System.out.println(count);
	}
}
