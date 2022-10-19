// 16236

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int map[20][20] = {0};
int n;
int babyShark = 2;
int babyCount = 0;
int ans = 0;

pair<int, int> bfs(int start_col, int start_row) {
    bool visited[20][20] = {false};
    int dis[20][20] = {0};
    queue<pair<int, int>> q;
    visited[start_col][start_row] = true;
    q.push({start_col, start_row});
    
    while (!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();
        int x = node.first;
        int y = node.second;
        int size = map[x][y];
        if (size != 0 && size != 9 && size != babyShark) {
            int movement = dis[x][y];
            while (!q.empty()) {
                auto temp = q.front();
                q.pop();
                int temp_x = temp.first;
                int temp_y = temp.second;
                size = map[temp_x][temp_y];
                if (movement == dis[temp_x][temp_y] && size != 0 && size != 9 && size != babyShark){
                    if (x == temp_x) {
                        if (temp_y < y) {
                            x = temp_x;
                            y = temp_y;
                        }
                    } else if (temp_x < x) {
                        x = temp_x;
                        y = temp_y;
                    }
                }
            }
            babyCount++;
            if (babyCount == babyShark) {
                babyShark++;
                babyCount = 0;
            }
            map[x][y] = 0;
            map[start_col][start_row] = 0;
            ans += dis[x][y];
            return {x, y};
        }
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (map[nx][ny] <= babyShark && !visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    dis[nx][ny] = dis[x][y] + 1;
                }
            }
        }
    }
    return {-1, -1};
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int input;
    cin >> n;
    int start_col, start_row;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> input;
            map[i][j] = input;
            if (input == 9) {
                start_col = i;
                start_row = j;
            }
        }
    }
    
    pair<int, int> p = bfs(start_col, start_row);
    while (!(p.first == -1 && p.second == -1)) {
        p = bfs(p.first, p.second);
    }
    cout << ans;

    return 0;
}
