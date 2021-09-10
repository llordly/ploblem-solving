import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		
		Scanner keyboard = new Scanner(System.in);
		
		int multi = 1;
		
		for (int i = 0; i < 3; ++i) {
			multi *= Integer.parseInt(keyboard.nextLine());
		}
		
		String num = String.valueOf(multi);
		
		int list[] = new int[10];
		
		for (int j = 0; j < 10; ++j) {
			list[j] = 0;
		}
		
		for (int k = 0; k < 10; ++k) {
			for (int l = 0; l < num.length(); ++l){
				if (k == num.charAt(l) - '0') list[k]++;
			}
		}
		
		for (int i = 0; i < 10; ++i) {
			System.out.println(list[i]);
		}
		
	}
}
