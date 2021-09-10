
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


public class Main {
	public static void main(String[] args) throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int num = Integer.parseInt(br.readLine());
		
		
		int x;
		int y;
		
		int list[] = new int[num];
		
		for (int i = 0; i < num; ++i) {
			String a = br.readLine();
			x = Integer.parseInt(a.split(" ")[0]);
			y = Integer.parseInt(a.split(" ")[1]);
			list[i] = Fly(x, y);
		}
		
		for (int j = 0; j < num; ++j) {
			bw.write(String.valueOf(list[j]));
			bw.newLine();
		}
		bw.flush();
	}
	
	static int Fly(int x, int y) {
		int distance = 1;
		int position = x + distance;
		int count = 1;
		while(true) {
			if (position == y) break;
			int diff = y - position;
			if (diff >= sum(distance + 1)) {
				distance++;
				position += distance;
			}
			else if (diff >= sum(distance)) {
				position += distance;
			}
			else if (diff == 1) {
				position += 1;
			}
			else {
				distance--;
				position += distance;
			}
			count++;
		}
		return count;
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