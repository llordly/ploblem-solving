
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = Integer.parseInt(br.readLine());
		
		Stack stack;
		
		StringBuilder sb = new StringBuilder();
		boolean result;
		for (int i = 0; i < n; ++i) {
			stack = new Stack();
			String testPs = br.readLine();
			result = true;
			for (int j = 0; j < testPs.length(); ++j) {
				if (testPs.charAt(j) == '(') {
					stack.push('(');
				}
				else {
					try {
						stack.pop();
					} catch (Exception e) {
						result = false;
						break;
					}
				}
			}
			if (result && stack.isEmpty()) {
				sb.append("YES");
				sb.append(System.getProperty("line.separator"));
			}
			else {
				sb.append("NO");
				sb.append(System.getProperty("line.separator"));
			}
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
	}
}
class Stack{
	private class Node{
		private char data;
		private Node link;
		
		public Node(char data) {
			this.data = data;
			this.link = null;
		}
	}
	
	public Stack() {
		init_stack();
	}
	
	Node top;
	
	public void init_stack() {
		top = null;
	}
	
	public boolean isEmpty() {
		return (top == null);
	}
	
	public int size() {
		Node n;
		int count = 0;
		for (n = top; n != null; n = n.link) {
			count++;
		}
		return count;
	}
	
	public void push(char data) {
		Node newNode = new Node(data);
		newNode.link = top;;
		top = newNode;
	}
	
	public char pop() {
		Node n;
		n = top;
		if (isEmpty()) throw new ArrayIndexOutOfBoundsException();
		top = top.link;
		
		return n.data;
	}
}