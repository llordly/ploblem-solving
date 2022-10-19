// 18116
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

int n;

int dsu[1000001];
vector<int> cnt(1000001);


int Find(int u) {
    return dsu[u] == u ? u : (dsu[u] = Find(dsu[u]));
}


void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u != v) {
        dsu[v] = u;
        cnt[u] += cnt[v];
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    iota(dsu + 1, dsu + 1000000, 1);
    
    fill(cnt.begin(), cnt.end(), 1);
    int a, b, c;
    char command;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> command;
        switch(command) {
            case 'I':
                cin >> a >> b;
                Union(a, b);
                break;
            case 'Q':
                cin >> c;
                cout << cnt[Find(c)] << "\n";
            default:
                break;
        }
    }
    
    return 0;
}
