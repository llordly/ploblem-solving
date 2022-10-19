/*
*/

#include <iostream>
#include <vector>


using namespace std;

typedef pair<int, int> Pos;


int n, m, h;

int ladder[31][11];
vector<Pos> ladderV;

int ans = 1e9;


int Min(int a, int b) { return a < b ? a : b; }


bool is_possible() {
    // 각 세로선별로 체크해보기
    for (int i = 1; i <= n; ++i) {
        int cur = i;
        // j는 행
        int j;

        // 1이면 오른쪽, 2이면 왼쪽
        for (j = 1; j <= h; ++j) {
            if (ladder[j][cur] == 1) {
                cur++;
            } else if (ladder[j][cur] == 2) {
                cur--;
            }
        }

        if (cur != i) return false;
    }
    return true;
}




void backtraking(int cnt, int idx) {
    // 3보다 큰 경우는 필요 없으므로 종료
    if (cnt > 3) {
        return;
    }

    // 가능하면 종료
    if (is_possible()) {
        ans = Min(ans, cnt);
        return;
    }



    for (int i = idx; i < ladderV.size(); ++i) {
        Pos p = ladderV[i];
        int a = p.first;
        int b = p.second;


        // 왼쪽으로 가는 길이 존재하므로 사다리를 놓지 못한다 -> 그냥 다음 사다리 보라고 패스시킴
        if (ladder[a][b] == 2) {
            continue;
        } else if (ladder[a][b + 1] == 1) {
            continue;
        } else {
            // 사다리를 놓을 수 있음 -> 백트래킹
            ladder[a][b] = 1;
            ladder[a][b + 1] = 2;
            backtraking(cnt + 1, i + 1);
            ladder[a][b] = 0;
            ladder[a][b + 1] = 0;
        }

    }
}





int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // n이 열, h가 행임
    cin >> n >> m >> h;

    int a, b;

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;

        // 1이면 오른쪽으로 가는 길이 있는 것이고, 2이면 왼쪽으로 가는 길이 있는 것
        ladder[a][b] = 1;
        ladder[a][b + 1] = 2;
    }


    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= h; ++j) {
            if (ladder[j][i] != 1) {
                ladderV.push_back({j, i});
            }
        }
    }


    backtraking(0, 0);

    if (ans == 1e9) cout << -1;
    else cout << ans;


    return 0;
}