import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner keyboard = new Scanner(System.in);

		String line = keyboard.nextLine().toUpperCase();
		
		studyWord[] list = new studyWord[26];
		
		char a = 'A';
		
		for (int i = 0; i < 26; ++i) {
			list[i] = new studyWord(0, a++);
		}
		
		for (int j = 0; j < line.length(); ++j) {
			for (int k = 0; k < 26; ++k) {
				if (line.charAt(j) == list[k].getAlphabet()) {
					list[k].increaseCount();
				}
			}
		}
		
		Arrays.sort(list);
		
		if (list[25].getCount() == list[24].getCount()) System.out.println("?");
		else
			System.out.println(list[25].getAlphabet());
		
	}
}

class studyWord implements Comparable<studyWord>{
	private int count;
	private char alphabet;
	
	public studyWord(int count, char alphabet) {
		this.count = count;
		this.alphabet = alphabet;
	}
	public int getCount() {
		return count;
	}
	public void increaseCount() {
		this.count++;
	}
	public char getAlphabet() {
		return alphabet;
	}
	
	@Override
	public int compareTo(studyWord o) {
		// TODO Auto-generated method stub
		if (this.count > o.count) return 1;
		else if (this.count < o.count) return -1;
		else return 0;
	}
	
}

