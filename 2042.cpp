// 2042
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
        if (right < start || left > end) {
            return 0;
        }
        if (start >= left && end <= right) {
            return tree[pos];
        }
        
        int mid = (start + end) / 2;
        return getSum(pos * 2, left, right, start, mid) + getSum(pos * 2 + 1, left, right, mid + 1, end);
    }
};

int n, m, k;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;
    
    ll num, a, b, c;
    
    segTree segtree(n);
    
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        segtree.update(i, num);
    }
    
    for (int i = 0; i < m + k; ++i) {
        cin >> a >> b >> c;
        if (a == 1) {
            segtree.update(b, c);
        } else {
            cout << segtree.getSum(1, b, c, 1, segtree.size) << "\n";
        }
    }
    
    
  
    return 0;
}
