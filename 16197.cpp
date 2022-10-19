/*

*/

#include <iostream>
#include <string>
#include <vector>


using namespace std;


typedef pair<int, int> P;


int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

// 벽 = -1, 동전 = 1, 빈칸 = 0
int board[21][21];
int n, m;

int ans = 1e9;

int Min(int a, int b) { return a < b ? a : b; }


// 빈 칸 처리를 먼저하기!

// 벽이면 이동하지 않는다.
// index 넘으면 떨어진다.
// 이외의 경우에는 이동한다.

// 중복순열에 기반하여 탐색을 하되 10번 이상인건 리턴시켜버리면 된다.


void backtracking(int cnt, vector<P> coinPos) {
    // cout << "cnt: " << cnt << "\n";
    // 10번 초과일 경우 탈락
    if (cnt > 10) {
        return;
    }

    // 두 개 다 떨어졌을 경우도 탈락
    if (coinPos.size() == 0) {
        return;
    }
    
    // 한 개만 떨어졌을 때 최솟값 갱신
    if (coinPos.size() == 1) {
        // cout << "ans : " << ans << "\n";
        ans = Min(ans, cnt);
        return;
    }
    
    // 동전 두 개가 겹쳤을 경우, 하나만 떨어지는 경우의 수는 존재하지 않는다.
    if (coinPos[0].first == coinPos[1].first && coinPos[0].second == coinPos[1].second) {
        return;
    }


    for (int i = 0; i < 4; ++i) {
        // 떨어졌는지 유무
        int drop1 = false;
        int drop2 = false;

        // 이동 유무
        int move1 = false;
        int move2 = false;


        int x1 = coinPos[0].first;
        int y1 = coinPos[0].second;
        int nx1 = x1 + dx[i];
        int ny1 = y1 + dy[i];

        int x2 = coinPos[1].first;
        int y2 = coinPos[1].second;
        int nx2 = x2 + dx[i];
        int ny2 = y2 + dy[i];

        // 벽 = -1, 동전 = 1, 빈칸 = 0
        if (nx1 >= 0 && nx1 < n && ny1 >= 0 && ny1 < m) {
            if (board[nx1][ny1] != -1) {
                // 벽이 아닐 경우 이동 => 새로운 좌표가 코인의 좌표, 원래 자리는 빈칸으로 바꿔줌
                board[nx1][ny1] = 0;
                move1 = true;
            }
        } else {
            // 떨어짐
            drop1 = true;
        }

        if (nx2 >= 0 && nx2 < n && ny2 >= 0 && ny2 < m) {
            if (board[nx2][ny2] != -1) {
                board[nx2][ny2] = 0;
                move2 = true;
            }
        } else {
            drop2 = true;
        }   


        vector<P> new_coinPos;
        if (!drop1) {
            if (move1) {
            new_coinPos.push_back({nx1, ny1});
            board[nx1][ny1] = 1;
            } else new_coinPos.push_back({x1, y1});
        }

        if (!drop2) {
            if (move2) {
            new_coinPos.push_back({nx2, ny2});
            board[nx2][ny2] = 1;
            } else new_coinPos.push_back({x2, y2});
        }

        for (P p : new_coinPos) {
            // cout << "{" << p.first << ", " << p.second << "} ";
        }
        // cout << "\n";
        // 백트래킹으로 탐색
        backtracking(cnt + 1, new_coinPos);
        // 탐색하고 돌아오면 보드 상태 원래대로
        
        if (move1) {
            board[nx1][ny1] = 0;
        }

        if (move2) {
            board[nx2][ny2] = 0;
        }

        board[x1][y1] = 1;
        board[x2][y2] = 1; 
    }

}



int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string line;
    vector<P> coin;

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> line;
        for (int j = 0; j < m; ++j) {
            if (line[j] == 'o') {
                board[i][j] = 1;
                coin.push_back({i, j});
            } else if (line[j] == '#') {
                board[i][j] = -1;
            }
        }
    }

    backtracking(0, coin);

    if (ans < 1e9) cout << ans;
    else cout << -1;

    return 0;
}