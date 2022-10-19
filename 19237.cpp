//19237

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<int, int> Smell;
typedef pair<pair<int, int>, int> Shark;

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};


vector<int> board[21][21];
Smell smell[21][21];
vector<Shark> sharkList;

int sharkPrior[401][401][4];
int sharkDir[401];

int timeStamp;



int N, M, k;


void init_board() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            board[i][j] = vector<int>();
        }
    }
}


void getSharkList() {
    sharkList = vector<Shark>();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j].size() == 1) {
                sharkList.push_back({{i, j}, board[i][j][0]});
            }
        }
    }
}



void scatterSmell() {
    for (Shark shark : sharkList) {
        int x = shark.first.first;
        int y = shark.first.second;
        int num = shark.second;

        smell[x][y].first = k;
        smell[x][y].second = num;
    }
}

void removeSmell() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (smell[i][j].first) {
                int temp = smell[i][j].first - 1;
                if (!temp) {
                    smell[i][j].first = 0;
                    smell[i][j].second = 0;
                } else {
                    smell[i][j].first = temp;
                }
            }
        }
    }
}

void outShark() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j].size() > 1) {
                vector<int> temp = board[i][j];
                sort(temp.begin(), temp.end());
                board[i][j] = vector<int>();
                board[i][j].push_back(temp[0]);
            }
        }
    }
}


bool checkShark() {
    return sharkList.size() == 1;
}


void moveShark() {
    init_board();

    for (Shark shark : sharkList) {
        int x = shark.first.first;
        int y = shark.first.second;
        int num = shark.second;
        int d = sharkDir[num];

        bool check = false;
        vector<Shark> candidate;

        for (int i = 0; i < 4; ++i) {
            bool check2 = false;
            int newD = sharkPrior[num][d][i];
            int nx = x + dx[newD];
            int ny = y + dy[newD];


            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (!smell[nx][ny].first) {
                    board[nx][ny].push_back(num);
                    check = true;
                    sharkDir[num] = newD;
                    break;
                }

                if (smell[nx][ny].second == num) {
                    candidate.push_back({{nx, ny}, newD});
                }
            }
        }

        if (!check) {
                if (candidate.size()) {
                    Shark temp = candidate[0];
                    board[temp.first.first][temp.first.second].push_back(num);
                    sharkDir[num] = temp.second;
                    check = true;
                }
            }
        
        if (!check) board[x][y].push_back(num);
    }
}


int run() {
    while (timeStamp < 1000) {
        timeStamp++;
        moveShark();
        outShark();
        getSharkList();
        removeSmell();
        scatterSmell();
        bool test = checkShark();
        if (test) return timeStamp;
    }
    return -1;
}




int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> k;

    int sharkNum;


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> sharkNum;
            if (sharkNum) board[i][j].push_back(sharkNum);
        }
    }


    for (int i = 1; i <= M; ++i) {
        cin >> sharkDir[i];
    }


    // 위 아래 왼 오
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                cin >> sharkPrior[i][j][k];
            }
        }
    }


    getSharkList();
    scatterSmell();

    cout << run();


    return 0;
}