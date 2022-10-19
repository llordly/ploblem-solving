// 7569

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int arr[101][101][101];
bool visited[101][101][101] = {false};
int dis[101][101][101];

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int n, m, h;
int ans;
bool start = true;
queue<tuple<int, int, int>> q;

void bfs() {
    while (!q.empty()) {
        tuple<int, int, int> node = q.front();
        q.pop();
        int x = get<0>(node);
        int y = get<1>(node);
        int z = get<2>(node);
        
        for (int l = 0; l < 6; ++l) {
            int newX = x + dx[l];
            int newY = y + dy[l];
            int newZ = z + dz[l];
            if (0 <= newX && newX < n && 0 <= newY && newY < m && 0 <= newZ && newZ < h) {
                if (arr[newX][newY][newZ] == 0 && !visited[newX][newY][newZ] ) {
                    arr[newX][newY][newZ] = 1;
                    q.push({newX, newY, newZ});
                    visited[newX][newY][newZ] = true;
                    dis[newX][newY][newZ] = dis[x][y][z] + 1;
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int input;
    cin >> m >> n >> h;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                cin >> input;
                arr[j][k][i] = input;
                if (input == 1) {
                    visited[j][k][i] = true;
                    q.push({j, k, i});
                }
                if (input == 0) start = false;
            }
        }
    }
    bool possible = true;
    int ans = 0;
    if (start) {
        cout << "0";
    } else {
        bfs();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < h; ++k) {
                    if (arr[i][j][k] == 0) {
                        possible = false;
                    }
                    if (ans < dis[i][j][k]) {
                        ans = dis[i][j][k];
                    }
                }
            }
        }
        if (possible) cout << ans;
        else cout << "-1";
    }
    return 0;
}

