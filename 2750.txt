
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		
		int num = Integer.parseInt(br.readLine());
		
		int list[] = new int[num];
		
		for (int i = 0; i < num; ++i) {
			list[i] = Integer.parseInt(br.readLine());
		}
		
		for (int i = 0; i < num - 1; ++i) {
			int temp = i;
			for (int j = i + 1; j < num; ++j) {
				if (list[temp] >= list[j]) temp = j;
			}
			swap(list, i, temp);
		}
		
		for (int k = 0; k < num; ++k) {
			System.out.println(list[k]);
		}
	}
	
	static void swap(int arr[], int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}