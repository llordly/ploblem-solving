
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
		
		Heap heap = new Heap();

		heap.init_heap();

		for (int i = 0; i < N; ++i) {
			Heap.HNode node = heap.new HNode(Integer.parseInt(br.readLine()));
			heap.insert_heap(node);
		}

		for (int j = 0; j < N; ++j) {
			bw.write(String.valueOf(heap.delete_heap().getKey()));
			bw.newLine();
		}
		bw.flush();

		
	}
}

class Heap {
	public class HNode {
		private int key;

		HNode(int key) {
			this.key = key;
		}

		public int getKey() {
			return key;
		}
		
	}

	final static int MAX_HEAP_NODE = 2000000;
	HNode heap[] = new HNode[MAX_HEAP_NODE]; // 배열을이용해구현한힙(힙노드배열)
	int heap_size; // 힙의크기

	void init_heap() {
		heap_size = 0;
	}

	public boolean is_empty_heap() {
		return heap_size == 0;
	}

	public boolean is_full_heap() {
		return (heap_size == MAX_HEAP_NODE - 1);
	}

	void insert_heap(HNode n) {
		int i;
		if (is_full_heap())
			return;
		i = ++heap_size;

		while (i != 1 && n.key < heap[i / 2].key) {
			heap[i] = heap[i / 2];
			i /= 2;
		}
		heap[i] = n;
	}

	HNode delete_heap() {
		HNode hroot = null;
		HNode last;
		int parent = 1, child = 2;
		if (!is_empty_heap()) {
			hroot = heap[1];
			last = heap[heap_size--];
			while (child <= heap_size) {
				if (child < heap_size && heap[parent * 2].key > heap[parent * 2 + 1].key)
					child++;
				if (last.key <= (heap[child].key))
					break;
				heap[parent] = heap[child];
				parent = child;
				child *= 2;
			}
			heap[parent] = last;
		}
		return hroot;
	}
}