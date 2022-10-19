// 1045
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

typedef pair<int, int> Edge;

vector<int> dsu(50);
vector<int> cnt(50);

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
    
    iota(dsu.begin(), dsu.end(), 0);
    fill(cnt.begin(), cnt.end(), 0);
    
    queue<Edge> heap;
    
    cin >> n >> m;
    string line;
    int check = 0;
    int total = 0;
    
    for (int i = 0; i < n; ++i) {
        dsu[i] = i;
        cnt[i] = 0;
    }
    
    for (int i = 0; i < n; ++i) {
        cin >> line;
        for (int j = i + 1; j < n; ++j) {
            if (line[j] == 'Y') {
                if (Find(i) != Find(j)) {
                    Union(i, j);
                    cnt[i]++;
                    cnt[j]++;
                    check++;
                } else {
                    heap.push({i, j});
                }
            }
        }
    }

    
    if (check != n - 1) {
        cout << -1 << "\n";
        return 0;
    }
    
    total = check;
    
    for (int i = 0; i < m - (n - 1); ++i) {
        if (!heap.empty()) {
            Edge node = heap.front();
            heap.pop();
            cnt[node.first]++;
            cnt[node.second]++;
            total++;
        } else {
            cout << -1 << "\n";
            return 0;
        }
    }
    
//    if (total < m) cout << -1;
//    else {
//        for (int i = 0; i < n; ++i) {
//            cout << cnt[i] << " ";
//        }
//    }
    for (int i = 0; i < n; ++i) {
        cout << cnt[i] << " ";
    }
    
    return 0;
}
