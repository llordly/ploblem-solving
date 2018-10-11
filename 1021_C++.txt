#include <stdio.h>
#include <cstring>
#define MAX_QUEUE_SIZE 51

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

void left() {
	push_back(pop_front());
}

void right() {
	push_front(pop_back());
}

int main() {
	int n, m, index, d, total;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		push_back(i);
	}
	total = 0;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &index);
		d = 0;
		while (peek() != index) {
			left(); d++;
		}
		if (d > n / 2) {
			while (d--)
				right();
			d++;
			while (peek() != index) {
				right(); d++;
			}
		}
		pop_front();
		n--;
		total += d;
	}
	printf("%d", total);
	return 0;
}