#include <cstdio>
#include <cstring>
#include <algorithm>
//BOJ 1912 SUM

int dp[100001];
int arr[100001];

int sum() {
	int n, num;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		arr[i] = num;
	}
	dp[0] = arr[0];

	for (int i = 1; i < n; ++i) {
		if (dp[i - 1] + arr[i] < arr[i])
			dp[i] = arr[i];
		else
			dp[i] = dp[i - 1] + arr[i];
	}
	return *std::max_element(dp, dp + n);
}
int main(void) {
	printf("%d", sum());
	return 0;
}