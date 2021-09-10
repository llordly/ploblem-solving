#include <cstdio>
#include <cstring>
#include <algorithm>

int dp[301][2]{ 0, }; 
int main(void) {
	int n, cost;
	scanf("%d %d", &n, &cost);
	dp[1][1] = cost;
	int last = cost;
	for (int i = 2; i <= n; ++i) {
		scanf("%d", &cost);
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = cost + std::max(dp[i - 2][0] + last, dp[i - 1][0]);
		last = cost;
	}
	printf("%d", dp[n][1]);
	return 0;
}

/////////////////////////////////////////////////

#include <stdio.h>
int m(int a,int b){return a>b?a:b;}
int t,x,a[302][2];	
int main()
{	scanf("%d",&t);
	for(int i=2; i<=t+1;i++){
        scanf("%d",&x);	
		a[i][0] += a[i-1][1]+x;
		a[i][1] += m(a[i-2][0],a[i-2][1])+x;
	}
	printf("%d\n",m(a[t+1][0],a[t+1][1]));
}