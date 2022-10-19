// 1647
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int>> Edge;

int dsu[100001];

int Find(int u) {
    return u == dsu[u] ? u : (dsu[u] = Find(dsu[u]));
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    
    if (u != v) {
        dsu[v] = u;
    }
}

int n, m;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    iota(dsu + 1, dsu + 100000, 1);
    priority_queue<Edge, vector<Edge>, greater<Edge>> heap;
    
    int ans = 0;
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        heap.push({c, {a, b}});
    }
    
    int temp = 0;
    while (!heap.empty()) {
        Edge node = heap.top();
        heap.pop();
        
        if (Find(node.second.first) != Find(node.second.second)) {
            Union(node.second.first, node.second.second);
            ans += node.first;
            temp = node.first;
        }
    }
    
    cout << ans - temp;
    
    
    return 0;
}
