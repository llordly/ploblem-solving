import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;



public class Main {
	
	static int MAX_SIZE = 10000000;
	static int MAX_NUM = 10000;
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());
		int A[] = new int[N];
		
		for (int i = 0; i < N; ++i) {
			A[i] = Integer.parseInt(br.readLine());
		}
		
		int B[] = CountingSort(A, N);
		
		for (int i = 0; i < N; ++i) {
			bw.write(String.valueOf(B[i]));
			bw.newLine();
		}
		bw.flush();
	}
	
	public static int[] CountingSort(int A[], int n) {
		
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
		
		int B[] = new int[n];
		
		for (int i = 0; i < max; ++i) {
			count[i] = 0;
		}
		for (int i = 0; i < n; ++i) {
			count[A[i]]++;
		}
		
		countSum[0] = count[0];
		
		for (int i = 1; i <= max; ++i) {
			countSum[i] = countSum[i-1] + count[i];
		}
		
		for (int i = n - 1 ; i >= 0; --i) {
			B[--countSum[A[i]]] = A[i] - MAX_NUM;
			//countSum�� �ִ� �� ������ ������ ���� n���� �ڸ��ϴ�. B�� ũ�⵵ n�̹Ƿ� n-1�� �����ؾ��ϹǷ�
			//������������ --�� ����Ͽ� B�� ����ִ´�.
		}
		
		return B;
		
	}
}