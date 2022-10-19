// 14442
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>


using namespace std;

int n, m, k;

int arr[1001][1001];
int visited[1001][1001][11] = {0};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(int row, int col) {
    queue<tuple<int, int, int>> q;
    visited[row][col][0] = 1;
    q.push(make_tuple(row, col, 0));
    
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
       
        
        int x = get<0>(node);
        int y = get<1>(node);
        int boo = get<2>(node);
        
        if (get<0>(node) == n - 1 && get<1>(node) == m - 1) {
            return visited[x][y][boo];
        }
        
        for (int i = 0; i < 4; ++i) {
            int nx = get<0>(node) + dx[i];
            int ny = get<1>(node) + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (arr[nx][ny] == 1 && boo < k && !visited[nx][ny][boo + 1]) {
                    visited[nx][ny][boo + 1] = visited[x][y][boo] + 1;
                    q.push(make_tuple(nx, ny, boo + 1));
                }
                if (arr[nx][ny] == 0 && visited[nx][ny][boo] == 0) {
                    visited[nx][ny][boo] = visited[x][y][boo] + 1;
                    q.push(make_tuple(nx, ny, boo));
                }
            }
        }
    }
    return -1;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string num;

    cin >> n >> m >> k;
    
    for (int i = 0; i < n; ++i) {
        cin >> num;
        for (int j = 0; j < m; ++j) {
            arr[i][j] = num[j] - 48;
        }
    }
    
    cout << bfs(0, 0);
    
    return 0;
}
