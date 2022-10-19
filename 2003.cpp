// 2003
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>

using namespace std;

int arr[10001];

int n, m;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int start = 0;
    int end = 0;
    int sum = 0;
    int ans = 0;
    
    while (end <= n) {
        if (sum >= m) {
            sum -= arr[start++];
        }
        if (sum < m) {
            sum += arr[end++];
        }
        if (sum == m) {
            ans++;
        }
    }
    
    cout << ans;
    

    return 0;
}
