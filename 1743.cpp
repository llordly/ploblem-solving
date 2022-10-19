// 1743
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>

using namespace std;

int Max(int a, int b) {
    return a > b ? a : b;
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int arr[101][101];

bool visited[101][101];
int n, m, k, ans;

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({x, y});
    int c = 0;
    
    while (!q.empty()) {
        auto node = q.front();
        int xx = node.first;
        int yy = node.second;
        q.pop();
        c++;
        
        for (int i = 0; i < 4; ++i) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                if(!visited[nx][ny] && arr[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
    return c;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;
    int r, c;
    
    
    for (int i = 0; i < k; ++i) {
        cin >> r >> c;
        arr[r][c] = 1;
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!visited[i][j] && arr[i][j]) {
                ans = Max(ans, bfs(i, j));
            }
        }
    }

    cout << ans;
    
    return 0;
}
