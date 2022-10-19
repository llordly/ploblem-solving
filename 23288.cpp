#include <iostream>
#include <queue>
#include <cstring>


using namespace std;

int board[21][21];

// 동 남 서 북 순서
int direct = 0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

pair<int, int> dicePos = {0, 0};

void rotClock() {
    direct = direct + 1 <= 3 ? direct + 1 : 0;
}

void rotCounterClock() {
    direct = direct - 1 >= 0 ? direct - 1 : 3;
}

void anotherSide() {
    direct = (direct + 2) % 4;
}

int dice[4][3] = {{0, 2, 0}, {4, 1, 3}, {0, 5, 0}, {0, 6, 0}};

int ans;


// hard coding
void East() {
    int temp1 = dice[1][2];
    int temp2 = dice[3][1];

    dice[1][2] = dice[1][1];
    dice[1][1] = dice[1][0];
    dice[1][0] = temp2;
    dice[3][1] = temp1;
}

void South() {
    int temp = dice[3][1];

    dice[3][1] = dice[2][1];
    dice[2][1] = dice[1][1];
    dice[1][1] = dice[0][1];
    dice[0][1] = temp;
}

void West() {
    int temp1 = dice[1][0];
    int temp2 = dice[3][1];

    dice[1][0] = dice[1][1];
    dice[1][1] = dice[1][2];
    dice[1][2] = temp2;
    dice[3][1] = temp1;
}

void North() {
    int temp = dice[0][1];

    dice[0][1] = dice[1][1];
    dice[1][1] = dice[2][1];
    dice[2][1] = dice[3][1];
    dice[3][1] = temp;
}

int getFloor() {
    return dice[3][1];
}

void rollDice() {
    switch (direct)
    {
    case 0:
        East();
        break;
    case 1:
        South();
        break;
    case 2:
        West();
        break;
    case 3:
        North();
        break;
    default:
        break;
    }
}



int n, m, k;


int get_score(int row, int col, int num) {
    int cnt = 0;
    bool visited[21][21];
    memset(visited, false, sizeof(visited));

    visited[row][col] = true;
    queue<pair<int, int>> q;
    q.push({row, col});

    while (!q.empty()) {
        auto node = q.front();
        int x = node.first;
        int y = node.second;
        q.pop();
        cnt++;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visited[nx][ny] && board[nx][ny] == num) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
    return cnt * num;
}

void run() {
    int nx = dicePos.first + dx[direct];
    int ny = dicePos.second + dy[direct];
    if (!(nx >= 0 && nx < n && ny >= 0 && ny < m)) {
        anotherSide();
        nx = dicePos.first + dx[direct];
        ny = dicePos.second + dy[direct];
    }

    dicePos.first = nx;
    dicePos.second = ny;
    rollDice();

    int a = getFloor();
    int b = board[nx][ny];

    ans += get_score(nx, ny, b);

    if (a > b) rotClock();

    if (a < b) rotCounterClock();
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < k; ++i) {
        run();
    }

    cout << ans;


    return 0;
}