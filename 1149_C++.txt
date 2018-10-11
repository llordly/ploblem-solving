#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int ans[1001][3];

int RGB() {
	int r, g, b, n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &r, &g, &b);
		if (i == 0) {
			ans[0][0] = r;
			ans[0][1] = g;
			ans[0][2] = b;
			continue;
		}
		ans[i][0] = min(ans[i - 1][1], ans[i - 1][2]) + r;
		ans[i][1] = min(ans[i - 1][0], ans[i - 1][2]) + g;
		ans[i][2] = min(ans[i - 1][0], ans[i - 1][1]) + b;
	}

	return min(min(ans[n - 1][0], ans[n - 1][1]), ans[n - 1][2]);
}

int main(void) {
	printf("%d", RGB());
}