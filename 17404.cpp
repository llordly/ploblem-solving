// 17404
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stack>


using namespace std;


int n;

int dp[3][1001][3];

int Min(int a, int b, int weight) {
    if (a == 0 && b == 0) {
        return 0;
    }
    if (a == 0) {
        return b + weight;
    }
    if (b == 0) {
        return a + weight;
    }
    return a < b ? a + weight : b + weight;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    int r, g, b;
    
    for (int i = 1; i <= n; ++i) {
        cin >> r >> g >> b;
        if (i == 1) {
            dp[0][i][0] = r;
            dp[1][i][1] = g;
            dp[2][i][2] = b;
            continue;
        }
        
        if (i == n) {
            // red
            dp[0][i][1] = Min(dp[0][i - 1][0], dp[0][i - 1][2], g);
            dp[0][i][2] = Min(dp[0][i - 1][0], dp[0][i - 1][1], b);
            
            // green
            dp[1][i][0] = Min(dp[1][i - 1][1], dp[1][i - 1][2], r);
            dp[1][i][2] = Min(dp[1][i - 1][0], dp[1][i - 1][1], b);
            
            // blue
            dp[2][i][0] = Min(dp[2][i - 1][1], dp[2][i - 1][2], r);
            dp[2][i][1] = Min(dp[2][i - 1][0], dp[2][i - 1][2], g);
            break;
        }
        
        for (int j = 0; j < 3; ++j) {
            dp[j][i][0] = Min(dp[j][i - 1][1], dp[j][i - 1][2], r);
            dp[j][i][1] = Min(dp[j][i - 1][0], dp[j][i - 1][2], g);
            dp[j][i][2] = Min(dp[j][i - 1][0], dp[j][i - 1][1], b);
        }
    }
    
    int ans = 1e9;
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (dp[i][n][j] != 0) {
                ans = min(ans, dp[i][n][j]);
            }
        }
    }
    
    cout << ans;
    
    return 0;
}



