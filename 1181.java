
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());
		
		WordSorting list[] = new WordSorting[N];
		
		for (int i = 0; i < N; ++i) {
			WordSorting a = new WordSorting(br.readLine());
			list[i] = a;
		}
		
		Arrays.sort(list);
		
		ArrayList<String> result = new ArrayList<String>();
		
		for (int i = 0; i < N; ++i) {
			if(!result.contains(list[i].getWord())) {
				result.add(list[i].getWord());
			}
		}
		
		for (int j = 0; j < result.size(); ++j) {
			bw.write(result.get(j));
			bw.newLine();
		}
		bw.flush();
	}
}

class WordSorting implements Comparable<WordSorting>{
	private String word;
	
	public WordSorting(String word) {
		this.word = word;
	}
	
	public String getWord() {
		return word;
	}

	@Override
	public int compareTo(WordSorting o) {
		if (this.word.length() == o.word.length()) {
			return this.word.compareTo(o.word);
		}
		else {
			if (this.word.length() > o.word.length())
				return 1;
			else if (this.word.length() < o.word.length())
				return -1;
			else
				return 0;
		}
	}
}