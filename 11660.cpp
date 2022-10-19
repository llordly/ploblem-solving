// 11660
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int n, m;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num, x1, y1, x2, y2;
    cin >> n >> m;
    vector<vector<long long>> arr(n + 1, vector<long long>(n + 1, 0));
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> num;
            arr[i][j] = num;
        }
    }
    
    dp[1][1] = arr[1][1];
    for (int i = 2; i <= n; ++i) {
        dp[i][1] = dp[i - 1][1] + arr[i][1];
        dp[1][i] = dp[1][i - 1] + arr[1][i];
    }
    

    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + arr[i][j];
        }
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        long long ans = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
        cout << ans << "\n";
    }
    
    return 0;
}


