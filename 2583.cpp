// 2583
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
int cnt;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int arr[101][101];
bool visited[101][101];

int bfs(int row, int col) {
    int ans = 0;
    queue<pair<int, int>> q;
    visited[row][col] = true;
    q.push({row, col});
    arr[row][col] = 1;
    
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        ans++;
        
        int x = node.first;
        int y = node.second;
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (!visited[nx][ny] && arr[nx][ny] == 0) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    arr[nx][ny] = 1;
                }
            }
        }
    }
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m >> n >> k;
    int lx, ly, rx, ry;
    vector<int> ans;
    
    for (int i = 0; i < k; ++i) {
        cin >> lx >> ly >> rx >> ry;
        for (int j = ly; j < ry; ++j) {
            for (int k = lx; k < rx; ++k) {
                arr[j][k] = 1;
            }
        }
    }
    
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == 0) {
                ans.push_back(bfs(i, j));
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    sort(ans.begin(), ans.end());
    
    for (int i : ans) cout << i << " ";
    
    
    return 0;
}
