
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.math.BigInteger;


public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		BigInteger big = combi(n, m);
		bw.write(String.valueOf(big));
		bw.flush();
	}
	
	public static BigInteger combi(int n, int r) {
		BigInteger ans = BigInteger.ONE;
		int b = Math.min(n-r, r);
		for (int i = 1; i <= b; ++i) {
			ans = ans.multiply(BigInteger.valueOf(n--));
			ans = ans.divide(BigInteger.valueOf(i));
		}
		return ans;
	}

}