// 14595
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

int n, m;

int dsu[1000001];


int Find(int u) {
    return dsu[u] == u ? u : (dsu[u] = Find(dsu[u]));
}


void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u != v) {
        dsu[u] = v;
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    iota(dsu + 1, dsu + 1000000, 1);
    
    
    cin >> n >> m;
    int x, y;
    
    for (int i = 0; i < m; ++i){
        cin >> x >> y;
        
        while (Find(x) != Find(y)) {
            n--;
            int a = Find(x) + 1;
            Union(x, y);
            x = a;
        }
    }
    cout << n;
    
    
    return 0;
}
