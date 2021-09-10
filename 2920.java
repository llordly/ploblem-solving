import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		
		Scanner keyboard = new Scanner(System.in);
		
		String line = keyboard.nextLine();
		
		StringTokenizer st = new StringTokenizer(line);
		
		int list[] = new int[8];
		
		for (int i = 0; i < 8; ++i) {
			list[i] = Integer.parseInt(st.nextToken());
		}
		
		boolean asc = true;
		boolean dsc = true;
		
		for (int j = 0 ; j < 7; ++j) {
			if (list[j] - list[j+1] < 0) {
				dsc = false;
			}
			else if (list[j] - list[j+1] > 0) {
				asc = false;
			}		
		}
		
		if(asc) System.out.println("ascending");
		else if(dsc) System.out.println("descending");
		else if (!asc && !dsc) System.out.println("mixed");
		
	}
}
