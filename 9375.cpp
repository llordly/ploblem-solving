
#include <stdio.h>
#include <cstring>
#include <algorithm>

int clothIndex;

int main(void) {
	int t, n, k;
	long long ans;
	char check[21];
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf("%d", &n);
		char cloth[31][21];
		int count[31] = { 0, };
		ans = 1;
		clothIndex = 0;
		for (int j = 0; j < n; ++j) {
			scanf("%s %s", check, check);
			for (k = 0; k <= clothIndex; ++k) {
				if (!strcmp(check, cloth[k])) {
					count[k]++;
					break;
				}
			}
			if (k == clothIndex + 1) {
				count[clothIndex]++;
				strcpy(cloth[clothIndex++], check);
			}
		}
		for (int l = 0; l < 31; ++l) {
			if (count[l] != 0) {
				ans *= count[l] + 1;
			}
		}
		printf("%lld\n", ans - 1);
	}
}