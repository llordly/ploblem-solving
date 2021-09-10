
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String N = br.readLine();
		
		int list[] = new int[N.length()];
		
		for (int i = 0; i < N.length(); ++i) {
			list[i] = N.charAt(i) - '0';
		}
		
		Arrays.sort(list);
		String result = "";
		for (int j = N.length() - 1; j >= 0; --j){
			result += list[j];
		}
		
		bw.write(result);
		bw.flush();
	}
}