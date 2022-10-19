/*
14890 경사로
구현
*/

#include <iostream>
#include <cstring>

using namespace std;


int n, l;

int board[101][101];
int slope[101][101];
int ans;


void solve() {
    // 어쨌든 갈라면 무조건 경사로 놓기는 해야함
    // 경사로의 유무를 기록해둘 필요가 있음
    // 경사로의 길이도 중요함 -> 경사로의 길이가 2일 때는 같은 수가 연속으로 2번 이상 존재해야함

    // 행 체크하기
    for (int i = 0; i < n; ++i) {
        // 각 행에 관하여

        int prev = board[i][0];
        int check = true;
        for (int j = 1; j < n; ++j) {
            int diff = board[i][j] - prev;

            // 높이 차이가 0이면 상관 없음
            if (diff == 0) {
                continue;
            } else if (diff == -1) {
                // 높이 차이가 1일 경우에는 경사로를 놓을 수 있다.
                // 내리막에 해당
                if (l > 1) {
                    int cnt = 1;
                    int value = board[i][j];
                    if (j == n - 1) {
                        // 이 경우는 마지막이기 때문에 불가능함 -> false return;
                        check = false;
                        break;
                    }
                    // L이 2 이상인 경우 -> 길이 L만큼 cnt가 되어야 경사로를 놓을 수 있음
                    for (int k = j + 1; k < n; ++k) {
                        if (board[i][k] == value) {
                            cnt++;
                        } else {
                            break;
                        }
                    }

                    // cnt가 l 이상일 경우에는 경사로를 놓을 수 있다. L 만큼 경사로 놓아주면 된다.
                    if (cnt >= l) {
                        for (int k = j; k < j + l; ++k) {
                            slope[i][k] = 1;
                        }
                    } else {
                        // 이 경우 경사로의 길이만큼 블럭의 수가 존재하지 않으므로 불가능함 
                        check = false;
                        break;
                    }
                } else {
                    // L이 1인 경우 -> 경사로 그냥 바로 놓으면 됨
                    slope[i][j] = 1;
                }
            } else if (diff == 1) {
                // 오르막에 해당
                if (l > 1) {
                    int cnt = 1;
                    int value = prev;
                    if (j == 1) {
                        // j가 1인 경우엔 앞에 길이 L짜리 경사로를 놓을 수 없다
                        check = false;
                        break;
                    }
                    // L이 2 이상인 경우 -> 길이 L만큼 cnt가 되어야 경사로를 놓을 수 있음
                    for (int k = j - 2; k >= 0; --k) {
                        if (board[i][k] == value) {
                            cnt++;
                        } else {
                            break;
                        }
                    }

                    // cnt가 l 이상일 경우에는 경사로를 놓을 수 있다. L 만큼 경사로 놓아주면 된다.
                    if (cnt >= l) {
                        for (int k = j - 1; k >= j - l; --k) {
                            if (slope[i][k]) {
                                check = false;
                                break;
                            } else slope[i][k] = 1;
                        }
                    } else {
                        // 이 경우 경사로의 길이만큼 블럭의 수가 존재하지 않으므로 불가능함 
                        check = false;
                        break;
                    }
                } else {
                    // L이 1인 경우 -> 경사로 그냥 바로 놓으면 됨 -> 이미 경사로가 존재할 경우는 제외하고
                    if (slope[i][j - 1]) {
                        check = false;
                        break;
                    } else slope[i][j - 1] = 1;
                }
            } else {
                check = false;
                break;
            }
            prev = board[i][j];
        }
        if (check) {
            ans++;
        }
    }

    memset(slope, 0, sizeof(slope));

    // 열 체크하기
    for (int i = 0; i < n; ++i) {
    // 각 열에 관하여
        int prev = board[0][i];
        int check = true;
        for (int j = 1; j < n; ++j) {
            int diff = board[j][i] - prev;

            // 높이 차이가 0이면 상관 없음
            if (diff == 0) {
                continue;
            } else if (diff == -1) {
                // 높이 차이가 1일 경우에는 경사로를 놓을 수 있다.
                // 내리막에 해당
                if (l > 1) {
                    int cnt = 1;
                    int value = board[j][i];
                    if (j == n - 1) {
                        // 이 경우는 마지막이기 때문에 불가능함 -> false return;
                        
                        check = false;
                        break;
                    }
                    // L이 2 이상인 경우 -> 길이 L만큼 cnt가 되어야 경사로를 놓을 수 있음
                    for (int k = j + 1; k < n; ++k) {
                        if (board[k][i] == value) {
                            cnt++;
                        } else {
                            break;
                        }
                    }
                    // cnt가 l 이상일 경우에는 경사로를 놓을 수 있다. L 만큼 경사로 놓아주면 된다.
                    if (cnt >= l) {
                        for (int k = j; k < j + l; ++k) {
                            slope[k][i] = 1;
                        }
                    } else {
                        // 이 경우 경사로의 길이만큼 블럭의 수가 존재하지 않으므로 불가능함 
                        check = false;
                        break;
                    }
                } else {
                    // L이 1인 경우 -> 경사로 그냥 바로 놓으면 됨
                    slope[j][i] = 1;
                }
            } else if (diff == 1) {
                // 오르막에 해당
                if (l > 1) {
                    int cnt = 1;
                    int value = prev;
                    if (j == 1) {
                        // j가 1인 경우엔 앞에 길이 L짜리 경사로를 놓을 수 없다
                        check = false;
                        break;
                    }
                    // L이 2 이상인 경우 -> 길이 L만큼 cnt가 되어야 경사로를 놓을 수 있음
                    for (int k = j - 2; k >= 0; --k) {
                        if (board[k][i] == value) {
                            cnt++;
                        } else {
                            break;
                        }
                    }

                    // cnt가 l 이상일 경우에는 경사로를 놓을 수 있다. L 만큼 경사로 놓아주면 된다.
                    if (cnt >= l) {
                        for (int k = j - 1; k >= j - l; --k) {
                            if (slope[k][i]) {
                                check = false;
                                break;
                            } else slope[k][i] = 1;
                        }
                    } else {
                        // 이 경우 경사로의 길이만큼 블럭의 수가 존재하지 않으므로 불가능함 
                        check = false;
                        break;
                    }
                } else {
                    // L이 1인 경우 -> 경사로 그냥 바로 놓으면 됨 -> 이미 경사로가 존재할 경우는 제외하고
                    if (slope[j - 1][i]) {
                        check = false;
                        break;
                    } else slope[j - 1][i] = 1;
                }
            } else {
                check = false;
                break;
            }
            prev = board[j][i];
        }

        if (check) {
            ans++;
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> l;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    solve();

    cout << ans;




    return 0;
}