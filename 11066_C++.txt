#include <cstdio>
#include <cstring>
#include <algorithm>
#include <limits.h>
//BOJ 11066 FILE

int dp[501][501] = {};
int arr[501] = {};
int c[501][501] = {};

int file() {
	int n, num;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &num);
		arr[i] = arr[i - 1] + num;
	}

	for (int i = 1; i <= n; ++i) {
		c[i-1][i] = i;
	}

	for (int diagonal = 2; diagonal <= n; diagonal++)
	{
		for (int i = 0; i <= n - diagonal; i++)
		{
			int j = i + diagonal;
			dp[i][j] = INT_MAX;
			for (int k = c[i][j - 1]; k <= c[i + 1][j]; k++) {
				int min = dp[i][k] + dp[k][j] + arr[j] - arr[i];
				if (dp[i][j] > min) {
					dp[i][j] = min;
					c[i][j] = k;
				}
			}
		}
	}
	return dp[0][n];
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		printf("%d\n", file());
	}
}