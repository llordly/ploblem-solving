import java.util.Scanner;


public class Main {
	public static void main(String[] args) {

		Scanner keyboard = new Scanner(System.in);
		
		String word = keyboard.nextLine();
		
		String[] list = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
		int count = 0;
		for (int i = 0; i < list.length; ++i) {
			if (word.contains(list[i])) {
				count += countString(word, list[i]);
				word = word.replace(list[i], " ");
			}
		}
		word = word.replace(" ", "");
		if(!word.equals("")) count += word.length();
		
		System.out.println(count);
	}
	
	static int countString(String str, String word) {
		int count = 0;
		int fromIndex = 0;
		while ((fromIndex = str.indexOf(word, fromIndex)) >= 0){
			count++;
			fromIndex += word.length();
		}
		
		return count;
	}
	

}
