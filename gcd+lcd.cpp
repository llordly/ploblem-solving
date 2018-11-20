#include <cstdio>
#include <cstring>
#include <algorithm>
//BOJ 13241 LCM2
//lorldy

int gcd(int a, int b) {
	return a % b ? gcd(b, a % b) : b;
}

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	int c = gcd(a, b);
	printf("%d\n%d", c, (a * b) / c);
	return 0;
}