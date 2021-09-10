#include <stdio.h>
int n, m, index;
int move() {
	index = (index + 1) % n;
	if (index == 0) index = n;
	return index;
}

int main() {
	scanf("%d %d", &n, &m);
	int count;
	int *arr = new int[n + 1];
	for (int i = 1; i <= n; ++i) {
		arr[i] = i;
	}
	index = m;
	printf("<%d", arr[index]);
	arr[index] = 0;
	for (int i = 0; i < n; ++i) {
		count = 0;
		if (i == n - 1) break;
		printf(", ");
		while(true) {
			if (arr[move()])++count;
			if (count == m)break;
		}
		printf("%d", arr[index]);
		arr[index] = 0;
	}
	printf(">");
	return 0;
}