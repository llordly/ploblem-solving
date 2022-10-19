// 14002
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, num;
    int cnt = 0;
    cin >> n;
    vector<int> a, dp, v;
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        a.push_back(num);
    }
    
    dp.push_back(a[0]);
    v.push_back(0);
    for (int i = 1; i < n; ++i) {
        if (dp.back() < a[i]) {
            dp.push_back(a[i]);
            v.push_back(dp.size() - 1);
        }
        else {
            int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            dp[pos] = a[i];
            v.push_back(pos);
        }
    }
    
    cnt = dp.size() - 1;
    
    for (int i = v.size() - 1; i >= 0; --i) {
        if (v[i] == cnt) {
            cnt--;
            s.push(a[i]);
        }
    }
    
    cout << s.size() << "\n";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    
    return 0;
}


