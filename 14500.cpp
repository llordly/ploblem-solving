// 14500

#include <iostream>
#include <vector>

using namespace std;


int n, m;
int arr[1000][500];

int ans = 0;

int max(int a, int b) {
    return a > b ? a : b;
}

// ㅡ line
int lx[2][4] = {{0, 0, 0, 0}, {0, 1, 2, 3}};
int ly[2][4] = {{0, 1, 2, 3}, {0, 0, 0, 0}};

// thunder
int tx[4][4] = {{0, 0, 1, 1}, {0, 0, -1, -1}, {0, -1, -1, -2}, {0, 1, 1, 2}};
int ty[4][4] = {{0, 1, 1, 2}, {0, 1, 1, 2}, {0, 0, 1, 1}, {0, 0, 1, 1}};

// ㄴ curve
int cx[8][4] = {{0, 0, 0, 1}, {0, 0, 0, 1}, {0, 1, 1, 1}, {0, 0, 0, -1}, {0, 1, 2, 2}, {0, 0, -1 ,-2}, {0, 1, 2, 0}, {0, 0, 1, 2}};
int cy[8][4] = {{0, 1, 2, 2}, {0, 1, 2, 0}, {0, 0, 1, 2}, {0, 1, 2, 2}, {0, 0, 0, 1}, {0, 1, 1, 1}, {0, 0, 0, 1}, {0, 1, 1, 1}};

// ㅗ mount
int mx[4][4] = {{0, 1, 2, 1}, {0, -1, 0, 1}, {0, 0, 0, -1}, {0, 0, 0, 1}};
int my[4][4] = {{0, 0, 0, 1}, {0, 1, 1, 1}, {0, 1, 2, 1}, {0, 1, 2, 1}};

// ㅁ square
int sx[1][4] = {{0, 0, 1, 1}};
int sy[1][4] = {{0, 1, 0 ,1}};

void line(int x, int y) {
    for (int i = 0; i < 2; ++i) {
        bool out = false;
        int sum = 0;
        for (int j = 0; j < 4; ++j) {
            int nx = x + lx[i][j];
            int ny = y + ly[i][j];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                out = true;
                break;
            } else {
                sum += arr[nx][ny];
            }
        }
        if (!out) {
            ans = max(ans, sum);
        }
    }
}

void thunder(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        bool out = false;
        int sum = 0;
        for (int j = 0; j < 4; ++j) {
            int nx = x + tx[i][j];
            int ny = y + ty[i][j];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                out = true;
                break;
            } else {
                sum += arr[nx][ny];
            }
        }
        if (!out) {
            ans = max(ans, sum);
        }
    }
}

void curve(int x, int y) {
    for (int i = 0; i < 8; ++i) {
        bool out = false;
        int sum = 0;
        for (int j = 0; j < 4; ++j) {
            int nx = x + cx[i][j];
            int ny = y + cy[i][j];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                out = true;
                break;
            } else {
                sum += arr[nx][ny];
            }
        }
        if (!out) {
            ans = max(ans, sum);
        }
    }
}

void mount(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        bool out = false;
        int sum = 0;
        for (int j = 0; j < 4; ++j) {
            int nx = x + mx[i][j];
            int ny = y + my[i][j];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                out = true;
                break;
            } else {
                sum += arr[nx][ny];
            }
        }
        if (!out) {
            ans = max(ans, sum);
        }
    }
}

void square(int x, int y) {
    for (int i = 0; i < 1; ++i) {
        bool out = false;
        int sum = 0;
        for (int j = 0; j < 4; ++j) {
            int nx = x + sx[i][j];
            int ny = y + sy[i][j];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                out = true;
                break;
            } else {
                sum += arr[nx][ny];
            }
        }
        if (!out) {
            ans = max(ans, sum);
        }
    }
}
    

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int input;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> input;
            arr[i][j] = input;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            line(i, j);
            thunder(i, j);
            curve(i, j);
            mount(i, j);
            square(i, j);
        }
    }
    cout << ans;
    return 0;
}

