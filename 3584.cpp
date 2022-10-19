// 3584
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>



using namespace std;

vector<int> tree[10001];
int parent[10001][21];
int depth[10001];

int T, N, A, B;

void dfs(int cur, int height) {
    depth[cur] = height;
    
    for (auto x : tree[cur]) {
        dfs(x, height + 1);
    }
}

void make_parent() {
    for (int j = 1; j < 21; ++j) {
        for (int i = 1; i <= N; ++i) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int lca(int a, int b) {
    if (depth[a] > depth[b]) {
        swap(a, b);
    }
    
    for (int i = 20; i >= 0; --i) {
        if (depth[b] - depth[a] >= (1 << i)) {
            b = parent[b][i];
        }
    }
    
    if (a == b) return a;
    
    for (int i = 20; i >= 0; --i) {
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
    
    cin >> T;
    
    while (T--) {
        for (int i = 0; i < 10001; ++i) {
            tree[i].clear();
            depth[i] = 0;
            for (int j = 0; j < 21; ++j) {
                parent[i][j] = 0;
            }
        }
        
        cin >> N;
        for (int i = 0; i < N - 1; ++i) {
            cin >> A >> B;
            tree[A].push_back(B);
            parent[B][0] = A;
        }
        
        int root = 1;
        
        while (true) {
            if (!parent[root][0]) break;
            root = parent[root][0];
        }
        
        dfs(root, 0);
        make_parent();
        
        cin >> A >> B;
        cout << lca(A, B) << "\n";
    }
    
    
    return 0;
}
