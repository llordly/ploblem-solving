
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
		int N = Integer.parseInt(br.readLine());
		Queue<Integer> queue = new Queue<Integer>();
		queue.init_queue();
		int num;
		String line;
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < N; ++i) {
			line = br.readLine();
			try {
				if (line.length() > 3 && line.substring(0, 4).equals("push")) {
					num = Integer.parseInt(line.substring(5));
					queue.push(num);
				}
				else if (line.equals("front")) {
					sb.append(queue.front());
					sb.append(System.getProperty("line.separator"));
				}
				else if (line.equals("back")) {
					sb.append(queue.back());
					sb.append(System.getProperty("line.separator"));
				}
				else if (line.equals("pop")) {
					sb.append(queue.pop());
					sb.append(System.getProperty("line.separator"));
				}
				else if (line.equals("size")) {
					sb.append(queue.size());
					sb.append(System.getProperty("line.separator"));
				}
				else if (line.equals("empty")) { 
					if (queue.isEmpty())
						sb.append("1");
					else
						sb.append("0");
					sb.append(System.getProperty("line.separator"));
				}
			} catch (Exception e) {
				sb.append("-1");
				sb.append(System.getProperty("line.separator"));
			}
		}
	bw.write(sb.toString());
	bw.flush();
	}
}
class Queue<T>{
	
	private class Node{
		private T data;
		private Node link;
		public Node(T data) {
			this.data = data;
			this.link = null;
		}
	}
	
	Node front;
	Node rear;
	
	public void init_queue() {
		front = null;
		rear = null;
	}
	
	public int size() {
		Node n;
		int count = 0;
		for (n = front; n !=null; n = n.link)
			count++;
		return count;
	}
	
	public void push(T data) {
		Node newNode = new Node(data);
		if (isEmpty()) {
			front = newNode;
			rear = newNode;
		}
		else {
			rear.link = newNode;
			rear = newNode;
		}
	}
	
	public T pop() {
		Node n;
		if (isEmpty()) throw new ArrayIndexOutOfBoundsException();
		else if (size() == 1) {
			n = front;
			front = null;
			rear = null;
		}
		else {
			n = front;
			front = front.link;
		}
		return n.data;
	}
	
	public T front() {
		Node n;
		if (isEmpty()) throw new ArrayIndexOutOfBoundsException();
		else {
			n = front;
		}
		return front.data;
	}
	
	public T back() {
		Node n;
		if (isEmpty()) throw new ArrayIndexOutOfBoundsException();
		else {
			n = rear;
		}
		return rear.data;
	}
	
	public boolean isEmpty() {
		return (front == null && rear == null);
	}
}