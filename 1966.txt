
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int test = Integer.parseInt(br.readLine());
		int N;
		int M;
		Queue queue;
		int count;
		for (int i = 0; i < test; ++i) {

			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			queue = new Queue();
			for (int j = 0; j < N; ++j) {
				Priority pr = new Priority(j, Integer.parseInt(st.nextToken()));
				queue.enqueue(pr);
			}
			count = 1;
			while (count <= N) {
				if (!queue.check()) {
					queue.enqueue(queue.dequeue());
				}
				else {
					if (queue.dequeue().getIndex() == M) {
						bw.write(String.valueOf(count));
						bw.newLine();
						break;
					}
					count++;
				}
			}
		}
		bw.flush();
	}
}

class Priority{
	private int index;
	private int num;

	public Priority(int index, int num) {
		this.index = index;
		this.num = num;
	}
	public int getIndex() {
		return index;
	}
	public int getNum() {
		return num;
	}
	
}

class Queue{
	
	private class Node{
		private Priority data;
		private Node link;
		public Node(Priority data) {
			this.data = data;
			this.link = null;
		}
	}
	
	Node front;
	Node rear;
	
	public Queue(){
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
	
	public void enqueue(Priority data) {
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
	
	public Priority dequeue() {
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
	
	public Priority front() {
		Node n;
		if (isEmpty()) throw new ArrayIndexOutOfBoundsException();
		else {
			n = front;
		}
		return front.data;
	}
	
	public Priority back() {
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
	
	public boolean check() {
		Node n;
		boolean result = true;
		for (n = front.link; n != null; n = n.link) {
			if (front.data.getNum() < n.data.getNum()) result = false;
		}
		return result;
	}
	
	
}

