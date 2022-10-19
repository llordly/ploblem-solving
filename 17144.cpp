// 17144
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int r, c, t;
int high, low;

int arr[51][51];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void rotateClock() {
    vector<int> firstRow(c + 1);
    vector<int> lastRow(c + 1);
    vector<int> firstCol(r + 1);
    vector<int> lastCol(r + 1);
    
    for (int i = 1; i <= c; ++i) {
        firstRow[i] = arr[low][i - 1];
    }
    for (int i = 0; i < c; ++i) {
        lastRow[i] = arr[r - 1][i + 1];
    }
    for (int i = low; i < r - 1; ++i) {
        firstCol[i] = arr[i + 1][0];
    }
    for (int i = low + 1; i <= r - 1; ++i) {
        lastCol[i] = arr[i - 1][c - 1];
    }
    
    
    for (int i = 1; i <= c; ++i) {
        arr[low][i] = firstRow[i];
    }
    for (int i = 0; i < c; ++i) {
        arr[r - 1][i] = lastRow[i];
    }
    for (int i = low; i < r - 1; ++i) {
        arr[i][0] = firstCol[i];
    }
    for (int i = low + 1; i <= r - 1; ++i) {
        arr[i][c - 1] = lastCol[i];
    }
    arr[low][0] = -1;
    arr[low][1] = 0;
}

void rotateCounterClock() {
    vector<int> firstRow(c + 1);
    vector<int> lastRow(c + 1);
    vector<int> firstCol(r + 1);
    vector<int> lastCol(r + 1);
    
    for (int i = 0; i < c; ++i) {
        firstRow[i] = arr[0][i + 1];
    }
    for (int i = 1; i <= c; ++i) {
        lastRow[i] = arr[high][i - 1];
    }
    for (int i = 1; i <= high; ++i) {
        firstCol[i] = arr[i - 1][0];
    }
    for (int i = 0; i < high; ++i) {
        lastCol[i] = arr[i + 1][c - 1];
    }
    
    
    for (int i = 0; i < c; ++i) {
        arr[0][i] = firstRow[i];
    }
    for (int i = 1; i <= c; ++i) {
        arr[high][i] = lastRow[i];
    }
    for (int i = 1; i <= high; ++i) {
        arr[i][0] = firstCol[i];
    }
    for (int i = 0; i < high; ++i) {
        arr[i][c - 1] = lastCol[i];
    }
    arr[high][0] = -1;
    arr[high][1] = 0;
}

int diffuse_indiv(int row, int col, vector<pair<int, int>> &list) {
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
        int nx = row + dx[i];
        int ny = col + dy[i];
        if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
            if (arr[nx][ny] != -1) {
                cnt++;
                list.push_back({nx, ny});
            }
        }
    }
    return cnt;
}

void diffuse() {
    vector<pair<int, int>> list;
    vector<pair<int, int>> amountList;
    
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (arr[i][j] && arr[i][j] != -1) {
                int amount = (int)floor(arr[i][j] / 5);
                int cnt = diffuse_indiv(i, j, list);
                amountList.push_back({amount, cnt});
                arr[i][j] -= amount * cnt;
            }
        }
    }
    
    int idx = 0;
    for (int i = 0; i < amountList.size(); ++i) {
        auto dust = amountList[i];
        
        int amount = dust.first;
        int cnt = dust.second;
        
        for (int j = 0; j < cnt; ++j) {
            auto index = list[idx];
            int row = index.first;
            int col = index.second;
            arr[row][col] += amount;
            idx++;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;
    
    cin >> r >> c >> t;
    
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> num;
            arr[i][j] = num;
            if (num == -1) {
                if (!high) high = i;
                else low = i;
            }
        }
    }
    
    for (int i = 0; i < t; ++i) {
        diffuse();
        rotateCounterClock();
        rotateClock();
    }
    
    int ans = 0;
    
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            ans += arr[i][j];
        }
    }
    
    cout << ans + 2;
    
    return 0;
}
