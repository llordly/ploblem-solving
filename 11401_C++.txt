#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

long long mul(long long x, long long y, long long p) {
	long long ans = 1;
	while (y > 0) {
		if (y % 2 != 0) {
			ans *= x;
			ans %= p;
		}
		x *= x;
		x %= p;
		y /= 2;
	}
	return ans;
}

int main(void) {
	long long n, r, p;
	scanf("%lld %lld", &n, &r);
	p = 1000000007LL;
	long long ans = 1;
	long long f = 1;
	r = min(n - r, r);
	for (int i = 1; i <= r; ++i) {
		ans = ans*(n - i + 1) % p;
		f = f*i%p;
	}
	long long t = mul(f, p - 2, p);
	t %= p;
	ans = ans*t;
	ans %= p;
	printf("%lld\n", ans);
	return 0;
}
