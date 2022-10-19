//11726

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int dp[1001];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    cin >> n;
    if (n > 2) {
        for (int i = 3; i <= n; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
        }
    }
    cout << dp[n];
    return 0;
}

