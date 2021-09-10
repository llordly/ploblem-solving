
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
			// countSum�� �ִ� �� ������ ������ ���� n���� �ڸ��ϴ�. B�� ũ�⵵ n�̹Ƿ� n-1�� �����ؾ��ϹǷ�
			// ������������ --�� ����Ͽ� B�� ����ִ´�.
		}

		average = (int) Math.round((double) sum / N);
		bw.write(String.valueOf(average));
		bw.newLine();
		// ������
		bw.write(String.valueOf(B[N / 2]));
		bw.newLine();
		// �߾Ӱ�
		bw.write(String.valueOf(mode(count)));
		bw.newLine();
		// �ֺ�
		bw.write(String.valueOf(B[N-1] - B[0]));
		bw.newLine();
		// ����
		
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