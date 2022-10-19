// 7562
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int test;

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int bfs(int startRow, int startCol, int endRow, int endCol, int n) {
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    queue<pair<pair<int, int>, int>> q;
    visited[startRow][startCol] = true;
    q.push({{startRow, startCol}, 0});
    
    while(!q.empty()) {
        auto node = q.front();
        q.pop();
        
        int x = node.first.first;
        int y = node.first.second;
        int dis = node.second;
        
        if (x == endRow && y == endCol) {
            return dis;
            break;
        }
        
        
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (!visited[nx][ny]) {
                    q.push({{nx, ny}, dis + 1});
                    visited[nx][ny] = true;
                }
            }
        }
    }
    return 0;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int a, b, c, d;
    cin >> test;
    
    while(test--) {
        cin >> n;
        cin >> a >> b >> c >> d;
        cout << bfs(a, b, c, d, n) << "\n";
    }
    
    return 0;
}
