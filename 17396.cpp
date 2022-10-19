// 17396
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

typedef long long ll;
#define INF 1e18

using namespace std;

int n, m;

vector<ll> dist;
bool see[100000];
vector<vector<pair<ll, ll>>> adj;

void dijkstra(int start) {
    fill(dist.begin(), dist.end(), INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> q;
    
    dist[start] = 0;
    q.push({0, start});
    
    while(!q.empty()) {
        auto node = q.top();
        q.pop();
        
        ll now = node.second;
        ll dis = node.first;
        
        if (dist[now] < dis) {
            continue;
        }
        
        for (auto x : adj[now]) {
            ll newDis = dis + x.second;
            if (newDis < dist[x.first]) {
                dist[x.first] = newDis;
                q.push({newDis, x.first});
            }
        }
    }
    
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;
    int a, b, t;
    cin >> n >> m;
    
    adj.resize(n);
    dist.resize(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (num) see[i] = true;
    }
    see[n - 1] = false;
    
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> t;
        if (see[a] || see[b]) continue;
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }
    

    
    dijkstra(0);
    if (dist[n - 1] == INF) cout << -1;
    else cout << dist[n - 1];
    
    
    return 0;
}
