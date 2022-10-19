/*
16562 친구비
유니온 파인드
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>



using namespace std;

typedef long long ll;



int n, m, k;
int friend_cost[10001];
int dsu[10001];
int visited[10001];

int Min(int a, int b) { return a < b ? a : b; }



int Find(int x) {
    return x == dsu[x] ? x : dsu[x] = Find(dsu[x]);
}


void Union(int u, int v) {
    u = Find(u);
    v = Find(v);

    if (u > v) {
        dsu[u] = v;
        friend_cost[v] = Min(friend_cost[v], friend_cost[u]);
        
    } else if (u < v) {
        dsu[v] = u;
        friend_cost[u] = Min(friend_cost[v], friend_cost[u]);
    }
}



int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    iota(dsu + 1, dsu + n + 1, 1);


    for (int i = 1; i <= n; ++i) {
        cin >> friend_cost[i];
    }

    int v, w;

    for (int i = 0; i < m; ++i) {
        cin >> v >> w;
        Union(v, w);
    }

    int cost = 0;

    for (int i = 1; i <= n; ++i) {
        int temp = Find(i);
        if (!visited[temp]) {
            visited[temp] = 1;
            cost += friend_cost[temp];
        }
    }

    if (cost > k) {
        cout << "Oh no";
    } else cout << cost;

    return 0;
}