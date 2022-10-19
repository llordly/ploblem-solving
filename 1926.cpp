// 1926
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
int arr[501][501];

bool visited[501][501];
int n, m, cnt, ans;

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
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(!visited[nx][ny] && arr[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
//                    cout << "nx : " << nx << " ny : " << ny << "\n";
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
    
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && arr[i][j]) {
                ans = Max(ans, bfs(i, j));
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    cout << ans;
    
    return 0;
}
