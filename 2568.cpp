// 2568
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stack>


using namespace std;


int n;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    vector<pair<int, int>> arr;
    int l, r;
    
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        arr.push_back({l, r});
    }
    
    sort(arr.begin(), arr.end());
    
    vector<int> dp;
    vector<int> pos;
    
    dp.push_back(arr[0].second);
    pos.push_back(0);
    
    for (int i = 1; i < arr.size(); ++i) {
        if (dp.back() < arr[i].second) {
            dp.push_back(arr[i].second);
            pos.push_back(dp.size() - 1);
        } else {
            int idx = lower_bound(dp.begin(), dp.end(), arr[i].second) - dp.begin();
            dp[idx] = arr[i].second;
            pos.push_back(idx);
        }
    }
    
    
    cout << n - dp.size() << "\n";
    
    
    stack<int> ans;
    int cnt = dp.size() - 1;
    
    
    for (int i = pos.size() - 1; i >= 0; --i) {
        if (pos[i] == cnt) {
            cnt--;
        } else {
            ans.push(arr[i].first);
        }
    }
    
    while (!ans.empty()) {
        cout << ans.top() << "\n";
        ans.pop();
    }
    
    return 0;
}



