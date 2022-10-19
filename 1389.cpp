// 1389

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, a, b;
    cin >> n >> m;
    int min = 100000000;
    int ans = 0;
    
    vector<vector<int>> adj(n + 1);
    
    
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    //bfs
    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        queue<pair<int, int>> q;
        vector<bool> visited(n + 1, false);
        
        int start = i;
        visited[i] = true;
        q.push({start, 0});
        
        while (!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();
            for (int x : adj[node.first]) {
                if (!visited[x]) {
                    visited[x] = true;
                    int dis = node.second + 1;
                    q.push({x, dis});
                    sum += dis;
                }
            }
        }
        if (sum < min) {
            min = sum;
            ans = i;
        }
    }
    cout << ans;
    return 0;
}

