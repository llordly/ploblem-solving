// 3745
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis(int n) {
    vector<int> dp;
    int num;
    cin >> num;
    dp.push_back(num);
    for (int i = 1; i < n; ++i) {
        cin >> num;
        if (num > dp.back()) {
            dp.push_back(num);
        } else {
            int pos = lower_bound(dp.begin(), dp.end(), num) - dp.begin();
            dp[pos] = num;
        }
    }
    return dp.size();
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    
    while(cin >> n) {
        cout << lis(n) << "\n";
    }
    
    
    return 0;
}



