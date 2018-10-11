
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;



public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int M = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		
		ArrayList<Boolean> eratosList = new ArrayList<Boolean>(N+1);
		eratosList.add(false);
		eratosList.add(false);
		
		for (int i = 2; i <= N; ++i) {
			eratosList.add(i, true);
		}
		
		for (int i = 2; (i*i) <= N; ++i) {
			if (eratosList.get(i)) {
				for (int j = i*i; j <= N; j += i)
					eratosList.set(j, false);
			}
		}
		
		for (int i = M; i <= N; ++i) {
			if (eratosList.get(i)) {
				bw.write(String.valueOf(i));
				bw.newLine();
			}
		}
		bw.flush();		
	}

}