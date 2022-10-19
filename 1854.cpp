// 1854
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;

vector<vector<pair<int, int>>> adj;
vector<priority_queue<int>> dist;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});
    dist[start].push(0);
    
    while (!pq.empty()) {
        auto node = pq.top();
        pq.pop();
        
        int now = node.second;
        int dis = node.first;
        
        for (auto x : adj[now]) {
            int newDis = x.second + dis;
            int newNode = x.first;
            if (dist[newNode].size() < k) {
                dist[newNode].push(newDis);
                pq.push({newDis, newNode});
            } else {
                if (dist[newNode].top() > newDis) {
                    dist[newNode].pop();
                    dist[newNode].push(newDis);
                    pq.push({newDis, newNode});
                }
            }
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c;
    
    cin >> n >> m >> k;
    
    adj.resize(n + 1);
    dist.resize(n + 1);
    
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    
    dijkstra(1);
    
    for (int i = 1; i <= n; ++i) {
        if (dist[i].size() == k) {
            cout << dist[i].top();
        } else cout << -1;
        cout << "\n";
    }
    
    
    
    return 0;
}
