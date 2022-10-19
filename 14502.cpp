// 14502

#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;
vector<vector<int>> arr(9, vector<int>(9, 0));
vector<pair<int, int>> startPoint;
vector<pair<int, int>> hole;

vector<vector<int>> bfs(int row, int col, vector<vector<int>> arr) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    
    q.push({row, col});
    visited[row][col] = true;
    
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        int x = node.first;
        int y = node.second;
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (!visited[nx][ny] && arr[nx][ny] == 0) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    arr[nx][ny] = 2;
                }
            }
        }
    }
    return arr;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;
    cin >> n >> m;
    int ans = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> num;
            arr[i][j] = num;
            if (num == 2) startPoint.push_back({i, j});
            if (num == 0) hole.push_back({i, j});
        }
    }
    
    for (int i = 0; i < hole.size(); ++i) {
        auto one = hole[i];
        int x1 = one.first;
        int y1 = one.second;
        vector<vector<int>> temp;
        for (int j = i + 1; j < hole.size(); ++j) {
            auto two = hole[j];
            int x2 = two.first;
            int y2 = two.second;
            for (int k = j + 1; k < hole.size(); ++k) {
                auto three = hole[k];
                int x3 = three.first;
                int y3 = three.second;
                temp = arr;
                temp[x1][y1] = 1;
                temp[x2][y2] = 1;
                temp[x3][y3] = 1;
                for (auto x : startPoint) {
                    temp = bfs(x.first, x.second, temp);
                }
                int result = 0;
                for (int x = 0; x < n; ++x) {
                    for (int y = 0; y < m; ++y) {
                        if (temp[x][y] == 0) result++;
                    }
                }
                if (result > ans) ans = result;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
