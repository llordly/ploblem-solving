// 17070
#include <iostream>
#include <vector>

using namespace std;

int n;

int arr[17][17];
int dp[17][17][3];

bool checkRow(int row, int col){
    if (col + 1 < n && !arr[row][col + 1]) return true;
    else return false;
}

bool checkCol(int row, int col) {
    if (row + 1 < n && !arr[row + 1][col]) return true;
    else return false;
}

bool checkDia(int row, int col) {
    if (col + 1 == n) return false;
    if (row + 1 == n) return false;
    
    if (!arr[row][col + 1] && !arr[row + 1][col] && !arr[row + 1][col + 1]) return true;
    else return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    
    dp[0][1][0] = 1;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            //row
            if (checkRow(i, j)) {
                dp[i][j + 1][0] += dp[i][j][0] + dp[i][j][2];
            }
            
            //col
            if (checkCol(i, j)) {
                dp[i + 1][j][1] += dp[i][j][1] + dp[i][j][2];
            }
            
            //diagonal
            if (checkDia(i, j)) {
                dp[i + 1][j + 1][2] += dp[i][j][0] + dp[i][j][1] +dp[i][j][2];
            }
        }
    }
    
    cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
    
    return 0;
}
