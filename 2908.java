import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {

		Scanner keyboard = new Scanner(System.in);

		StringTokenizer st = new StringTokenizer(keyboard.nextLine());
		
		String a = st.nextToken();
		String b = st.nextToken();
		
		String c = "";
		String d = "";
		
		for (int i = 2; i >= 0; --i) {
			c += a.charAt(i);
			d += b.charAt(i);
		}
		
		int num1 = Integer.parseInt(c);
		int num2 = Integer.parseInt(d);
		
		System.out.println(num1 > num2 ? num1 : num2);
	}
	

}
