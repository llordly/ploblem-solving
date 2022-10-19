// 2565
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

int n;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    vector<pair<int, int>> arr;
    
    int a, b;
    
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        arr.push_back({a, b});
    }
    
    sort(arr.begin(), arr.end());
    
    vector<int> dp;
    dp.push_back(arr[0].second);
    
    for (int i = 1; i < n; ++i) {
        if (arr[i].second > dp.back()) {
            dp.push_back(arr[i].second);
        } else {
            int idx = lower_bound(dp.begin(), dp.end(), arr[i].second) - dp.begin();
            dp[idx] = arr[i].second;
        }
    }
    
    cout << n - dp.size();

    return 0;
}
