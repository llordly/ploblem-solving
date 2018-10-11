#include <stdio.h>
#include <cstring>
#define MAX_QUEUE_SIZE 100001

int data[MAX_QUEUE_SIZE];
int front;
int rear;

void init_queue() {
	front = rear = 0;
}

int is_empty() {
	return front == rear;
}

int size() {
	return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void push_front(int val) {
	front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	data[(front + 1) % MAX_QUEUE_SIZE] = val;
}

void push_back(int val) {
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = val;
}

int pop_back() {
	if (is_empty())
		return -1;
	rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return data[(rear + 1) % MAX_QUEUE_SIZE];
}

int pop_front() {
	if (is_empty())
		return -1;
	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}

int peek() {
	if (is_empty())
		return -1;
	return data[(front + 1) % MAX_QUEUE_SIZE];
}

int back() {
	if (is_empty())
		return -1;
	return data[rear];
}

int main() {
	int n, a;
	char str[16];
	scanf("%d", &n);
	init_queue();
	for (int i = 0; i < n; ++i) {
		scanf("%s", str);
		if (!strcmp("push_front", str)) {
			scanf("%d", &a);
			push_front(a);
		}
		else if (!strcmp("push_back", str)) {
			scanf("%d", &a);
			push_back(a);
		}
		else if (!strcmp("size", str)) {
			printf("%d\n", size());
		}
		else if (!strcmp("pop_front", str)) {
			printf("%d\n", pop_front());
		}
		else if (!strcmp("pop_back", str)) {
			printf("%d\n", pop_back());
		}
		else if (!strcmp("empty", str)) {
			printf("%d\n", is_empty());
		}
		else if (!strcmp("front", str)) {
			printf("%d\n", peek());
		}
		else if (!strcmp("back", str)) {
			printf("%d\n", back());
		}
	}
	return 0;
}