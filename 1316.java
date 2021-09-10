import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static void main(String[] args) {

		Scanner keyboard = new Scanner(System.in);

		int num = Integer.parseInt(keyboard.nextLine());
		
		int count = 0;

		for (int i = 0; i < num; ++i) {
			if(check(keyboard.nextLine())) count++;
		}
		System.out.println(count);
	}
	
	static boolean check(String word) {
		Stack<Character> stack = new Stack<>();
		ArrayList<Character> list = new ArrayList<Character>();
		
		for(int i = 0; i < word.length(); ++i) {
			if(stack.empty()) stack.push(word.charAt(i));
			else if (stack.peek() == word.charAt(i)) stack.push(word.charAt(i));
			else {
				list.add(stack.pop());
				while(!stack.empty())
					stack.pop();
			}
			Character checkChar = new Character(word.charAt(i));
			if (list.contains(checkChar)) return false;
		}
		return true;
	}
}
