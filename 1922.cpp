// 1992
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>

using namespace std;

typedef pair<int, pair<int, int>> Edge;

int dsu[100001];

int Find(int x) {
    return dsu[x] == x ? x : (dsu[x] = Find(dsu[x]));
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u != v) {
        dsu[v] = u;
    }
}

int n, m;
int ans;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c;
    priority_queue<Edge, vector<Edge>, greater<Edge>> heap;
    cin >> n >> m;
    
    iota(dsu + 1, dsu + n + 1, 1);
    
    for (int i = 0; i < m; ++i) {
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
