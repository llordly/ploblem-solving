#include <cstdio>
#include <cstring>
#include <algorithm>
//BOJ 9251 LCS

char x[1001];
char y[1001];
int dp[1001][1001];
int a, b;

int LCS(char *x, char *y, int n, int m) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (x[i - 1] == y[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[n][m];
}

int main() {

	scanf("%s %s", x, y);
	int n = strlen(x);
	int m = strlen(y);

	int result = LCS(x, y, n, m);

	printf("%d\n", result);
}