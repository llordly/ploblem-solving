#include <cstdio>
#include <cstring>
#include <algorithm>
//BOJ 1520 DESCENDING STRAIR

int arr[501][10001];
int dp[501][10001];
int m, n;

int path(int i, int j) {
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = 0;
	if (arr[i + 1][j] > arr[i][j] && i + 1 < m) {
		dp[i][j] += path(i + 1, j);
	}
	if (arr[i - 1][j] > arr[i][j] && i - 1 >= 0) {
		dp[i][j] += path(i - 1, j);
	}
	if (arr[i][j + 1] > arr[i][j] && j + 1 < n) {
		dp[i][j] += path(i, j + 1);
	}
	if (arr[i][j - 1] > arr[i][j] && j - 1 >= 0) {
		dp[i][j] += path(i, j - 1);
	}
	return dp[i][j];
}

int stair() {
	int num;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &num);
			arr[i][j] = num;
		}
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 1;
	
	//path(m-1, n-1);
	
	return path(m - 1, n - 1);
}

int main() {
	printf("%d", stair());
	return 0;
}