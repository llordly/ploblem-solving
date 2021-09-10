import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner keyboard = new Scanner(System.in);
		
		int num = Integer.parseInt(keyboard.nextLine());
		
		int count = 1;
		
		String fraction;
		int row = 1;
		int col = 1;
		
		while (count != num) {			
			if (row == 1) {
				count++;
				col++;
				if (count == num) break;
				while (col != 1) {
					row++;
					col--;
					count++;
					if (count == num) break;
				}
			}
			else if (col == 1) {
				count++;
				row++;
				if (count == num) break;
				while (row != 1) {
					row--;
					col++;
					count++;
					if (count == num) break;
				}
			}
		}
		fraction = row + "/" + col;
		System.out.println(fraction);
	}
}
