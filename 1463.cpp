#include <cstdio>
#include <cstring>
#include <algorithm>

int dp[1000001]{ 0, };

int one(int n)
{
	if (n == 1) return 0;
	if (dp[n] > 0) return dp[n];
	dp[n] = one(n - 1) + 1;

	if (n % 2 == 0) {
		int temp = one(n / 2) + 1;
		if (dp[n] > temp) dp[n] = temp;
	}
	if (n % 3 == 0) {
		int temp = one(n / 3) + 1;
		if (dp[n] > temp) dp[n] = temp;
	}
	return dp[n];
}

int main(void) {
	int n;
	scanf("%d", &n);
	one(n);
	printf("%d", dp[n]);
}

////////////////////////////////////////////

#include <cstdio>
int min(int a, int b){
    return a> b? b: a;
}
int solve(int n) {
    if (n <= 1) return 0;
    int x, y;
    x = solve(n/3) + 1 + (n%3);
    y = solve(n/2) + 1 + (n%2);
    return min(x,y);
}
int main(void){
    int n;
    scanf("%d", &n);
    printf("%d\n", solve(n));
    return 0;
}