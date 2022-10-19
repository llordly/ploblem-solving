// 2644
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, x, y;
    cin >> n >> a >> b >> m;
    
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1);
    
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    queue<pair<int, int>> q;
    q.push({a, 0});
    visited[a] = true;
    
    bool ans = false;
    
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        
        int idx = node.first;
        int dis = node.second;
        
        if (idx == b) {
            cout << dis;
            ans = true;
            break;
        }
        
        for (int i : adj[idx]) {
            if(!visited[i]) {
                q.push({i, dis + 1});
                visited[i] = true;
            }
        }
        
    }
    
    if (!ans) cout << -1;
   
    return 0;
}
