#include <cstdio>
#include <cstring>
#include <algorithm>
//BOJ 2293 COIN1

int dp[100001] = { 1, };

int coin() {
	int n, k, num;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		for (int j = num; j <= k; ++j) {
			dp[j] += dp[j - num];
		}
	}
	return dp[k];
}

int main(void) {
	printf("%d", coin());
	return 0;
}