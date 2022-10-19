//11724

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited(1001, false);
queue<int> q;

void bfs(int start) {
    visited[start] = true;
    q.push(start);
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        visited[node] = true;
        for (int item : adj[node]) {
            if(!visited[item]) {
                visited[item] = true;
                q.push(item);
            }
        }
    }
}

int main(void) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
    int n, m, u, v;
    cin >> n >> m;
    adj.resize(n + 1);
    
    int ans = 0;
    
    
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            ans++;
            bfs(i);
        }
    }
    cout << ans;
    return 0;
}

