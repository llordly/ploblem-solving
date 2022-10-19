// 11725
#include <iostream>
#include <vector>
#include <queue>


using namespace std;

vector<vector<int>> adj;
vector<int> parent;
int n;

void bfs(int start) {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    visited[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (auto x : adj[node]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
                parent[x] = node;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    int a, b;
    adj.resize(n + 1);
    parent.resize(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    bfs(1);
    
    for (int i = 2; i <= n; ++i) {
        cout << parent[i] << "\n";
    }
    
    
    return 0;
}
