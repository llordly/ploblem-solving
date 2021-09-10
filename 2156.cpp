#include <cstdio>
#include <cstring>
#include <algorithm>
//BOJ 2156 GRAPH
using namespace std;
int dp[10002][3];

int graph(int n) {
	int num;
	for (int i = 3; i <= n+2; ++i) {
		scanf("%d", &num);
		dp[i][0] += max(dp[i - 1][1], dp[i - 1][2]) + num;
		dp[i][1] += max(dp[i - 2][0], dp[i - 2][1]) + num;
		dp[i][2] += max(dp[i - 3][0], dp[i - 3][1]) + num;
	}
	return max(max(dp[n + 2][0], dp[n + 2][1]), max(dp[n+1][0], dp[n+1][1]));
}

int main(void) {
	int n;
	scanf("%d", &n);
	printf("%d", graph(n));
	return 0;
}