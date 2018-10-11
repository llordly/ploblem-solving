#include <cstdio>
#include <cstring>
#include <algorithm>
long long mod = 1000000000;
int dp[100][12];
// 0 = 1;

long long stair(int n) {
	long long ans = 0;
	for (int i = 2; i <= 10; ++i) {
		dp[0][i] = 1;
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= 10; ++j) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			dp[i][j] %= mod;
		}
	}
	for (int i = 1; i <= 10; ++i)
		ans = (ans + dp[n - 1][i]) % mod;
	return ans;
}

int main(void) {
	int n;
	scanf("%d", &n);
	printf("%lld", stair(n));
	return 0;
}