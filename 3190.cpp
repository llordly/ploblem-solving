// 3190

#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int n, k;

int board[101][101];
bool visited[101][101];
int snakeDirection[10001];

int dRow = 0;
int dCol = 1;

int dummy(int row, int col) {
    int t = 0;
    deque<pair<int, int>> dq;
    dq.push_back({row, col});
    visited[row][col] = true;
    
    while (row >= 0 && row < n && col >= 0 && col < n) {
        row += dRow;
        col += dCol;
        t++;
        if (visited[row][col]) break;
        
        dq.push_back({row, col});
        visited[row][col] = true;
        
        if (board[row][col]) board[row][col] = 0;
        else {
            auto tail = dq.front();
            dq.pop_front();
            visited[tail.first][tail.second] = false;
        }
        int dir = snakeDirection[t];
        if (dir != 0) {
            int tempR = dRow;
            int tempC = dCol;
            dRow = tempC;
            dCol = tempR;
            if (dir == 1) {
                // left
                if (!tempR) dRow = -dRow;
            } else {
                // right
                if (!tempC) dCol = - dCol;
            }
        }
    }
    return t;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int appleRow, appleCol, x, l;
    char direct;
    
    cin >> n >> k;
    
    for (int i = 0; i < k; ++i) {
        cin >> appleRow >> appleCol;
        board[appleRow - 1][appleCol - 1] = 1;
    }
    
    cin >> l;
    for (int i = 0; i < l; ++i) {
        int lr;
        cin >> x >> direct;
        if (direct == 'L') lr = 1;
        else lr = 2;
        snakeDirection[x] = lr;
    }
    
    cout << dummy(0, 0);

    return 0;
}
