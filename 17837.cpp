/*
*/

#include <iostream>
#include <vector>


using namespace std;

typedef pair<int, int> Horse;
typedef pair<pair<int, int>, int> Pos;

int n, k;
int finish;



vector<Horse> horses[13][13];
int board[13][13];


// 오 왼 위 아
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};


// 반대방향 return
int redir(int dir) {
    if (dir == 1) return 0;
    if (dir == 0) return 1;
    if (dir == 2) return 3;
    if (dir == 3) return 2;
    return -1;
}


// 해당 번호의 말이 존재하는 위치를 반환 + 말이 몇 번 높이에 있는지도 반환
Pos find_pos(int horseNum) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < horses[i][j].size(); ++k) {
                if (horses[i][j][k].first == horseNum) {
                    return {{i, j}, k};
                }
            }
        }
    }
    return {{0, 0}, 0};
}


// blue일 때 true return
bool isBlue(int row, int col) {
    if (!(row >= 0 && row < n && col >= 0 && col < n)) return true;
    if (board[row][col] == 2) return true;
    return false;
}

bool isRed(int row, int col) {
    if (board[row][col] == 1) return true;
    return false;
}

bool isWhite(int row, int col) {
    if (board[row][col] == 0) return true;
    return false;
}


void isWhiteRed(int x, int y, int nx, int ny, int idx) {
    if (isWhite(nx, ny)) {
        // 흰색일 때 -> 자기 위에있는 거랑 통채로 이동
        int horseSize = horses[x][y].size();
        int cnt = horseSize - idx + horses[nx][ny].size();
        // 이동했을 때 4이상이면 종료 플래그
        if (cnt >= 4) {
            finish = 1;
            return;
        }

        // 자신부터 시작해서 위에 모든것을 다음칸에 말 리스트에 붙인다.
        for (int start = idx; start < horseSize; ++start) {
            horses[nx][ny].push_back({horses[x][y][start].first, horses[x][y][start].second});
        }

        // 이동했으니까 원래는 지워준다. size - idx 만큼 지워주면 된다!
        for (int start = idx; start < horseSize; ++start) {
            horses[x][y].pop_back();
        }
    } else if (isRed(nx, ny)) {
        // 빨간색 일때 -> 자기 위에있는 거랑 통채로 이동하는데 거꾸로 뒤집어서 이동한다.
        int horseSize = horses[x][y].size();
        int cnt = horseSize - idx + horses[nx][ny].size();
        if (cnt >= 4) {
            finish = 1;
            return;
        }

        // 자신부터 시작해서 위에 모든것을 다음칸에 말 리스트에 붙인다.
        for (int end = horseSize - 1; end >= idx; --end) {
            horses[nx][ny].push_back({horses[x][y][end].first, horses[x][y][end].second});
        }

        // 이동했으니까 원래는 지워준다. size - idx 만큼 지워주면 된다!
        for (int end = horseSize - 1; end >= idx; --end) {
            horses[x][y].pop_back();
        }
    }
}


bool run() {
    for (int i = 0; i < k; ++i) {
        // 우선 말의 위치를 찾음
        Pos horsePos = find_pos(i);
        int x = horsePos.first.first;
        int y = horsePos.first.second;
        int idx = horsePos.second;
        int dir = horses[x][y][idx].second;

        int nx = x + dx[dir];
        int ny = y + dy[dir];


        // 파란색일 경우부터 시작
        if (isBlue(nx, ny)) {
            // 방향 반대로
            dir = redir(dir);

            // 반대 방향으로 이동하기
            int nx2 = x + dx[dir];
            int ny2 = y + dy[dir];
            horses[x][y][idx].second = dir;
            // 이동했는데도 파란칸이면 -> 이동하지 않는다.
            if (isBlue(nx2, ny2)) {
                // 이동하지 않고 방향만 바꾼다.
            } else {
                isWhiteRed(x, y, nx2, ny2, idx);
            }  
        } else {
            isWhiteRed(x, y, nx, ny, idx);
        }
        // print_board();
        if (finish) {
            return true;
        }
    }
    return false;
}



int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    int a, b, c;

    for (int i = 0; i < k; ++i) {
        cin >> a >> b >> c;
        horses[a - 1][b - 1].push_back({i, c - 1});
    }

    int ans = -1;
    for (int i = 1; i <= 1001; ++i) {
        if (run()) {
            ans = i;
            break;
        }
    }

    cout << ans;


    return 0;
}