#include <stdio.h>

typedef int HNode;	//힙에 저장할 항목의 자료형 
#define Key(n) (n)	//힙노드 n의 키값
#define MAX_HEAP_NODE 2000000
HNode heap[MAX_HEAP_NODE];	//배열을이용해구현한힙(힙노드배열) 
int heap_size;	//힙의크기
#define Parent(i) (heap[i / 2])	//i의부모노드
#define Left(i) (heap[i*2])	//i의왼쪽자식노드 
#define Right(i) (heap[i*2+1])	//i의오른쪽자식노드
void init_heap() { heap_size = 0; }
int is_empty_heap() { return heap_size == 0; }
int is_full_heap() { return(heap_size == MAX_HEAP_NODE - 1); }

void insert_heap(HNode n) {
	int i;
	if (is_full_heap())
		return;
	i = ++heap_size;

	while (i != 1 && n < heap[i / 2]) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = n;
}

HNode delete_heap() {
	HNode hroot;
	HNode last;
	int parent = 1, child = 2;
	if (!is_empty_heap()) {
		hroot = heap[1];
		last = heap[heap_size--];
		while (child <= heap_size) {
			if (child < heap_size && heap[parent * 2] > heap[parent * 2 + 1])
				child++;
			if (last <= heap[child])
				break;
			heap[parent] = heap[child];
			parent = child;
			child *= 2;
		}
		heap[parent] = last;
	}
	return hroot;
}

int main() {
	init_heap();
	
	int num;
	int node;
	scanf("%d", &num);
	int *sort = (int*)malloc(sizeof(int)*num);

	for (int i = 0; i < num; ++i) {
		scanf("%d", &node);
		insert_heap(node);
	}

	for (int i = 0; i < num; ++i) {
		sort[i] = delete_heap();
	}

	for (int j = 0; j < num; ++j) {
		printf("%d\n", sort[j]);
	}
	return 0;
}