
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;



public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());
		int M = Integer.parseInt(br.readLine());
		
		if (N == M) {
			int result = N;
			for (int k = 2; k < N; ++k) {
				if (N % k == 0) {
					result = -1;
					break;
				}
			}
			if (N == 1) {
				result = -1;
			}
			bw.write(String.valueOf(result));
			bw.newLine();
			if (result != -1) {
				bw.write(String.valueOf(result));
			}
			bw.close();
			System.exit(0);
		}
		
		int resultSum = sum(M) - sum(N-1);
		
		HashSet<Integer> resultSet = new HashSet<Integer>();
		
		for (int i = N; i <= M; ++i) {
			resultSet.add(i);
		}
		
		HashSet<Integer> set = new HashSet<Integer>();
		
		for (int j = N; j <= M; ++j) {
			int num = j;
			for (int k = 2; k < num; ++k) {
				if (num % k == 0) {
					resultSum -= num;
					set.add(num);
					break;
				}
			}
			if (num == 1) {
				set.add(1);
				resultSum--;
			}
		}
		
		resultSet.removeAll(set);
		
		ArrayList<Integer> list = new ArrayList<Integer>(resultSet);
		Collections.sort(list);
		
		if (list.isEmpty()) {
			bw.write("-1");
			bw.flush();
		} 
		else {
			int min = list.get(0);
			bw.write(String.valueOf(resultSum));
			bw.newLine();
			bw.write(String.valueOf(min));
			bw.flush();
		}
		
	}
	static int sum(int n) {
		if (n <= 0) return 0;
		if(n % 2 == 0){
		    return (n + 1) * (n / 2);
		  }else{
		    return n * ((n - 1) / 2) + n;
		  }
	}
}