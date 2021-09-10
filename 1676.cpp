#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

int count = 0;
int a = 5;
void fac(int n) {
	int power = a;
	if (n == 0) return;
	while (power <= n) {
		count += n / power;
		power *= a;
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	fac(n);
	printf("%d", count);
	return 0;
}