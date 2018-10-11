import java.util.HashMap;

import java.util.Scanner;


public class Main {
	public static void main(String[] args) {

		Scanner keyboard = new Scanner(System.in);
		
		String word = keyboard.nextLine();
		
		int totalTime = 0;
		
		HashMap<Character, Integer> map = new HashMap<Character, Integer>();
		
		char a = 'A';
		int repeat = 3;
		int time = 3;
		
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < repeat; ++j) {
				map.put(a++, time);
			}
			time++;
			if (time == 8) repeat++;
			else if (time == 9) repeat--;
			else if (time == 10) repeat++;
		}
		
		for (int i = 0; i < word.length(); ++i) {
			if (map.containsKey(word.charAt(i)))
				totalTime += map.get(word.charAt(i));
		}
		System.out.println(totalTime);
	}
	

}
