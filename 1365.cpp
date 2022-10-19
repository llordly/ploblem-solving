// 1365
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, port;
    cin >> n;
    vector<int> dp;
    cin >> port;
    dp.push_back(port);
    
    for (int i = 1; i < n; ++i) {
        cin >> port;
        if (port > dp.back()) {
            dp.push_back(port);
        } else {
            dp[lower_bound(dp.begin(), dp.end(), port) - dp.begin()] = port;
        }
    }
    
    cout << n - dp.size();
    
    return 0;
}


