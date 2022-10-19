// 5719
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


#define INF 1e9

using namespace std;

int n, m;
int test;
vector<vector<int>> arr;
vector<vector<int>> trace;

void bfs(int start, int end) {
    vector<bool> visited(n, false);
    queue<int> q;
    
    q.push(end);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (visited[node]) continue;
        if (node == start) continue;
        visited[node] = true;
        for (int i = 0; i < trace[node].size(); ++i) {
            int ad = trace[node][i];
                q.push(ad);
                arr[ad][node] = 0;
        }
    }
}

int dijkstra(int start, int end) {
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
    heap.push({0, start});
    
    while (!heap.empty()) {
        auto node = heap.top();
        heap.pop();
        
        int now = node.second;
        int dis = node.first;
        
        if (dist[now] < dis) continue;
        
        for (int i = 0; i < n; ++i) {
            if (arr[now][i]) {
                int temp = arr[now][i] + dis;
                if (temp < dist[i]) {
                    dist[i] = temp;
                    heap.push({temp, i});
                    trace[i].clear();
                    trace[i].push_back(now);
                } else if (temp == dist[i]) {
                    trace[i].push_back(now);
                }
            }
        }
    }
    
    bfs(start, end);

    return dist[end];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        
        int start, end;
        int u, v, p;
        
        arr.clear();
        trace.clear();
        arr.assign(n, vector<int>(n, 0));
        trace.assign(n, vector<int>());
        cin >> start >> end;
        
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> p;
            arr[u][v] = p;
        }
        
        dijkstra(start, end);
        int ans = dijkstra(start, end);
        if (ans == INF) cout << -1 << "\n";
        else cout << ans << "\n";
    }
    
    
    return 0;
}
