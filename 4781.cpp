//4781

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cstring>

using namespace std;

int n, c;
double m, p;


int dp[10001];

int ans;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0.00) break;
        
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; ++i) {
            cin >> c >> p;
            int idx = (int)(p * 100 + 0.5);
            
            for (int j = idx; j <= (int)(m * 100 + 0.5); ++j) {
                dp[j] = max(dp[j - idx] + c, dp[j]);
            }
        }
        cout << dp[(int)(m * 100 + 0.5)] << "\n";
    }



    return 0;
}




