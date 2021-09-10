
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.StringTokenizer;



public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int line = -1;
		while((line = Integer.parseInt(br.readLine())) != 0) {
			bw.write(String.valueOf(Eratos(line)));
			bw.newLine();
		}
		bw.flush();
			
	}
	public static int Eratos(int N) {
		ArrayList<Boolean> eratosList = new ArrayList<Boolean>(2*N+1);
		eratosList.add(false);
		eratosList.add(false);
		
		for (int i = 2; i <= 2*N; ++i) {
			eratosList.add(i, true);
		}
		
		for (int i = 2; (i*i) <= 2*N; ++i) {
			if (eratosList.get(i)) {
				for (int j = i*i; j <= 2*N; j += i)
					eratosList.set(j, false);
			}
		}
		int count = 0;
		for (int i = N+1; i <= 2*N; ++i) {
			if (eratosList.get(i)) {
				count++;
			}
		}
		return count;
	}
}