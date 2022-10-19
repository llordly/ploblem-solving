//21611

#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, int> Pos;

vector<Pos> posOrder;
int posOrderIdx[50][50];
Pos shark;


int board[50][50];



int posX[4] = {1, 0, -1, 0};
int posY[4] = {0, 1, 0, -1};

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};


int N, M;
int marbleSize;


void traverse(int n) {
    int num = 0;
    int r = n/2;
    int c = n/2;
    c -= 1;

    int level = 0;


    while (num < n * n - 1) {
        int d = level * 2 + 1;

        for (int i = 0; i < d; ++i) {
            posOrder.push_back({r, c});
            posOrderIdx[r][c] = num++;
            r += posX[0];
            c += posY[0];
        }

        for (int i = 0; i < d + 1; ++i) {
            posOrder.push_back({r, c});
            posOrderIdx[r][c] = num++;
            r += posX[1];
            c += posY[1];
        }

        for (int i = 0; i < d + 1; ++i) {
            posOrder.push_back({r, c});
            posOrderIdx[r][c] = num++;
            r += posX[2];
            c += posY[2];
        }

        for (int i = 0; i < d + 2; ++i) {
            posOrder.push_back({r, c});
            posOrderIdx[r][c] = num++;
            r += posX[3];
            c += posY[3];
        }
        level++;

    }
}


void removeTail(int size) {
    for (int i = marbleSize - 1; i >= marbleSize - size; --i) {
        board[posOrder[i].first][posOrder[i].second] = 0;
    }
    marbleSize -= size;
}


void blizard(int d, int s) {
    vector<Pos> destroyedMarble;
    int x = shark.first;
    int y = shark.second;
    for (int i = 0; i < s; ++i) {
        x += dx[d];
        y += dy[d];

        if (x >= 0 && x < N && y >= 0 && y < N) {
            if (board[x][y]) {
                board[x][y] = 0;
                destroyedMarble.push_back({x, y});
            }
        }
    }

    for (int i = destroyedMarble.size() - 1; i >= 0; --i) {
        int idx = posOrderIdx[destroyedMarble[i].first][destroyedMarble[i].second];

        for (int j = idx; j < N * N - 1; ++j) {
            int temp = board[posOrder[j + 1].first][posOrder[j + 1].second];

            if (temp == 0) break;
            else {
                board[posOrder[j].first][posOrder[j].second] = temp;
            }
        }
    }

    removeTail(destroyedMarble.size());
}


int dfs(int num, int cnt) {
    if (num == 0) {
        return cnt;
    }
    if (board[posOrder[cnt].first][posOrder[cnt].second] == num) {
        return dfs(num, cnt + 1);
    } else {
        return cnt;
    }
}



int explosion() {
    int cnt = 0;

    while (true) {
        vector<Pos> bombList;
        for (int i = 0; i < posOrder.size(); ++i) {
            int marbleNum = board[posOrder[i].first][posOrder[i].second];
            if (marbleNum == 0) break;
            int endPos = dfs(marbleNum, i + 1);
           
            if ((endPos - i) >= 4) {
                bombList.push_back({i, endPos});
                cnt += marbleNum * (endPos - i);
                i = endPos;
            }
        }
        if (bombList.size() == 0) break;

        for (int i = bombList.size() - 1; i >= 0; --i) {
            int bombSize = bombList[i].second - bombList[i].first;
            for (int j = bombList[i].first; j < N * N - bombSize; ++j) {
                int temp = board[posOrder[j + bombSize].first][posOrder[j + bombSize].second];

                if (temp == 0) break;
                else {
                    board[posOrder[j].first][posOrder[j].second] = temp;
                }
            }
            removeTail(bombSize);
        }
    }
    return cnt;
}


void groupingMarble() {
    // A and B pair
    vector<Pos> groupList;
    for (int i = 0; i < posOrder.size();) {
            int marbleNum = board[posOrder[i].first][posOrder[i].second];

            if (marbleNum == 0) break;
            int endPos = dfs(marbleNum, i + 1);
            groupList.push_back({endPos - i, marbleNum});
            i = endPos;
        }

    memset(board, 0, sizeof(board));

    int idx = 0;

    for (auto marble : groupList) {
        board[posOrder[idx].first][posOrder[idx].second] = marble.first;
        idx++;
        if (idx >= N * N - 2) break;
        board[posOrder[idx].first][posOrder[idx].second] = marble.second;
        if (idx >= N * N - 2) break;
        idx++;
    }
    marbleSize = idx;
}


int run(int d, int s) {
    int ans;
    blizard(d, s);
    ans = explosion();
    groupingMarble();
    return ans;
}




int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int d, s;
    int ans = 0;

    cin >> N >> M;

    traverse(N);
    shark = {N/2, N/2};

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
            if (board[i][j]) marbleSize++;
        }
    }

    for (int i = 0; i < M; ++i) {
        cin >> d >> s;
        ans += run(d, s);
    }

    cout << ans;
    
    return 0;
}