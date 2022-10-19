// 11053
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, num;
    cin >> n;
    vector<int> dp;
    cin >> num;
    dp.push_back(num);
    
    for (int i = 1; i < n; ++i) {
        cin >> num;
        if (dp.back() < num) dp.push_back(num);
        else {
            dp[lower_bound(dp.begin(), dp.end(), num) - dp.begin()] = num;
        }
    }
    
    cout << dp.size();
    
    return 0;
}


