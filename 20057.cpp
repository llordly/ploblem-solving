// 20057

#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;


// 좌 하 우 상
// 0 1 2 3 


typedef pair<pair<int, int>, int> Tornado;

vector<Tornado> tornadoList;

int board[500][500];
int tornadoIdx;
int N;
int out;



// alpha is 7
double percent[10] = {0.01, 0.01, 0.02, 0.07, 0.07, 0.02, 0.1, 0, 0.1, 0.05};

int sandDir[4][2][10] = 
{
    {
        {-1, 1, -2, -1, 1, 2, -1, 0, 1, 0}, 
        {0, 0, -1, -1, -1, -1, -2, -2, -2, -3}
    },
    {
        {0, 0, 1, 1, 1, 1, 2, 2, 2, 3},
        {-1, 1, -2, -1, 1, 2, -1, 0, 1, 0}
    },
    {
        {-1, 1, -2, -1, 1, 2, -1, 0, 1, 0},
        {0, 0, 1, 1, 1, 1, 2, 2, 2, 3}
    },
    {
        {0, 0, -1, -1, -1, -1, -2, -2, -2, -3},
        {-1, 1, -2, -1, 1, 2, -1, 0, 1, 0}
    }
};


void makeTornadoPos() {
    int level = 0;
    int idx = 1;
    int row = N/2;
    int col = N/2;

    tornadoList.push_back({{row, col}, 0});
    col--;

    while (idx < N * N) {
        int d = level * 2 + 1;

        for (int i = 0; i < d; ++i) {
            tornadoList.push_back({{row, col}, 1});
            row++;
            idx++;
        }

        for (int i = 0; i < d + 1; ++i) {
            tornadoList.push_back({{row, col}, 2});
            col++;
            idx++;
        }

        for (int i = 0; i < d + 1; ++i) {
            tornadoList.push_back({{row, col}, 3});
            row--;
            idx++;
        }

        for (int i = 0; i < d + 2; ++i) {
            tornadoList.push_back({{row, col}, 0});
            col--;
            idx++;
        }
        level++;
    }
}



void moveTornado() {
    Tornado tornado = tornadoList[tornadoIdx];
    int x = tornado.first.first;
    int y = tornado.first.second;
    int d = tornado.second;

    int nextIdx = tornadoIdx + 1;
    int nextX = tornadoList[nextIdx].first.first;
    int nextY = tornadoList[nextIdx].first.second;

    int sandAmount = board[nextX][nextY];

    // 좌 하 우 상
    // 0 1 2 3 
    // alpha is 7

    int alphaX = x + sandDir[d][0][7];
    int alphaY = y + sandDir[d][1][7];

    int alpha = sandAmount;

    for (int i = 0; i < 10; ++i) {
        if (i == 7) continue;
        int nx = x + sandDir[d][0][i];
        int ny = y + sandDir[d][1][i];

        int sand = (int)(trunc(percent[i] * sandAmount));

        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            board[nx][ny] += sand;
        } else {
            out += sand;
        }

        alpha -= sand;
    }

    if (alphaX >= 0 && alphaX < N && alphaY >= 0 && alphaY < N) {
        board[alphaX][alphaY] += alpha;
    } else {
        out += alpha;
    }

    board[nextX][nextY] = 0;
}


void run() {
    while (tornadoIdx < tornadoList.size()) {
        moveTornado();
        tornadoIdx++;
    }
}




int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   

    cin >> N;

    makeTornadoPos();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    run();

    cout << out;


    return 0;
}