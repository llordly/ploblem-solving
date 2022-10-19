// 2638
#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int n, m;

vector<vector<int>> arr;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int nx = node.first + dx[i];
            int ny = node.second + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && (arr[nx][ny] == 0 || arr[nx][ny] == 2) && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                arr[nx][ny] = 2;
            }
        }
    }
}

bool cheese() {
    bool check = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == 1) {
                check = false;
                int temp = 0;
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (0 <= nx && nx < n && 0 <= ny && ny < m && arr[nx][ny] == 2) {
                        temp++;
                    }
                }
                if (temp >= 2) arr[i][j] = 0;
            }
        }
    }
    return check;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    arr.resize(n);
    
    int num;
    
    int x, y;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> num;
            arr[i].push_back(num);
            if (num == 0) {
                x = i;
                y = j;
            }
        }
    }
    int ans = 0;
    bfs(x, y);
    
    while (!cheese()) {
        ans++;
        bfs(x, y);
    }
    
    cout << ans;
    
    
   
    return 0;
}
