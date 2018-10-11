
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;


public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());

		int list[] = new int[N];
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for (int i = 0; i < N; ++i) {
			list[i] = Integer.parseInt(st.nextToken());
		}
		
		int count = N;
		for (int j = 0; j < N; ++j) {
			int num = list[j];
			for (int k = 2; k < num; ++k) {
				if (num % k == 0) {
					count--;
					break;
				}
			}
			if (num == 1) count--;

		}
		
		bw.write(String.valueOf(count));
		bw.flush();
	}
}