// 2580
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

pair<int, int> startP[9] = {{0, 0}, {0, 3}, {0, 6}, {3, 0}, {3, 3}, {3, 6}, {6, 0}, {6, 3}, {6, 6}};
pair<int, int> endP[9] = {{2, 2}, {2, 5}, {2, 8}, {5, 2}, {5, 5}, {5, 8}, {8, 2}, {8, 5}, {8, 8}};

vector<pair<int, int>> blank;

int arr[9][9];

bool finish = false;



int checkRow(int r) {
    int temp = 0;
    for (int i = 0; i < 9; ++i) {
        temp |= (1 << arr[r][i]);
    }
    return temp;
}

int checkCol(int c) {
    int temp = 0;
    for (int i = 0; i < 9; ++i) {
        temp |= (1 << arr[i][c]);
    }
    return temp;
}

int checkSquare(int r, int c) {
    int temp = 0;
    for (int i = 0; i < 9; ++i) {
        pair<int, int> leftTop = startP[i];
        pair<int, int> rightBottom = endP[i];
        
        if (r >= leftTop.first && r <= rightBottom.first && c >= leftTop.second && c <= rightBottom.second) {
            for (int j = leftTop.first; j <= rightBottom.first; ++j) {
                for (int k = leftTop.second; k <= rightBottom.second; ++k) {
                    temp |= (1 << arr[j][k]);
                }
            }
        }
    }
    return temp;
}

void backtracking(int cnt, int pos) {
    if (finish) return;
    if (cnt == blank.size()) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        finish = true;
        return;
    }
    int r = blank[pos].first;
    int c = blank[pos].second;
    
    int check = checkRow(r) | checkCol(c) | checkSquare(r, c);
    check = ~check;
    
    
    for (int i = 1; i <= 9; ++i) {
        if (check & (1 << i)) {
            arr[r][c] = i;
            backtracking(cnt + 1, pos + 1);
            arr[r][c] = 0;
        }
    }
}



int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> arr[i][j];
            if (!arr[i][j]) blank.push_back({i, j});
        }
    }
    
    backtracking(0, 0);

    
    return 0;
}


