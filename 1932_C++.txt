#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int tri() {
	int n, a;
	scanf("%d", &n);
	int **list = new int*[n];
	for (int i = 0; i < n; ++i) {
		list[i] = new int[i+1];
		for (int j = 0; j < i+1; ++j) {
			scanf("%d", &a);
			list[i][j] = a;
			if (i == 0) break;
			if (j == 0) {
				list[i][j] += list[i - 1][j];
			}
			else if (j == i) {
				list[i][j] += list[i - 1][j - 1];
			}
			else {
				list[i][j] += max(list[i - 1][j], list[i - 1][j - 1]);
			}
		}
	}
	return *max_element(list[n - 1], list[n - 1] + n);
}

int main(void) {
	printf("%d", tri());
	return 0;
}


//////////////////////////////////////////////////////////////

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int tri() {
	int n, a;
	scanf("%d", &n);
	int *list = new int[n+1]();
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j >= 1; --j) {
			scanf("%d", &a);
			list[j] = max(list[j - 1], list[j]) + a;
		}
	}
	return *max_element(list + 1, list + n + 1);
}

int main(void) {
	printf("%d", tri());
	return 0;
}