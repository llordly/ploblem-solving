/*
8911 거북이
구현
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;


// 방향을 북 동 남 서
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dir;
int curX;
int curY;

// F이면 방향으로 감, B이면 방향 반대로 감(방향 반대는 (idx + 2) % 4)
// L이면 (idx + 3) % 4, R이면 (idx + 1) % 4

priority_queue<int, vector<int>, greater<int>> row_min;
priority_queue<int> row_max;
priority_queue<int, vector<int>, greater<int>> col_min;
priority_queue<int> col_max;



void update_value(int row, int col) {
    row_min.push(row);
    row_max.push(row);
    col_min.push(col);
    col_max.push(col);
}


void update_pos(int d) {
    curX += dx[d];
    curY += dy[d];
}



void move(char d) {
    if (d == 'F') {
        update_pos(dir);
        update_value(curX, curY);
    } else if (d == 'B') {
        update_pos((dir + 2) % 4);
        update_value(curX, curY);
    } else if (d == 'L') {
        dir = (dir + 3) % 4;
    } else if (d == 'R') {
        dir = (dir + 1) % 4;
    }
}


void init_tutle() {
    row_min = {};
    row_max = {};
    col_min = {};
    col_max = {};
    dir = 0;
    curX = 0;
    curY = 0;
    update_value(0, 0);
}

int run(string command) {
    init_tutle();
    for (int i = 0; i < command.size(); ++i) {
        move(command[i]);
    }
    int rowMin = row_min.top();
    int rowMax = row_max.top();
    int colMin = col_min.top();
    int colMax = col_max.top();
    int rowAbs = abs(rowMax - rowMin);
    int colAbs = abs(colMax - colMin);

    return rowAbs * colAbs;    
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int T;
    cin >> T;
    string command;

    for (int i = 0; i < T; ++i) {
        cin >> command;
        cout << run(command) << "\n";
    }


    return 0;
}
