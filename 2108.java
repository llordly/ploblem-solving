
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {

	static int MAX_SIZE = 10000000;
	static int MAX_NUM = 4000;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());
		int A[] = new int[N];

		for (int i = 0; i < N; ++i) {
			A[i] = Integer.parseInt(br.readLine());
		}

		int average;
		int sum = 0;

		for (int i = 0; i < N; ++i) {
			sum += A[i];
		}

		for (int i = 0; i < A.length; ++i) {
			A[i] += MAX_NUM;
		}

		int max = A[0];

		for (int i = 1; i < A.length; ++i) {
			if (A[i] >= max) {
				max = A[i];
			}
		}

		int count[] = new int[max + 1];
		int countSum[] = new int[max + 1];

		int B[] = new int[N];

		for (int i = 0; i < max; ++i) {
			count[i] = 0;
		}
		for (int i = 0; i < N; ++i) {
			count[A[i]]++;
		}

		countSum[0] = count[0];

		for (int i = 1; i <= max; ++i) {
			countSum[i] = countSum[i - 1] + count[i];
		}

		for (int i = N - 1; i >= 0; --i) {
			B[--countSum[A[i]]] = A[i] - MAX_NUM;
			// countSum의 최댓값 즉 마지막 원소의 값은 n임이 자명하다. B의 크기도 n이므로 n-1로 접근해야하므로
			// 전위연산자인 --를 사용하여 B에 집어넣는다.
		}

		average = (int) Math.round((double) sum / N);
		bw.write(String.valueOf(average));
		bw.newLine();
		// 산술평균
		bw.write(String.valueOf(B[N / 2]));
		bw.newLine();
		// 중앙값
		bw.write(String.valueOf(mode(count)));
		bw.newLine();
		// 최빈값
		bw.write(String.valueOf(B[N-1] - B[0]));
		bw.newLine();
		// 범위
		
		bw.flush();
	}

	public static int mode(int arr[]) {
		int num = 0;
		int max = arr[0];
		int maxIndex = -1;
		for (int i = 1; i < arr.length; ++i) {
			if (arr[i] >= max) {
				max = arr[i];
				maxIndex = i;
			}
		}
	
		int count = 0;
		for (int i = 0; i < arr.length; ++i) {
			if (arr[i] == max) {
				count++;
				if (count == 2) {
					num = i;
				}
			}
		}
		if (count == 1) {
			num = maxIndex;
		}

		return num - MAX_NUM;
	}

}