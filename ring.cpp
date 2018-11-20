#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

//BOJ 3036 ring
//lorldy

int gcd(int a, int b) {
	return (a % b ? gcd(b, a % b) : b);
}

int arr[100];

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	int first = arr[0];
	for (int i = 1; i < n; ++i) {
		if (first % arr[i] == 0) {
			printf("%d/1\n", first / arr[i]);
		}
		else {
			int gcd_num = gcd(first, arr[i]);
			printf("%d/%d\n", first / gcd_num, arr[i] / gcd_num);
		}
	}

	return 0;
}