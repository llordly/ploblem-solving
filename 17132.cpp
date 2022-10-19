//17132
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;

typedef pair<ll, pair<int, int>> Edge;

vector<Edge> edge;
int dsu[100001];
int cnt[100001];

int Find(int x) {
    return x == dsu[x] ? x : dsu[x] = Find(dsu[x]);
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    
    if (u != v) {
        dsu[v] = u;
        cnt[u] += cnt[v];
    }
}

int n;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int x, y;
    ll w;
    
    cin >> n;
    
    iota(dsu + 1, dsu + 100001, 1);
    fill(cnt + 1, cnt + 100001, 1);
    
    
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y >> w;
        edge.push_back({w, {x, y}});
    }
    
    ll ans = 0;
    
    sort(edge.begin(), edge.end(), greater<Edge>());
    
    for (int i = 0; i < edge.size(); ++i) {
        Edge temp = edge[i];
        if (Find(temp.second.first) != Find(temp.second.second)) {
            ans += temp.first * cnt[Find(temp.second.first)] * cnt[Find(temp.second.second)];
            Union(temp.second.first, temp.second.second);
        }
    }
    
    cout << ans;

    
    return 0;
}





