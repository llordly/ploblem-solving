// 1799
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>

using namespace std;

vector<pair<int, int>> whiteBoard;
vector<pair<int, int>> blackBoard;

int bishop[11][11];

int n;
int black;
int white;

bool blackPossible(int row, int col) {
    for (int i = 0; i < n; ++i) {
        for (int j = (i % 2 == 0); j < n; j += 2) {
            if (bishop[i][j]) {
                if (abs(row - i) == abs(col - j)) return false;
            }
        }
    }
    return true;
}

bool whitePossible(int row, int col) {
    for (int i = 0; i < n; ++i) {
        for (int j = !(i % 2 == 0); j < n; j += 2) {
            if (bishop[i][j]) {
                if (abs(row - i) == abs(col - j)) return false;
            }
        }
    }
    return true;
}


void blackTracking(int pos, int cnt) {
    black = max(black, cnt);
    if (pos == blackBoard.size()) return;
    
    int r = blackBoard[pos].first;
    int c = blackBoard[pos].second;
    if (blackPossible(r, c)) {
        bishop[r][c] = 1;
        blackTracking(pos + 1, cnt + 1);
        bishop[r][c] = 0;
    }
    blackTracking(pos + 1, cnt);
}

void whiteTracking(int pos, int cnt) {
    white = max(white, cnt);
    if (pos == whiteBoard.size()) return;
    
    int r = whiteBoard[pos].first;
    int c = whiteBoard[pos].second;
    if (whitePossible(r, c)) {
        bishop[r][c] = 1;
        whiteTracking(pos + 1, cnt + 1);
        bishop[r][c] = 0;
    }
    whiteTracking(pos + 1, cnt);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    int num;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> num;
            if (num) {
                if (i % 2 == j % 2) {
                    whiteBoard.push_back({i, j});
                } else {
                    blackBoard.push_back({i, j});
                }
            }
        }
    }
    
    blackTracking(0, 0);
    whiteTracking(0, 0);
    
    cout << black + white;

    
    return 0;
}


