import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		int a = keyboard.nextInt();
	
		if (a < 3 || a > 5000)
			System.exit(0);
		int three_d = a/3;
		int three_q = a%3;
		int five_d = a/5;
		int five_q = a%5;
		
		
		int temp = 5000;
		boolean result = false;
		
		for (int i = 0; i <= three_d; ++i) {
			for (int j = 0; j <= five_d; ++j) {
				if(3*i + 5*j == a && i + j <= temp) {
					temp = i + j;
					result = true;
				}
			}
		}
		
		if (result)
			System.out.println(temp);
		else
			System.out.println(-1);
		
		
		
		
	}
}
