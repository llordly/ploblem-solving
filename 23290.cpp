//23290

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cstring>
#include <string>


using namespace std;

typedef pair<pair<int, int>, int> Fish;

vector<Fish> fishes;
vector<Fish> copiedFishes;
vector<int> board[4][4];
int sharkMoveList[64][3];

int smell[4][4];

int dfx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dfy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int dsx[4] = { -1, 0, 1, 0 };
int dsy[4] = { 0, -1, 0, 1 };


int M, S, sx, sy;


int cal_count() {
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ans += board[i][j].size();
        }
    }
    return ans;
}

void board_to_vector() {
    fishes = vector<Fish>();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int d : board[i][j]) {
                fishes.push_back({{i, j}, d});
            }
        }
    }
}

void cal_shark_moveList() {
    int idx = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                sharkMoveList[idx][0] = i;
                sharkMoveList[idx][1] = j;
                sharkMoveList[idx][2] = k;
                idx++;
            }
        }
    }
}


void reset_board() {
     for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            board[i][j] = vector<int>();
        }
    }
}


void copyFish() {
    for (Fish fish : copiedFishes) {
        fishes.push_back(fish);
        board[fish.first.first][fish.first.second].push_back(fish.second);
    }
}

void moveFish() {
    board_to_vector();
    reset_board();
    copiedFishes = fishes;
    for (int i = 0; i < fishes.size(); ++i) {
        int x = fishes[i].first.first;
        int y = fishes[i].first.second;
        int d = fishes[i].second;

        int idx = d;

        while (true) {
            int nx = x + dfx[idx];
            int ny = y + dfy[idx];


            if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
                if (smell[nx][ny] == 0 && !(sx == nx && sy == ny)) {
                    fishes[i].first.first = nx;
                    fishes[i].first.second = ny;
                    fishes[i].second = idx;
                    break;
                }
            }
            idx--;
            if(idx < 0) idx = 7;
            if (idx == d) break;
        }
        board[fishes[i].first.first][fishes[i].first.second].push_back(fishes[i].second);
    }
}

void moveShark() {
    int max = -1;
    int maxIdx = -1;

    for (int i = 0; i < 64; ++i) {
        bool visited[4][4];
        memset(visited, false, sizeof(visited));
        int temp = 0;
        int tempSx = sx;
        int tempSy = sy;
        bool isPossible = true;
        for (int j = 0; j < 3; ++j) {
            int d = sharkMoveList[i][j];
            int nx = tempSx + dsx[d];
            int ny = tempSy + dsy[d];

            if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
                if (!visited[nx][ny]) temp += board[nx][ny].size();
                tempSx = nx;
                tempSy = ny;
                visited[nx][ny] = true;
            } else {
                temp = 0;
                isPossible = false;
                break;
            }
        }
        if (temp > max && isPossible) {
            max = temp;
            maxIdx = i;
        }
    }

    for (int i = 0; i < 3; ++i) {
        sx += dsx[sharkMoveList[maxIdx][i]];
        sy += dsy[sharkMoveList[maxIdx][i]];
        if (board[sx][sy].size() > 0) {
            board[sx][sy] = vector<int>();
            smell[sx][sy] = 3;
        }
    }
}

void remove_smell() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (smell[i][j] > 0) smell[i][j]--;
        }
    }
}


void run() {
    moveFish();
    moveShark();
    remove_smell();
    copyFish();
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cal_shark_moveList();

    cin >> M >> S;

    int fx, fy, d;
    

    for (int i = 0; i < M; ++i) {
        cin >> fx >> fy >> d;
        board[fx-1][fy-1].push_back(d-1);
    }

    cin >> sx >> sy;
    sx -= 1;
    sy -= 1;
    
   
    for (int i = 0; i < S; ++i) {
        run();
    }
    cout << cal_count();

}