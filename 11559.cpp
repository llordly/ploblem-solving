/*
11559 Puyo Puyo
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>


using namespace std;

typedef pair<int, int> P;

// R G B P Y


int board[12][6];
int visited[12][6];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};




void print_board() {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (board[i][j] == 0) cout << ".";
            else cout << (char)(board[i][j] + 'A');
        }
        cout << "\n";
    }
}


bool bfs(int row, int col) {
    visited[row][col] = 1;
    queue<P> q;
    vector<P> popList;

    q.push({row, col});
    popList.push_back({row, col});

    int color = board[row][col];
    int cnt = 0;

    while (!q.empty()) {
        P node = q.front();
        q.pop();

        cnt++;

        for (int i = 0; i < 4; ++i) {
            int nx = node.first + dx[i];
            int ny = node.second + dy[i];

            if (nx >= 0 && nx < 12 && ny >= 0 && ny < 6) {
                if (!visited[nx][ny] &&  (board[nx][ny] == color)) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                    popList.push_back({nx, ny});
                }
            }
        }
        
    }

    if (cnt >= 4) {
        for (P pos : popList) {
            int x = pos.first;
            int y = pos.second;

            board[x][y] = 0;
        }
        return true;
    } else return false;
}


void downColor() {
    for (int k = 11; k >= 0; --k) {
        for (int i = 0; i < 6; ++i) {
            int idx = 0;
            for (int j = k; j >= 0; --j) {
                if (board[j][i] != 0) {
                    break;
                } else {
                    idx++;
                }
            }
            if (idx == 0) continue;
            for (int j = k; j >= idx; --j) {
                board[j][i] = board[j - idx][i];
                board[j - idx][i] = 0;
            }
        }
    }
    
}




int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string line;

    for (int i = 0; i < 12; ++i) {
        cin >> line;
        for (int j = 0; j < 6; ++j) {
            if (line[j] != '.') {
                board[i][j] = line[j] - 'A';
            }
        }
    }

    bool check = false;
    int ans = 0;
    while (true) {
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (!visited[i][j] && (board[i][j] != 0)) {
                    if(bfs(i, j)) {
                        check = true;
                    }
                }
            }
        }
       
        if (check) {
            ans++;
            downColor();
            check = false;
        } else {
            break;
        }
    }

    cout << ans;


}