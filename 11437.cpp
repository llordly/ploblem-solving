// 11437
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define MAX 17


using namespace std;


vector<int> tree[50001];
int parent[50001][MAX];
int depth[50001];
bool visited[50001];

int n, m;

void dfs(int v, int d) {
    visited[v] = true;
    depth[v] = d;
    for (auto x : tree[v]) {
        if (!visited[x]) {
            parent[x][0] = v;
            dfs(x, d + 1);
        }
    }
}

void make_parent() {
    for (int j = 1; j < MAX; ++j) {
        for (int i = 1; i <= n; ++i) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int lca(int a, int b) {
    if (depth[a] > depth[b]) {
        swap(a, b);
    }
    
    for (int i = MAX - 1; i >= 0; --i) {
        if (depth[b] - depth[a] >= (1 << i)) {
            b = parent[b][i];
        }
    }
    
    if (a == b) return a;
    
    for (int i = MAX - 1; i >= 0; --i) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}



int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b;
    
    
    cin >> n;
    
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    dfs(1, 0);
    make_parent();
    
    cin >> m;
    
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }

    
    return 0;
}
