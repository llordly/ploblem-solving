// 1197
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

typedef long long ll;

typedef pair<ll, pair<int, int>> Edge;


int v, e;

int dsu[10001];

int Find(int x) {
    return x == dsu[x] ? x : (dsu[x] = Find(dsu[x]));
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u != v) {
        dsu[v] = u;
    }
}

ll ans;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    priority_queue<Edge, vector<Edge>, greater<Edge>> heap;
    iota(dsu + 1, dsu + 10000, 1);
    cin >> v >> e;
    int a, b, c;
    
    for (int i = 0; i < e; ++i) {
        cin >> a >> b >> c;
        heap.push({c, {a, b}});
    }
    
    while (!heap.empty()) {
        Edge node = heap.top();
        heap.pop();
        if (Find(node.second.first) != Find(node.second.second)) {
            Union(node.second.first, node.second.second);
            ans += node.first;
        }
    }
    
    cout << ans;
    
    
    return 0;
}
