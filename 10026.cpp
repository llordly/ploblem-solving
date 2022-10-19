// 10026

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<string> arr;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;

int bfs() {
    bool visited[101][101] = {false};
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j]) {
                continue;
            }
            visited[i][j] = true;
            queue<pair<int, int>> q;
            q.push({i, j});
            
            while (!q.empty()) {
                pair<int, int> node = q.front();
                q.pop();
                int x = node.first;
                int y = node.second;
                
                for (int k = 0; k < 4; ++k) {
                    int newX = x + dx[k];
                    int newY = y + dy[k];
                    if (0 <= newX && newX < n && 0 <= newY && newY < n) {
                        if (arr[newX][newY] == arr[x][y] && !visited[newX][newY] ) {
                            q.push({newX, newY});
                            visited[newX][newY] = true;
                        }
                    }
                }
            }
            ans++;
        }
    }
    return ans;
}

int bfs_colorBlind() {
    bool visited[101][101] = {false};
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j]) continue;
            
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;
            
            while (!q.empty()) {
                pair<int, int> node = q.front();
                q.pop();
                int x = node.first;
                int y = node.second;
                for (int k = 0; k < 4; ++k) {
                    int newX = x + dx[k];
                    int newY = y + dy[k];
                    if (0 <= newX && newX < n && 0 <= newY && newY < n) {
                        if (arr[newX][newY] == arr[x][y] && !visited[newX][newY]) {
                            q.push({newX, newY});
                            visited[newX][newY] = true;
                        } else if (((arr[newX][newY] == 'R' && arr[x][y] == 'G') || (arr[newX][newY] == 'G' && arr[x][y] == 'R')) && !visited[newX][newY]) {
                            q.push({newX, newY});
                            visited[newX][newY] = true;
                        }
                    }
                }
            }
            ans++;
        }
    }
    return ans;
}
    
    


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string line;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> line;
        arr.push_back(line);
    }
    cout << bfs() << " ";
    cout << bfs_colorBlind();
    return 0;
}

