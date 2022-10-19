/*
21609 상어 중학교
구현 & BFS
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;


typedef pair<int, int> Pos;





int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};


int n, m;
int score;
int finish;

// 빈칸은 -2로 하기

// 회전
vector<vector<int>> rotate(vector<vector<int>> board) {
    vector<vector<int>> new_board(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            new_board[n - i - 1][j] = board[j][i];
        }
    }

    return new_board;
}




// 중력
vector<vector<int>> gravity(vector<vector<int>> board) {
    // 검은 블록엔 중력이 작용하지 않음
    // 밑에서부터 올라가되 검은 블록을 만나면 break;

    for (int j = 0; j < n; ++j) {
        // -2인 칸으로 떨어트려야함! -2인 칸의 개수를 세고 떨어트리면 된다? 벡터를 쓸까?
        // 검은색을 만나기 전까지 모든 것들을 큐에 넣자!
        // 그리고 이전 검은색 index에서 현재 검은색 index까지 내용을 큐에서 pop하면서 바꿔주자!
        // outofindex도 검은색 취급!
        queue<Pos> q;
        int black_idx = n;
        int prev_black_idx = n;

        for (int i = n - 1; i >= 0; --i) {
            if (board[i][j] == -1) {
                black_idx = i;
                for (int k = prev_black_idx - 1; k > black_idx; --k) {
                    if (q.empty()) break;
                    board[k][j] = q.front().first;
                    if (q.front().second != k) board[q.front().second][j] = -2;
                    q.pop();
                }
                prev_black_idx = black_idx;
                q = {};
            } else {
                if (board[i][j] >= 0) {
                    q.push({board[i][j], i});
                }
            }

            if (i == 0) {
                for (int k = prev_black_idx - 1; k > 0; --k) {
                    if (q.empty()) break;
                    board[k][j] = q.front().first;
                    if (q.front().second != k) board[q.front().second][j] = -2;
                    q.pop();
                }
            }
        }
    }


    return board;
}







// 큰 그룹 찾기
vector<vector<int>> find_large(vector<vector<int>> board) {
    // 크기각 가장 큰 블록 그룹을 찾는데, 여러개면 무지개 블록이 가장 많은 블록, 그것도 여러개면 행이 가장 큰 것, 그것도 여러개면 열이 가장 큰것
    // cnt > rainbow > row > col

    // bfs로 찾기
    vector<vector<int>> visited(n, vector<int>(n, 0));
    int max_cnt = 0;
    int max_row = -1;
    int max_col = -1;
    int prev_rainbow = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // bfs 여러번 돌리기
            // 무지게 == 0, 검은색 == -1, 일반은 1이상

            if (board[i][j] == 0 || board[i][j] == -2 || board[i][j] == -1) {
                // 탐색의 시작은 무조건 일반블록부터
                continue;
            }
            
            for (int k = 0; k < n; ++k) {
                for (int s = 0; s < n; ++s) {
                    if (board[k][s] == 0) visited[k][s] = 0;
                }
            }

            queue<Pos> q;
            visited[i][j] = 1;
            q.push({i, j});

            // 초기값 배정
            int cnt = 0;
            int rainbow = 0;
            int color = board[i][j];
            int std_row = i;
            int std_col = j;

            while (!q.empty()) {
                Pos node = q.front();
                q.pop();

                cnt++;
                int x = node.first;
                int y = node.second;

                //기준 블록 찾아야함
                if (board[x][y] != 0) {
                    if (x < std_row) {
                        std_row = x;
                        std_col = y;
                    } else if (x == std_row) {
                        if (y < std_col) {
                            std_col = y;
                        }
                    }
                }


                for (int k = 0; k < 4; ++k) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        if (!visited[nx][ny]) {
                            if (board[nx][ny] == color) {
                                q.push({nx, ny});
                                visited[nx][ny] = 1;
                            }
                            if (board[nx][ny] == 0) {
                                q.push({nx, ny});
                                visited[nx][ny] = 1;
                                rainbow++;
                            }
                        }
                    }
                }
            }
            

            // 우선순위 판단해서 i, j 뽑아내기
            if (cnt > max_cnt) {
                max_row = std_row;
                max_col = std_col;
                prev_rainbow = rainbow;
                max_cnt = cnt;
            } else if (cnt == max_cnt) {
                if (rainbow > prev_rainbow) {
                    prev_rainbow = rainbow;
                    max_row = std_row;
                    max_col = std_col;
                } else if (rainbow == prev_rainbow) {
                    if (max_row < std_row) {
                        max_row = std_row;
                        max_col = std_col;
                    } else if (max_row == std_row) {
                        if (max_col < std_col) {
                            max_col = std_col;
                        }
                    }
                }
            }
        }
    }

    if (max_cnt <= 1) {
        max_cnt = 0;
        finish = 1;
    } else {
        //이제 최우선순위의 기준블럭 i, j를 찾아냄!
        score += max_cnt * max_cnt;
        // 다시 bfs해서 지워버리기! 이때는 -2로 바꿔주자!

        vector<vector<int>> visited2(n, vector<int>(n, 0));
        queue<Pos> q2;
        visited2[max_row][max_col] = 1;
        q2.push({max_row, max_col});

        int cnt = 0;
        int color = board[max_row][max_col];


        while (!q2.empty()) {
            Pos node = q2.front();
            q2.pop();

            int x = node.first;
            int y = node.second;
            
            // 빈칸처리해주기
            board[x][y] = -2;

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if (!visited2[nx][ny]) {
                        if (board[nx][ny] == color || board[nx][ny] == 0) {
                            q2.push({nx, ny});
                            visited2[nx][ny] = 1;
                        }
                    }
                }
            }
        }
    }



    return board;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;



    vector<vector<int>> board(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    while (!finish) {
        board = find_large(board);
        board = gravity(board);
        board = rotate(board);
        board = gravity(board);
    }
    

    cout << score;

    return 0;
}