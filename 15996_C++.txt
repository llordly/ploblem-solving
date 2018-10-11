#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

int count = 0;

void fac(long long n, int a) {
	long long power = a;
	if (n == 0) return;
	while (power <= n) {
		count += n / power;
		power *= a;
	}
}

int main(void) {
	long long n; int a;
	scanf("%lld %d", &n, &a);
	fac(n, a);
	printf("%d", count);
	return 0;
}