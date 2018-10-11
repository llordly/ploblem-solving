
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int list[][] = new int[15][14];

		for (int i = 0; i < 15; ++i) {
			for (int j = 0; j < 14; ++j) {
				list[i][j] = 0;
				if (i == 0)
					list[i][j] = j + 1;
			}
		}

		for (int i = 1; i < 15; ++i) {
			for (int j = 0; j < 14; ++j) {
				int sum = 0;
				for (int k = 0; k <= j; ++k) {
					sum += list[i - 1][k];
				}
				list[i][j] = sum;
			}
		}

		int num = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < num; ++i) {
			int row = Integer.parseInt(br.readLine());
			int col = Integer.parseInt(br.readLine()) - 1;
			bw.write(String.valueOf(list[row][col]));
			bw.newLine();
		}
		bw.flush();
	}

}