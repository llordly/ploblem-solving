//3176
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cstring>

#define MAX_NODE 17

using namespace std;


int n, k;

int parent[100001][MAX_NODE + 1];
int min_dist[100001][MAX_NODE + 1];
int max_dist[100001][MAX_NODE + 1];

int depth[100001];
bool visited[100001];
vector<pair<int, int>> adj[100001];
int min_ans = 1e9;
int max_ans = 0;

void dfs(int v, int d) {
    visited[v] = true;
    depth[v] = d;
    
    for (auto x : adj[v]) {
        if (!visited[x.first]) {
            parent[x.first][0] = v;
            min_dist[x.first][0] = x.second;
            max_dist[x.first][0] = x.second;
            dfs(x.first, d + 1);
        }
    }
}


void make_parent() {
    for (int j = 1; j < MAX_NODE + 1; ++j) {
        for (int i = 1; i <= n; ++i) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

void min_parent() {
    for (int j = 1; j < MAX_NODE + 1; ++j) {
        for (int i = 1; i <= n; ++i) {
            min_dist[i][j] = min(min_dist[i][j - 1], min_dist[parent[i][j - 1]][j - 1]);
        }
    }
}

void max_parent() {
    for (int j = 1; j < MAX_NODE + 1; ++j) {
        for (int i = 1; i <= n; ++i) {
            max_dist[i][j] = max(max_dist[i][j - 1], max_dist[parent[i][j - 1]][j - 1]);
        }
    }
}


void lca(int a, int b) {
    if (depth[a] > depth[b]) {
        swap(a, b);
    }
    
    for (int i = MAX_NODE; i >= 0; --i) {
        if (depth[b] - depth[a] >= (1 << i)) {
            min_ans = min(min_ans, min_dist[b][i]);
            max_ans = max(max_ans, max_dist[b][i]);
            b = parent[b][i];
        }
    }
    
    if (a == b) return;
    
    
    for (int i = MAX_NODE; i >= 0; --i) {
        if (parent[a][i] != parent[b][i]) {
            min_ans = min(min_ans, min(min_dist[a][i], min_dist[b][i]));
            max_ans = max(max_ans, max(max_dist[a][i], max_dist[b][i]));
            a = parent[a][i];
            b = parent[b][i];
            
        }
    }
    
    min_ans = min(min_ans, min(min_dist[a][0], min_dist[b][0]));
    max_ans = max(max_ans, max(max_dist[a][0], max_dist[b][0]));
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b;
    int c;
    
    cin >> n;
    
   
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < MAX_NODE + 1; ++j) {
            min_dist[i][j] = 1000001;
            max_dist[i][j] = 0;
        }
    }
    
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    dfs(1, 0);
    make_parent();
    min_parent();
    max_parent();
    
    cin >> k;
    
    int d, e;
    
    int common;
    
    
    for (int i = 0; i < k; ++i) {
        cin >> d >> e;
        min_ans = 1e9;
        max_ans = 0;
        lca(d, e);
        cout << min_ans << " " << max_ans << "\n";
    }
    
    return 0;
}





