// 9465

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dp[2][100001];
int arr[2][100001];

int Max(int a, int b) {
    return a > b ? a : b;
}

int sticker(int n) {
    dp[0][1] = arr[0][1];
    dp[1][1] = arr[1][1];
    
    for (int i = 2; i <= n; ++i) {
        dp[0][i] = Max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
        dp[1][i] = Max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
    }
    return Max(dp[0][n], dp[1][n]);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t, n, num;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        for (int j = 0; j < 2; ++j) {
            for (int k = 1; k <= n; ++k) {
                cin >> num;
                arr[j][k] = num;
            }
        }
        cout << sticker(n) << "\n";
    }
    
    return 0;
}
