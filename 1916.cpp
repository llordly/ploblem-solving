// 1916

#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;


int n, m;

vector<vector<pair<int, int>>> adj;
vector<int> dist;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
    fill(dist.begin(), dist.end(), INF);
    
    dist[start] = 0;
    heap.push({start, 0});
    
    while (!heap.empty()) {
        auto node = heap.top();
        heap.pop();
        int now = node.first;
        int dis = node.second;
        
        if (dist[now] < dis) continue;
        
        for (auto x : adj[now]) {
            int temp = dis + x.second;
            if (dist[x.first] > temp) {
                dist[x.first] = temp;
                heap.push({x.first, temp});
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int start, end, cost;
    
    cin >> n >> m;
    adj.resize(n + 1);
    dist.resize(n + 1);
    
    
    for (int i = 0; i < m; ++i) {
        cin >> start >> end >> cost;
        adj[start].push_back({end, cost});
    }
    cin >> start >> end;
    dijkstra(start);
    cout << dist[end];
    
    

    return 0;
}
