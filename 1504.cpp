// 1504
#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int n, e;

vector<vector<pair<int, int>>> adj;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>> adj) {
    vector<int> dist(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
    fill(dist.begin(), dist.end(), INF);
    dist[start] = 0;
    heap.push({0, start});
    
    while (!heap.empty()) {
        auto node = heap.top();
        heap.pop();
        int now = node.second;
        int dis = node.first;
        
        if (dis > dist[now]) continue;
        
        for (auto x : adj[now]) {
            int newDis = dist[now] + x.second;
            int next = x.first;
            if (newDis < dist[next]) {
                dist[next] = newDis;
                heap.push({newDis, next});
            }
        }
    }
    return dist;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c;
    cin >> n >> e;
    adj.resize(n + 1);
    
    for (int i = 0; i < e; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    int v1, v2;
    cin >> v1 >> v2;
    // 1 -> n
    // 1 -> v1 -> v2 -> n
    // 1 -> v2 -> v1 -> n
    vector<int> start1 = dijkstra(1, adj);
    
    
    if (start1[v1] == INF || start1[v2] == INF) {
        cout << "-1";
        return 0;
    }
    
    vector<int> startV1 = dijkstra(v1, adj);
    vector<int> startV2 = dijkstra(v2, adj);
    
    if (startV1[v2] == INF) {
        cout << "-1";
        return 0;
    }

    int toV1 = start1[v1];
    int toV2 = start1[v2];
    int v1v2 = startV1[v2];
    int v2ToEnd = startV2[n];
    int v1ToEnd = startV1[n];
    
    int pass1 = toV1 + v1v2 + v2ToEnd;
    int pass2 = toV2 + v1v2 + v1ToEnd;
    
    if (pass1 < pass2) cout << pass1;
    else cout << pass2;
    
    
    return 0;
}


