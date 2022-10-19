/*
16918 봄버맨
구현
*/

#include <iostream>
#include <string>
#include <vector>


using namespace std;

// bomb, time
typedef pair<int, int> Bomb;


Bomb board[201][201];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int r, c, n;

void mine() {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (!board[i][j].first) {
                board[i][j] = {1, 3};
            }
        }
    }
}

void explosion() {
    vector<Bomb> bomb_list;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (board[i][j].first && board[i][j].second <= 0) {
                bomb_list.push_back({i, j});
            }
        }
    }

    for (auto bomb : bomb_list) {
        int x = bomb.first;
        int y = bomb.second;
        board[x][y] = {0, 0};
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                board[nx][ny] = {0, 0};
            }
        }
    }
}

void next_step() {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (board[i][j].first) {
                board[i][j].second--;
            }
        }
    }
}

void print_board() {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (board[i][j].first && board[i][j].second) cout << 'O';
            else cout << '.';
        }
        cout << "\n";
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    

    cin >> r >> c >> n;
    string line;

    for (int i = 0; i < r; ++i) {
        cin >> line;
        for (int j = 0; j < c; ++j) {
            if (line[j] == '.') board[i][j] = {0, 0};
            else board[i][j] = {1, 2};
        }
    }

    if (n == 1) {
        print_board();
        return 0;
    }

    int t = 1;
    while(true) {
        t++;
        next_step();
        mine();
        if (t == n) break;
        t++;
        next_step();
        explosion();
        if (t == n) break;
    }

    print_board();


    return 0;
}