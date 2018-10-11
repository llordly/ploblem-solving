
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
		
		Stack stack = new Stack();
		
		int index = 1;
		StringBuilder sb = new StringBuilder();
		boolean result = true;
		for (int i = 0; i < n; ++i) {
			int num = Integer.parseInt(br.readLine());
			
			if ((index <= num) && result) {
				while (index <= num) {
					stack.push(index);
					sb.append("+");
					sb.append(System.getProperty("line.separator"));
					index++;
				}
			}
			int popNum = stack.pop();
			if ((popNum == num) && result) {
				sb.append("-");
				sb.append(System.getProperty("line.separator"));
			}
			else {
				sb = new StringBuilder();
				sb.append("NO");
				result = false;
			}
			
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
	}
}
class Stack{
	private class Node{
		private int data;
		private Node link;
		
		public Node(int data) {
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
	
	public void push(int data) {
		Node newNode = new Node(data);
		newNode.link = top;;
		top = newNode;
	}
	
	public int pop() {
		Node n;
		n = top;
		if (isEmpty()) return -1; 
		top = top.link;
		
		return n.data;
	}
}