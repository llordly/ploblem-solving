// 11505
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;

class mul_segTree {
public:
    vector<ll> tree;
    int size;
    
    mul_segTree(int n) {
        for (size = 1; size < n; size *= 2);
        tree.resize(size * 2);
        for (int i = 0; i < tree.size(); ++i) {
            tree[i] = 1;
        }
    }
    
    void update(int pos, ll x) {
        int idx = size + pos - 1;
        
        ll a = tree[idx];
        tree[idx] = x;
        idx /= 2;
        
        while (idx) {
            tree[idx] = tree[idx * 2] * tree[idx * 2 + 1];
            tree[idx] %= MOD;
            idx /= 2;
        }
    }
    
    ll getMul(int pos, int left, int right, int start, int end) {
        if (left > end || right < start) {
            return 1;
        }
        if (left <= start && end <= right) {
            return tree[pos];
        }
        
        int mid = (start + end) / 2;
        return (getMul(pos * 2, left, right, start, mid) * getMul(pos * 2 + 1, left, right, mid + 1, end)) % MOD;
    }
};


int n, m, k;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;
    
    mul_segTree segtree(n);
    
    ll num;
    
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        segtree.update(i, num);
    }
    
    ll a, b, c;
    for (int i = 0; i < m + k; ++i) {
        cin >> a >> b >> c;
        if (a == 1) {
            segtree.update(b, c);
            
        } else {
            cout << segtree.getMul(1, b, c, 1, segtree.size) << "\n";
        }
    }
  
    return 0;
}
