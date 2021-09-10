
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
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int vertex = Integer.parseInt(st.nextToken());
		int edge = Integer.parseInt(st.nextToken());
		int start = Integer.parseInt(st.nextToken());
		
		Graph graph = new Graph(vertex);
		
		for (int i = 1; i <= vertex; ++i) {
			graph.insert_vertex(i);
		}
		for (int i = 0; i < edge; ++i) {
			st = new StringTokenizer(br.readLine());
			graph.insert_edge(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		graph.reset_visited();
		graph.DFS(start);
		bw.write(graph.getResult());
		bw.newLine();
		graph.reset_visited();
		graph.resetResult();
		graph.BFS(start);
		bw.write(graph.getResult());
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
	
	public Queue() {
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

class Graph{

	final static int MAX_VTXS = 1001;
	private String result = "";

	public void resetResult() {
		result = "";
	}

	private int vsize;

	int vdata[] = new int[MAX_VTXS];
	
	boolean adj[][] = new boolean[MAX_VTXS][MAX_VTXS];
	
	public Graph(int vsize){
		this.vsize = vsize;
		for (int i = 1; i < MAX_VTXS; ++i) {
			for (int j = 1; j < MAX_VTXS; ++j) {
				adj[i][j] = false;
			}
		}
	}
	
	public boolean isEmpty() {
		return vsize == 0;
	}
	
	public boolean isFull() {
		return vsize >= MAX_VTXS;
	}
	
	public void insert_vertex(int name) {
		if (isFull()) throw new ArrayIndexOutOfBoundsException();
		else {
			vdata[name] = name;
		}
	}
	
	public void insert_edge(int u, int v) {
		adj[u][v] = adj[v][u] = true;
	}
	
	boolean visited[] = new boolean[MAX_VTXS];
	
	void reset_visited() {
		for (int i = 1; i <= vsize; ++i) {
			visited[i] = false;
		}
	}
	
	public String getResult() {
		return result;
	}

	public void DFS(int v) {
		visited[v] = true;
		result += vdata[v] + " ";
		for (int w = 1; w <= vsize; ++w) {
			if (adj[v][w] && !visited[w])
				DFS(w);
		}
	}
	Queue<Integer> queue = new Queue<Integer>();
	public void BFS(int v) {
		visited[v] = true;
		result += vdata[v] + " ";
		queue.push(v);
		
		while (!queue.isEmpty()) {
			v = queue.pop();
			
			for (int w = 1; w <= vsize; ++w) {
				if (!visited[w] && adj[v][w]) {
					visited[w] = true;
					result += vdata[w] + " ";
					queue.push(w);
				}
			}
		}
	}
	
	
}