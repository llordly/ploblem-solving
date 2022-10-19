// 11404
#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

int n, m;

int Min(int a, int b) {
    return a > b ? b : a;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
    
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 0;
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        dp[a][b] = Min(dp[a][b], c);
    }

    
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = Min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dp[i][j] != INF) cout << dp[i][j];
            else cout << 0;
            cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
