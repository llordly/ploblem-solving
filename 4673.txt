import java.util.ArrayList;
import java.util.HashSet;


public class Main {
	public static void main(String[] args) {
		
		int num = 1;
		int result;
		
		HashSet<Integer> set = new HashSet<Integer>();
		
		while(true) {
			result = selfNumber(num);
			if (num > 10000) break;
			set.add(result);
			++num;
		}
		
		HashSet<Integer> selfSet = new HashSet<Integer>();
		
		for (int i = 1; i <= 10000; ++i) {
			selfSet.add(i);
		}
		
		selfSet.removeAll(set);
		
		ArrayList<Integer> selfList = new ArrayList<Integer>(selfSet);
		
		for (int j = 0; j < selfList.size(); ++j) {
			System.out.println(selfList.get(j));
		}
		
	}
	
	static int selfNumber(int num) {
		int sum = num;
		String a = String.valueOf(num);
		for (int i = 0; i < a.length(); ++i) {
			sum += a.charAt(i) - '0';
		}
		
		return sum;
	}
}
