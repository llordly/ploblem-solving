//17490

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;

typedef pair<ll, pair<int, int>> Edge;

int dsu[1000001];
bool connect[1000002];

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

int n, m;
ll k;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    iota(dsu + 1, dsu + 1000001, 1);
    memset(connect, true, sizeof(connect));
    
    cin >> n >> m >> k;
    
    ll s;
    
    int a, b;
    
    priority_queue<Edge, vector<Edge>, greater<Edge>> heap;
    
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        heap.push({s, {i, n + 1}});
    }
    
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        int diff = b - a;
        if (diff != 1) {
            connect[n] = false;
        } else {
            connect[a] = false;
        }
    }
    
    if (m <= 1) {
        cout << "YES";
        return 0;
    }
    
    
    for (int i = 1; i <= n; ++i) {
        if (connect[i]) {
            if (i == n) heap.push({0, {1, n}});
            else heap.push({0, {i, i + 1}});
        }
    }

    ll sum = 0;
    int cnt = 0;
    
    while (!heap.empty() && cnt < n) {
        Edge node = heap.top();
        heap.pop();
        
        if (Find(node.second.first) != Find(node.second.second)) {
            Union(node.second.first, node.second.second);
            cnt++;
            sum += node.first;
        }
    }
    
    if (k - sum < 0) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    
    
    return 0;
}




