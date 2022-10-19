// 1806
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;


int n, s;
int arr[100001];

int Min(int a, int b) { return a < b ? a : b; }

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> s;
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int sum = 0;
    int min = 100002;
    int start = 0;
    int end = 0;
    
    while (end <= n) {
        if (sum >= s) {
            min = Min(min, end - start);
            sum -= arr[start++];
        }
        if (sum < s) {
            sum += arr[end++];
        }
    }
    
    if (min == 100002) cout << 0;
    else cout << min;
    
    return 0;
}
