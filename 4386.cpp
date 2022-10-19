// 6416
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cmath>

using namespace std;

typedef pair<double, pair<int, int>> Edge;

int dsu[101];

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

int n;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    iota(dsu, dsu + 101, 0);
    
    cin >> n;
    double x, y;
    
    priority_queue<Edge, vector<Edge>, greater<Edge>> heap;
    vector<pair<double, double>> arr;
    
    
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        arr.push_back({x, y});
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto a = arr[i];
            auto b = arr[j];
            double dis = sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
            heap.push({dis, {i, j}});
        }
    }
    
    double ans = 0.0;
    
    while (!heap.empty()) {
        Edge node = heap.top();
        heap.pop();
        
        if (Find(node.second.first) != Find(node.second.second)) {
            Union(node.second.first, node.second.second);
            ans += node.first;
        }
    }
    
    cout << fixed;
    cout.precision(2);
    cout << ans;
    
    
    return 0;
}
