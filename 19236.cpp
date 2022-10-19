//19236

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>



using namespace std;

inline int Max(int a, int b) {return a > b ? a : b;}

int ans;

typedef pair<int, int> Fish;
typedef pair<pair<int, int>, int> Pos;

vector<Pos> sortedFish;


int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};


int rotateDir(int d) {
    return d + 1 > 8 ? 1 : d + 1;
}

void sortFish(vector<vector<Fish>> board) {
    sortedFish = vector<Pos>(17, {{0, 0}, 0});

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            Fish fish = board[i][j];
            if (fish.first == 0) continue;
            sortedFish[fish.first] = {{i, j}, fish.second};
        }
    }
}

vector<vector<Fish>> moveFish(int sharkX, int sharkY, vector<vector<Fish>> board) {
    sortFish(board);


    for (int i = 1; i < 17; ++i) {
        Pos fish = sortedFish[i];
        if (fish.second == 0) continue;

        int x = fish.first.first;
        int y = fish.first.second;
        int d = fish.second;

        int dir = d;


        while (true) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
                if (!(nx == sharkX && ny == sharkY)) {
                    board[x][y].second = dir;
                    int tempX = sortedFish[board[nx][ny].first].first.first;
                    int tempY = sortedFish[board[nx][ny].first].first.second;

                    sortedFish[board[nx][ny].first].first.first = sortedFish[i].first.first;
                    sortedFish[board[nx][ny].first].first.second = sortedFish[i].first.second;

                    sortedFish[i].first.first = tempX;
                    sortedFish[i].first.second= tempY;
                    sortedFish[i].second = dir;


                    swap(board[x][y], board[nx][ny]);
                    break;
                } else dir = rotateDir(dir);
            } else dir = rotateDir(dir);

            if (dir == d) break;
        }
    }
    return board;
}


void moveShark(int sharkX, int sharkY, vector<vector<Fish>> board, int num) {
    vector<Pos> moveList;
  
    int nx = sharkX;
    int ny = sharkY;

    int d = board[nx][ny].second;
    int newNum = num + board[nx][ny].first;
    board[nx][ny] = {0, 0};

    vector<vector<Fish>> temp = moveFish(nx, ny, board);
    

    while (true) {
        nx += dx[d];
        ny += dy[d];
        if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
            if (temp[nx][ny].first) moveList.push_back({{nx, ny}, temp[nx][ny].second});
        } else break;
    }

    if (!moveList.size()) {
        ans = Max(ans, newNum);
        return;
    }


    for (Pos shark : moveList) {
        int x = shark.first.first;
        int y = shark.first.second;
        moveShark(x, y, temp, newNum);
    }

}




int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // num, direction
    int a, b;

    vector<vector<Fish>> board(4, vector<Fish>(4, {0, 0}));
    pair<int, int > shark = {0, 0};


    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> a >> b;
            board[i][j] = {a, b};
        } 
    }

    moveShark(0, 0, board, 0);

    cout << ans;


    return 0;
}