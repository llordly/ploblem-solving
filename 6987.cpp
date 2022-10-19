/*
6987 월드컵
백트래킹
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstring>


using namespace std;

typedef pair<int, int> P;

P comb[15] = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 3}, {2, 4}, {2, 5}, {3, 4}, {3, 5}, {4, 5}};

// 승 무 패
int score1[3] = {0, 1, 2};
// 패 승 무
int score2[3] = {2, 1, 0};

int board[6][3];
int ex[4][6][3];
int ans[4];



void backtracking(int idx, int num) {
    if (ans[num]) return;
    if (idx == 15) {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (ex[num][i][j] != board[i][j]) {
                    return;
                }
            }
        }
        ans[num] = 1;
        return;
    }

    int a = comb[idx].first;
    int b = comb[idx].second;

    for (int i = 0; i < 3; ++i) {
        board[a][score1[i]]++;
        board[b][score2[i]]++;
        backtracking(idx + 1, num);
        board[a][score1[i]]--;
        board[b][score2[i]]--;
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 6; ++j) {
            // 승 무 패
            for (int k = 0; k < 3; ++k) {
                cin >> ex[i][j][k];
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        backtracking(0, i);
    }



    for (int i = 0; i < 4; ++i) {
        cout << ans[i] << " ";
    }

    return 0;
}
