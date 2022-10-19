// 1238

#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int n, m, x;

vector<int> dist;


vector<int> dijkstra(int start, vector<vector<pair<int, int>>> adj) {
    fill(dist.begin(), dist.end(), INF);
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
    return dist;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<vector<pair<int, int>>> forward;
    vector<vector<pair<int, int>>> backward;
    
    int ans = 0;
    int start, end, t;
    cin >> n >> m >> x;
    
    vector<int> party(n + 1, 0);
    forward.resize(n + 1);
    backward.resize(n + 1);
    dist.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        cin >> start >> end >> t;
        forward[start].push_back({end, t});
        backward[end].push_back({start, t});
    }
    
    
    vector<int> go = dijkstra(x, backward);
    vector<int> back = dijkstra(x, forward);
    
    for (int i = 1; i <= n; ++i) {
        int temp = go[i] + back[i];
        if (temp > ans)
            ans = temp;
    }
    
    cout << ans;

    return 0;
}
