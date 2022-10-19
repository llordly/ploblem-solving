// 16202
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>

using namespace std;

int dsu[1001];
int n, m, k;
vector<pair<int, int>> edge;

int Find(int x) {
    return dsu[x] == x ? x : (dsu[x] = Find(dsu[x]));
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u != v) dsu[v] = u;
}

int mst(int turn) {
    iota(dsu + 1, dsu + n + 1, 1);
    int cnt = 0;
    int ans = 0;
    for (int i = turn; i <= m; ++i) {
        auto node = edge[i];
        if (Find(node.first) != Find(node.second)) {
            Union(node.first, node.second);
            cnt++;
            ans += i;
        }
    }
    if (cnt != n - 1) return 0;
    else return ans;
}



int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;
    
    int x, y;
    
    edge.push_back({0, 0});
    
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        edge.push_back({x, y});
    }
    
    bool check = false;
    int ans = 0;
    for (int i = 1; i <= k; ++i) {
        if (check) cout << 0 << " ";
        else {
            ans = mst(i);
            if (!ans) check = true;
            cout << ans << " ";
        }
    }
    
    

    
    
    return 0;
}
