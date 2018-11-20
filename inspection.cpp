#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

//BOJ 2981 inspection
//lorldy
int gcd(int a, int b) {
	return (a % b ? gcd(b, a % b) : b);
}

int arr[100];
int new_arr[5445];

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}

	std::sort(arr, arr + n);

	int index = 0;
	for (int i = n - 1; i > 0; --i) {
		for (int j = i - 1; j >= 0; j--) {
			new_arr[index++] = arr[i] - arr[j];
		}
	}

	for (int i = 1; i < index; ++i) {
		new_arr[i] = gcd(new_arr[i], new_arr[i - 1]);
	}

	int gcd_num = new_arr[index - 1];

	std::vector<int> divisors;
	
	for (int i = 1; i * i <= gcd_num; i++) {
		if (gcd_num % i == 0) {
			divisors.push_back(i);
			if (i != gcd_num / i) divisors.push_back(gcd_num / i);
		}
	}

	sort(divisors.begin(), divisors.end());

	for (int i = 1; i < divisors.size(); i++) {
		printf("%d ", divisors[i]);
	}

}