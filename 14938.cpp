// 14938
#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int n, m, r;

vector<vector<int>> arr;
vector<int> item;

int Min(int a, int b) {
    return a > b ? b : a;
}

void floyd_warshall() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                arr[i][j] = Min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, l;
    cin >> n >> m >> r;

    arr.resize(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; ++i) {
        arr[i][i] = 0;
    }

    int t;
    item.push_back(-1);

    for (int i = 0; i < n; ++i) {
        cin >> t;
        item.push_back(t);
    }

    for (int i = 0; i < r; ++i) {
        cin >> a >> b >> l;
        arr[a][b] = arr[b][a] = l;
    }

    floyd_warshall();

    int ans = 0;

    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        for (int j = 1; j <= n; ++j) {
            if (arr[i][j] <= m)
                sum += item[j];
        }
        if (sum > ans) ans = sum;
    }

    cout << ans;
    return 0;
}
