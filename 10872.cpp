#include <stdio.h>
#include <cstring>

int factorial(int n) {
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
		ans *= i;
	}
	return ans;
}

int main(void) {
	int n;
	scanf("%d", &n);
	printf("%d", factorial(n));
}