// 1865
#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

bool bellman_ford(vector<vector<pair<int, int>>> arr, int n) {
    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 1; j <= n; ++j) {
            int from = j;
            for (auto x : arr[j]) {
                int to = x.first;
                int dis = x.second;
                
                if (dist[to] > dist[from] + dis) dist[to] = dist[from] + dis;
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        int from = i;
        for (auto x : arr[i]) {
            int to = x.first;
            int dis = x.second;
            
            if (dist[to] > dist[from] + dis) {
                return true;
            }
        }
    }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int test;
    cin >> test;
    int n, m, w, s, e, t;
    while(test--) {
        cin >> n >> m >> w;
        vector<vector<pair<int, int>>> arr(n + 1);
        for (int i = 0; i < m; ++i) {
            cin >> s >> e >> t;
            arr[s].push_back({e, t});
            arr[e].push_back({s, t});
        }
        for (int i = 0; i < w; ++i) {
            cin >> s >> e >> t;
            arr[s].push_back({e, -t});
        }
        if(bellman_ford(arr, n)) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}
