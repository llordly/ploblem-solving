// 16474
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int l[2002];
int r[2002];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;

    cin >> n >> m;

    vector<vector<int>> A(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> num;
        l[num] = i;
    }

    for (int i = 1; i <= m; ++i) {
        cin >> num;
        r[num] = i;
    }

    cin >> k;
    int a, b;

    for (int i = 0; i < k; ++i) {
        cin >> a >> b;
        A[l[a]].push_back(r[b]);
    }


    for (int i = 1; i <= n; ++i) {
        sort(A[i].begin(), A[i].end(), greater<int>());
    }


    vector<int> dp;
    
    for (int i = 1; i <= n; ++i) {
        for (int x : A[i]) {
            if (dp.empty() || dp.back() < x) {
                dp.push_back(x);
            } else {
                dp[lower_bound(dp.begin(), dp.end(), x) - dp.begin()] = x;
            }
        }
    }


    cout << k - dp.size();

    return 0;
}
