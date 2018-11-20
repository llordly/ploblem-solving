#include <cstdio>
#include <cstring>
#include <algorithm>
//BOJ 1934 LCM
//lorldy

int gcd(int a, int b) {
	return a % b ? gcd(b, a % b) : b;
}

int main(void) {
	int n, a, b;
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &a, &b);
		printf("%d\n", (a * b) / gcd(a, b));
	}
	return 0;
}