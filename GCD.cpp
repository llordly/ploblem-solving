#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
//BOJ 1850 gcd
//lorldy
long long gcd(long long a, long long b) {
	return (a % b ? gcd(b, a % b) : b);
}
char result[10000000];

int main(void) {
	long long a, b, c;
	scanf("%lld %lld", &a, &b);
	c = gcd(a, b);

	std::fill_n(result, c, '1');
	printf("%s", result);
	return 0;
}