#include <stdio.h>
#include <cstring>

int list[1001][1001];


int bino(int n, int k) {
	if (n == k || k == 0)
		list[n][k] = 1;
	if (list[n][k] == 0) {
		list[n][k] = (bino(n - 1, k - 1) + bino(n - 1, k)) % 10007;
	}
	return list[n][k];
}

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", bino(n, k));
}