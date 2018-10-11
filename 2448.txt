import java.util.Scanner;

public class Main {
	static char[][] str = null;
	public static void main(String[] args) {
		
		Scanner keyboard = new Scanner(System.in);
		
		int n = Integer.parseInt(keyboard.nextLine());
		
		str = new char[n][2 * n-1];
		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 2 * n-1; ++j) {
				str[i][j] = ' ';
			}
		}
		
		printStar(0, n-1, n);
		
		for (int i = 0; i < n; ++i) {
			System.out.println(str[i]);
		}
		
	}
	
	
	
	public static void printStar(int x, int y, int n) {
		if (n == 3) {
			str[x][y] = '*';
			str[x+1][y-1] = str[x+1][y+1] = '*';
			str[x+2][y-2] = str[x+2][y-1] = str[x+2][y] = str[x+2][y+1] = str[x+2][y+2] = '*';
			return;
		}
		
		printStar(x, y, n/2);
		printStar(x + n/2, y - n/2, n/2);
		printStar(x + n/2, y + n/2, n/2);
	}
}
