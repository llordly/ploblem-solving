// 1987
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int r, c;

int arr[21][21];

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

int ans, visited;

void backtracking(int row, int col, int cnt) {
    for (int i = 0; i < 4; ++i) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (nr >= 0 && nr < r && nc >= 0 && nc < c) {
            if (!(visited & (1 << arr[nr][nc]))) {
                visited |= (1 << arr[nr][nc]);
                backtracking(nr, nc, cnt + 1);
                visited ^= (1 << arr[nr][nc]);
            }
        }
    }
    ans = max(ans, cnt);
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string input;
    
    cin >> r >> c;
    
    for (int i = 0; i < r; ++i) {
        cin >> input;
        for (int j = 0; j < c; ++j) {
            arr[i][j] = input[j] - 'A';
        }
    }
    visited |= 1 << arr[0][0];
    
    backtracking(0, 0, 1);
    
    cout << ans;
 
  
    return 0;
}



