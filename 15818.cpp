#include <stdio.h>
#include <cstring>

long long multi(long long a, long long b, int M) {
	return (a*b) % M;
}

int main(void) {
	int n, m, num;
	long long result;
	scanf("%d %d", &n, &m);
	scanf("%d", &num);
	result = num % m;
	if (n > 1) {
		for (int i = 0; i < n-1; ++i) {
			scanf("%d", &num);
			result = multi(result, num, m);
		}
	}
	printf("%lld", result);

}
