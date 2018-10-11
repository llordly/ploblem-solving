
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

		Calendar list[] = new Calendar[num];

		StringTokenizer st;

		for (int i = 0; i < num; ++i) {
			st = new StringTokenizer(br.readLine());
			Calendar a = new Calendar(st.nextToken(), st.nextToken(), st.nextToken(), st.nextToken());
			list[i] = a;
		}
		int count;
		int M;
		int N;
		int x;
		int y;
		int diff;
		
		for (int j = 0; j < num; ++j) {
			Calendar cal = list[j];
			count = cal.getX();
			M = cal.getM();
			N = cal.getN();
			x = cal.getX();
			y = cal.getX();
			
			while (y <= 0)
				y += N;
			while (y > N)
				y -= N;
		
			diff = M - N;
			
			while (!(x == cal.getX() && y == cal.getY())){
				if (count > (int)lcm((int)M, (int)N)) {
					count = -1;
					break;
				}
				y += diff;
				while (y <= 0)
					y += N;
				while (y > N)
					y -= N;
				count += M;
			}
			
			
			bw.write(String.valueOf(count));
			bw.newLine();
		}
		bw.flush();
		
	
	}

	public static long lcm(long a, long b) {
		int gcd_value = gcd((int) a, (int) b);

		if (gcd_value == 0)
			return 0;

		return Math.abs((a * b) / gcd_value);
	}

	public static int gcd(int a, int b) {
		while (b != 0) {
			int temp = a % b;
			a = b;
			b = temp;
		}
		return Math.abs(a);
		
		/*
		 * 유클리드 호제법
		 * (a,b) = (b,r)
		 * (1071, 1029) = (1029, 42) = (42, 21) = (21, 0) = 21
		 */
	}
}

class Calendar {
	private int M;
	private int N;

	public int getM() {
		return M;
	}

	public int getN() {
		return N;
	}

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}

	private int x;
	private int y;

	public Calendar(String M, String N, String x, String y) {
		this.M = Integer.parseInt(M);
		this.N = Integer.parseInt(N);
		this.x = Integer.parseInt(x);
		this.y = Integer.parseInt(y);
	}
}