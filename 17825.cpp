/*
17825 주사위 윷놀이
구현
*/

#include <iostream>
#include <vector>

#define START 0
#define END 21

using namespace std;


typedef pair<int, int> P;

vector<int> board[33];

int score[33] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0, 13, 16, 19, 22, 24, 28, 27, 26, 25, 30, 35};
int dice[10];
int ans;

int Max(int a, int b) { return a > b ? a : b; }


// 시작 지점의 말의 개수, pos는 말의 위치
void backtracking(int horse, int dice_idx, vector<int> horse_pos, int score_sum) {
    if (dice_idx == 10) {
        
        ans = Max(ans, score_sum);
        return;
    }

    // 도착말은 이동 못하니까 제외
    for (int i = 0; i < 33; ++i) {
        if (horse_pos[i]) {
            // 시작 말의 개수가 0일 경우에는 시작점은 선택 못하니까 건너뛴다.
            if (horse == 0 && i == 0) {
                continue;
            }

            int move = dice[dice_idx];

            int cur = i;

            if (board[cur].size() == 2) {
                // 파란색 길로 가야함
                cur = board[cur][1];
                // 횟수 하나 감소
                move--;
            }
            for (int j = 0; j < move; ++j) {
                cur = board[cur][0];
            }

            // 이동했을 때 말이 존재하면 안됨! 도착 칸이면 상관 없음
            if (cur == END) {
                vector<int> new_horse_pos = horse_pos;
                new_horse_pos[i] = 0;
                // 이동을 마쳤으므로 다음 주사위를 던져본다.
                backtracking(horse, dice_idx + 1, new_horse_pos, score_sum);
            } else if (horse_pos[cur]) {
                // 칸에 말이 존재하므로 다음 말을 선택해봄
                continue;
            } else {
                // 이동할 수 있는 경우
                vector<int> new_horse_pos = horse_pos;
                new_horse_pos[cur] = 1;
                
                if (i == 0) {
                    // 시작점에서 이동한 경우 남은 말의 수를 하나 빼고 넘겨줌
                    backtracking(horse - 1, dice_idx + 1, new_horse_pos, score_sum + score[cur]);
                } else {
                    new_horse_pos[i] = 0;
                    backtracking(horse, dice_idx + 1, new_horse_pos, score_sum + score[cur]);
                }
            }
        }
    }
}






int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    //start = 0, end = 21
    for (int i = 0; i < 21; ++i) {
        board[i].push_back(i + 1);
    }

    board[21].push_back(21);

    board[5].push_back(22);
    board[22].push_back(23);
    board[23].push_back(24);
    board[24].push_back(30);

    board[10].push_back(25);
    board[25].push_back(26);
    board[26].push_back(30);

    board[15].push_back(27);
    board[27].push_back(28);
    board[28].push_back(29);
    board[29].push_back(30);

    board[30].push_back(31);
    board[31].push_back(32);
    board[32].push_back(20);

    for (int i = 0; i < 10; ++i) {
        cin >> dice[i];
    }


    vector<int> horse_pos(33, 0);
    horse_pos[0] = 1;

    backtracking(4, 0, horse_pos, 0);

    cout << ans;


    return 0;
}