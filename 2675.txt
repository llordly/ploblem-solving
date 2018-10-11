import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {

		Scanner keyboard = new Scanner(System.in);

		int n = Integer.parseInt(keyboard.nextLine());
		
		StringTokenizer st;
		
		ArrayList<wordRepeat> list = new ArrayList<wordRepeat>();
		
		for (int i = 0; i < n; ++i) {
			st = new StringTokenizer(keyboard.nextLine());
			wordRepeat a = new wordRepeat(Integer.parseInt(st.nextToken()), st.nextToken());
			list.add(a);
		}
		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < list.get(i).getWord().length(); ++j) {
				for (int k = 0; k < list.get(i).getCount(); ++k) {
					System.out.print(list.get(i).getWord().charAt(j));
				}
			}
			System.out.println();
		}
	}
}

class wordRepeat{
	private int count;
	private String word;
	
	wordRepeat(int count, String word){
		this.count = count;
		this.word = word;
	}
	public int getCount() {
		return count;
	}
	public String getWord() {
		return word;
	}
}