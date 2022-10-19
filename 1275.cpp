// 1275
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

class segTree {
public:
    vector<ll> tree;
    int size;
    
    segTree(int n) {
        for (size = 1; size < n; size *= 2);
        tree.resize(size * 2);
    }
    
    void update(int pos, ll x) {
        int idx = size + pos - 1;
        ll u = x - tree[idx];
        
        while (idx) {
            tree[idx] += u;
            idx /= 2;
        }
    }
    
    ll getSum(int pos, int left, int right, int start, int end) {
        if (left > end || right < start) {
            return 0;
        }
        if (left <= start && end <= right) {
            return tree[pos];
        }
        
        int mid = (start + end) / 2;
        return getSum(pos * 2, left, right, start, mid) + getSum(pos * 2 + 1, left, right, mid + 1, end);
    }
};


int n, q;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> q;
    
    segTree segtree(n);
    
    ll num;
    
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        segtree.update(i, num);
    }
    
    int x, y, a;
    ll b;
    
    for (int i = 0; i < q; ++i) {
        cin >> x >> y >> a >> b;
        if (x > y) cout << segtree.getSum(1, y, x, 1, segtree.size) << "\n";
        else cout << segtree.getSum(1, x, y, 1, segtree.size) << "\n";
        segtree.update(a, b);
    }
    
  
    return 0;
}
