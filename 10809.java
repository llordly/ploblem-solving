import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner keyboard = new Scanner(System.in);

		String word = keyboard.nextLine();

		char list[] = new char[26];
		char alphabet = 'a';
		int result[] = new int[26];

		for (int i = 0; i < 26; ++i) {
			list[i] = alphabet++;
			result[i] = -1;
		}

		for (int i = 0; i < word.length(); ++i) {
			for (int j = 0; j < 26; ++j) {
				if (word.charAt(i) == list[j]) {
					result[j] = word.indexOf(word.charAt(i));
				}
			}
		}

		for (int i = 0; i < result.length; ++i) {
			System.out.print(result[i]);
			if (i == result.length - 1)
				break;
			System.out.print(" ");
		}

	}
}
