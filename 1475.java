
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
		
		char list[] = new char[10];
		int countList[] = new int[10];
		char zero = '0';
		for (int i = 0; i < 10; ++i) {
			list[i] = zero++;
			countList[i] = 0;
		}
		
		for (int j = 0; j < N.length(); ++j) {
			 for (int k = 0; k < 10; ++k) {
				 if (N.charAt(j) == list[k])
					 countList[k]++;
			 }
		}
		
		countList[6] += countList[9];
		if (countList[6] % 2 == 0) countList[6] /= 2;
		else countList[6] = countList[6] /2 + 1;
		countList[9] = 0;
		
		Arrays.sort(countList);	
		
		bw.write(String.valueOf(countList[9]));
		bw.flush();
	}
}