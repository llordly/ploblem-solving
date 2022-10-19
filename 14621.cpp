// 14621
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int>> Edge;

int dsu[1001];
int cnt[1001];

int Find(int u) {
    return u == dsu[u] ? u : (dsu[u] = Find(dsu[u]));
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    
    if (u < v) {
        dsu[v] = u;
        cnt[u] += cnt[v];
    } else if (u > v) {
        dsu[u] = v;
        cnt[v] += cnt[u];
    }
}


int n, m;
int gender[1001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int ans = 0;
    fill(cnt + 1, cnt + 1000, 1);
    
    iota(dsu + 1, dsu + 1000, 1);
    
    cin >> n >> m;
    int u, v, d;
    char s;
    
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        if (s == 'W') gender[i] = 1;
    }
     
    priority_queue<Edge, vector<Edge>, greater<Edge>> heap;
    
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> d;
        if (gender[u] != gender[v]) {
            heap.push({d, {u, v}});
        }
    }
    
    while (!heap.empty()) {
        Edge node = heap.top();
        heap.pop();
        if (Find(node.second.first) != Find(node.second.second)) {
            Union(node.second.first, node.second.second);
            ans += node.first;
        }
    }
    
    if (cnt[1] != n) cout << -1;
    else cout << ans;
    
    return 0;
}
