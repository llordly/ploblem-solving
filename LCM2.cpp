#include <cstdio>
#include <cstring>
#include <algorithm>
//BOJ 13241 LCM2
//lorldy

int gcd(int a, int b) {
	return a % b ? gcd(b, a % b) : b;
}

int main(void) {
	long long a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld", (a * b) / gcd(a, b));
	return 0;
}