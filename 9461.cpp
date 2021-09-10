#include <cstdio>
#include <cstring>
#include <algorithm>
//BOJ 9461 WAVE

long long dp[101] = { 0, 1, 1, 1, 2, 2, };

long long wave(int n) {
	if (dp[n] != 0)
		return dp[n];
	else {
		dp[n] = wave(n - 1) + wave(n - 5);
		return dp[n];
	}
}

int main() {
	int t, n;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf("%d", &n);
		printf("%lld\n", wave(n));
	}
}
