
#include <stdio.h>
#include <string.h>

typedef struct node {
	int data;
	struct node *link;
}Node;

Node *top;

void init_stack() {
	top = NULL;
}

int size() {
	Node *p;
	int count = 0;
	
	for (p = top; p != NULL; p = p->link) {
		count++;
	}

	return count;
}

int isEmpty() {
	return (top == NULL);
}

int pop() {
	Node *p;

	if (isEmpty()) {
		return -1;
	}
	else {
		p = top;
		top = top->link;
	}
	return p->data;
}

void push(int data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = top;
	top = newNode;
}

int peek() {
	Node *p;
	if (isEmpty()) return -1;
	p = top;

	return p->data;
}

int main(void) {
	int N;
	init_stack();
	scanf("%d", &N);
	int num;
	char str[6];
	for (int i = 0; i < N; ++i) {
		scanf("%s", str);
		if (!strcmp("push", str)) {
			scanf("%d", &num);
			push(num);
		}
		else if (!strcmp("top", str)) {
			printf("%d\n", peek());
		}
		else if (!strcmp("size", str)) {
			printf("%d\n", size());
		}
		else if (!strcmp("pop", str)) {
			printf("%d\n", pop());
		}
		else if (!strcmp("empty", str)) {
			printf("%d\n", isEmpty());
		}	
	}
	return 0;
}