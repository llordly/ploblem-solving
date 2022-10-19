// 2610
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stack>




using namespace std;

int n, m;
int INF = 1e9;

int dist[101][101];
int dsu[101];


int Find(int x) {
    return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    
    if (u != v) {
        dsu[v] = u;
    }
}


void floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin >> n >> m;
    
    iota(dsu + 1, dsu + 101, 1);
    vector<vector<int>> group(n + 1, vector<int>());
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) dist[i][i] = 0;
            else dist[i][j] = INF;
        }
    }
    
    
    int a, b;
    
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        dist[a][b] = dist[b][a] = 1;
        Union(a, b);
    }
    
    
    floyd();
    
    for (int i = 1; i <= n; ++i) {
        group[Find(i)].push_back(i);
    }
    
    int cnt = 0;
    vector<int> ans;
    
    for (int i = 1; i <= n; ++i) {
        if (!group[i].size()) continue;
        cnt++;
        
        int dis = INF;
        int represent = 0;
        
        for (auto x : group[i]) {
            int temp = 0;
            for (auto y : group[i]) {
                temp = max(temp, dist[x][y]);
            }
            
            if (dis > temp) {
                dis = temp;
                represent = x;
            }
        }
        ans.push_back(represent);
    }
    
    sort(ans.begin(), ans.end());
    
    cout << cnt << "\n";
    for (auto x : ans) {
        cout << x << "\n";
    }
    
    return 0;
}
