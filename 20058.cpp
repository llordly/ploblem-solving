//20058

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX_N (1 << 6)

using namespace std;

typedef pair<int, int> Ice;

inline int Max(int a, int b) {return a > b ? a : b;}

int board[MAX_N + 1][MAX_N + 1];
bool visited[MAX_N + 1][MAX_N + 1];
int N, Q, L;
int boardSize;


int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


// (row, col) -> (col, size - row - 1)
void rotateMatrix(int start_row, int start_col, int size) {
    vector<vector<int>> rotMat(size, vector<int>(size, 0));
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            rotMat[j][size - i - 1] = board[i + start_row][j + start_col];
        }
    }


    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            board[i + start_row][j + start_col] = rotMat[i][j];
        }
    }
}


void fireStorm(int row, int col, int L, int size) {
    if (size == L) {
        rotateMatrix(row, col, L);
        return;
    } else {
        int newSize = size / 2;
        fireStorm(row, col, L, newSize);
        fireStorm(row, col + newSize, L, newSize);
        fireStorm(row + newSize, col, L, newSize);
        fireStorm(row + newSize, col + newSize, L, newSize);
    }
}


void reduceIce() {
    vector<Ice> iceList;
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            int cnt = 0;
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize) {
                    if (board[nx][ny]) cnt++;
                }
            }
            if (cnt < 3) iceList.push_back({i, j});
        }
    }

    for (Ice ice : iceList) {
        int x = ice.first;
        int y = ice.second;

        if (board[x][y]) board[x][y]--;
    }
}

int getIceSum() {
    int ans = 0;

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            ans += board[i][j];
        }
    }

    return ans;
}


int getMass(int row, int col) {
    int cnt = 0;

    queue<Ice> q;
    visited[row][col] = true;

    q.push({row, col});

    while (!q.empty()) {
        Ice ice = q.front();
        q.pop();
        cnt++;

        int x = ice.first;
        int y = ice.second;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize) {
                if (!visited[nx][ny] && board[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }

    }
    return cnt;
}

int getMaxMass() {
    memset(visited, false, sizeof(visited));
    int ans = 0;
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (!visited[i][j] && board[i][j]) {
                int mass = getMass(i, j);
                ans = Max(ans, mass);
            }
        }
    }

    return ans > 1 ? ans : 0;
}


void run(int L) {
    fireStorm(0, 0, L, boardSize);
    reduceIce();
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> Q;

    boardSize = 1 << N;

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < Q; ++i) {
        cin >> L;
        run(1 << L);
    }

    cout << getIceSum() << "\n" << getMaxMass();


    return 0;
}
