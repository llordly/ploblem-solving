// 1753

#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int v, e, k;

vector<int> dist;
vector<vector<pair<int, int>>> adj;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
    heap.push({0, start});
    dist[start] = 0;
    
    while (!heap.empty()) {
        auto node = heap.top();
        heap.pop();
        int dis = node.first;
        int now = node.second;
        
        if (dist[now] < dis) continue;
        
        for (auto x : adj[now]) {
            int cost = dis + x.second;
            if (cost < dist[x.first]) {
                dist[x.first] = cost;
                heap.push({cost, x.first});
            }
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, w;
    
    cin >> v >> e >> k;
    
    adj.resize(v + 1);
    dist.resize(v + 1);
    
    fill(dist.begin(), dist.end(), INF);
    
    
    
    for (int i = 0; i < e; ++i) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    
    dijkstra(k);
    
    for (int i = 1; i <= v; ++i) {
        int temp = dist[i];
        if (temp == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}
