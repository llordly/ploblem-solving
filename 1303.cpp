/*

*/

#include <iostream>
#include <string>
#include <queue>
#include <vector>




using namespace std;

typedef pair<int, int> P;


int n, m;

int board[101][101];
bool visited[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


int bfs(int row, int col, int team) {
    int cnt = 0;
    queue<P> q;

    visited[row][col] = true;
    q.push({row, col});

    while (!q.empty()) {
        P node = q.front();
        q.pop();
        cnt++;

        int x = node.first;
        int y = node.second;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (!visited[nx][ny] && board[nx][ny] == team) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    return cnt * cnt;
}




int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string line;
    cin >> n >> m;

    vector<P> me;
    vector<P> enemy;

    for (int i = 0; i < m; ++i) {
        cin >> line;
        for (int j = 0; j < n; ++j) {
            if (line[j] == 'W') {
                board[i][j] = 1;
                me.push_back({i, j});
            } else enemy.push_back({i, j});
        }
    }

    int my_score = 0;
    for (P w : me) {
        int row = w.first;
        int col = w.second;
        if (!visited[row][col]) my_score += bfs(row, col, 1);
    }


    int enemy_score = 0;
    for (P b : enemy) {
        int row = b.first;
        int col = b.second;

        if (!visited[row][col]) enemy_score += bfs(row, col, 0);
    }

    cout << my_score << " " << enemy_score;

    return 0;
}