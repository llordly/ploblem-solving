/*
17779 게리맨더링 2
구현
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int ans = 1e9;

vector<vector<int>> population;


int Min(int a, int b) { return a < b ? a : b; }


int get_diff(vector<vector<int>> board) {
    vector<int> idv_popul(6, 0);


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            idv_popul[board[i][j]] += population[i][j];
        }
    }

    sort(idv_popul.begin(), idv_popul.end());
    
    return idv_popul[5] - idv_popul[1];
}


bool possible_index(int x, int y) {
    if (!(x >= 0 && x < n && y >= 0 && y < n)) {
        return false;
    }
    return true;
}


// 각 꼭짓점 찾기, 1번 꼭짓점은 볼필요 없음
bool is_possible_seperate(int x, int y, int d1, int d2) {
    // 2번 꼭짓점 체크
    int nx = x + d2;
    int ny = y + d2;
    if (!possible_index(nx, ny)) {
        return false;
    }
    
    // 3번 꼭짓점 체크
    nx = x + d1;
    ny = y - d1;
    if (!possible_index(nx, ny)) {
        return false;
    }

    // 4번 꼭짓점 체크
    nx = x + d1 + d2;
    ny = y - d1 + d2;
    if (!possible_index(nx, ny)) {
        return false;
    }

    return true;
}


// 선거 구역 나누기 함수
vector<vector<int>> seperate(int x, int y, int d1, int d2) {
    vector<vector<int>> boundary(n, vector<int>(n, 0));
    vector<vector<int>> board(n, vector<int>(n, 0));

    // 5번 선거구의 경계 지정
    for (int i = 0; i <= d1; ++i) {
        // 5와 1의 경계
        boundary[x + i][y - i] = 1;
        board[x + i][y - i] = 5;

        // 5와 4의 경계
        boundary[x + d2 + i][y + d2 - i] = 1;
        board[x + d2 + i][y + d2 - i] = 5;
    }

    for (int i = 0; i <= d2; ++i) {
        // 5와 2의 경계
        boundary[x + i][y + i] = 1;
        board[x + i][y + i] = 5;

        // 5와 3의 경계
        boundary[x + d1 + i][y - d1 + i] = 1;
        board[x + d1 + i][y - d1 + i] = 5;
    }



    // 1번 선거구 지정
    for (int i = 0; i < x + d1; ++i) {
        for (int j = 0; j <= y; ++j) {
            if (boundary[i][j]) break;
            board[i][j] = 1;
        }
    }

    // 2번 선거구 지정
    for (int i = x + d2; i >= 0; --i) {
        for (int j = n - 1; j > y; --j) {
            if (boundary[i][j]) break;
            board[i][j] = 2;
        }
    }

    // 3번 선거구 지정
    for (int i = x + d1; i < n; ++i) {
        for (int j = 0; j < y - d1 + d2; ++j) {
            if (boundary[i][j]) break;
            board[i][j] = 3;
        }
    }

    // 4번 선거구 지정
    for (int i = n - 1; i > x + d2; --i) {
        for (int j = n - 1; j >= y - d1 + d2; --j) {
            if (boundary[i][j]) break;
            board[i][j] = 4;
        }
    }

    // 5번 선거구 지정
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 0) {
                board[i][j] = 5;
            }
        }
    }

    return board;
}


// 브루트포스로 돌리기!
void solve() {
    // 각 시작 꼭짓점에 대해
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            // d1, d2를 정한다.
            // d1 + d2는 n + 1을 넘으면 안된다. d1 + d2 <= n + 1
            // d1, d2 각각은 n - 1이하여야한다. d1, d2 <= n - 1
            for (int d1 = 1; d1 <= n - 1; ++d1) {
                for (int d2 = 1; d2 <= n - 1; ++d2) {
                    if (d1 + d2 > n + 1) continue;
                    if(is_possible_seperate(x, y, d1, d2)) {
                        int diff = get_diff(seperate(x, y, d1, d2));
                        ans = Min(ans, diff);
                    }
                }
            }
        }
    }
}



int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int num;

    population.resize(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> num;
            population[i].push_back(num);
        }
    }


    solve();

    cout << ans;


    return 0;
}