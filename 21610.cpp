//21610

#include <iostream>
#include <cstring>
#include <vector>
#include <string>


using namespace std;

typedef pair<int, int> Pos;
typedef pair<pair<int, int>, int> Water;

vector<Pos> cloudList;

int board[51][101];

int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int diag[4] = {2, 4, 6, 8};


int N, M;

int linkMap(int pos) {
    if (pos > N) return 1;
    if (pos < 1) return N;
    else return pos;
}

void makeCloud() {
    cloudList.push_back({N, 1});
    cloudList.push_back({N, 2});
    cloudList.push_back({N-1, 1});
    cloudList.push_back({N-1, 2});
}


void moveCloud(int d, int s) {
    for (int i = 0; i < cloudList.size(); ++i) {
        int x = cloudList[i].first;
        int y = cloudList[i].second;

        for (int j = 0; j < s; ++j) {
            x += dx[d];
            y += dy[d];
            x = linkMap(x);
            y = linkMap(y);
        }
        cloudList[i].first = x;
        cloudList[i].second = y;
    }

    // int test[51][101];
    // memset(test, 0, sizeof(test));
    // for (Pos cloud : cloudList) {
    //     // cout << "cloud pos: (" << cloud.first << ", " << cloud.second << ")\n";
    //     test[cloud.first][cloud.second] = 1;
    // }

    // cout << "\ncloud : \n";
    // for (int i = 1; i <= N; ++i) {
    //     for (int j = 1; j <= N; ++j) {
    //         cout << test[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
}


void rain() {
    for (Pos cloud : cloudList) {
        int r = cloud.first;
        int c = cloud.second;
        board[r][c] += 1;
    }
}


void copyWater() {
    bool visited[51][101];
    vector<Water> waterList;
    memset(visited, false, sizeof(visited));
    // memset(cloudVisited, false, sizeof(cloudVisited));
    for (Pos cloud : cloudList) {
        int x = cloud.first;
        int y = cloud.second;
        visited[x][y] = true;
        int basket = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[diag[i]];
            int ny = y + dy[diag[i]];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                if (board[nx][ny]) basket++;
            }
        }
        // board[x][y] += basket;
        waterList.push_back({{x, y}, basket});
    }

    for (Water water : waterList) {
        int x = water.first.first;
        int y = water.first.second;
        int m = water.second;
        board[x][y] += m;
    }


    cloudList = vector<Pos>();

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (!visited[i][j]) {
                if (board[i][j] >= 2) {
                    // cloudVisited[i][j] = true;
                    cloudList.push_back({i, j});
                    board[i][j] -= 2;
                }
            }
        }
    }

    // for (Pos cloud : cloudList) {
    //     cout << "cloud pos: (" << cloud.first << ", " << cloud.second << ")\n";
    // }

}

int calWater() {
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            ans += board[i][j];
        }
    }
    return ans;
}


void print_cloud(string name) {
    cout << "\n" << name << "\n";
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int run(int d, int s) {
    moveCloud(d, s);
    rain();
    copyWater();
    return calWater();
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int d, s;

    int ans = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> board[i][j];
        }
    }

    makeCloud();

    for (int i = 0; i < M; ++i) {
        cin >> d >> s;
        ans = run(d, s);
    }

    cout << ans;

    return 0;
}