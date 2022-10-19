// 10868
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

class min_segTree {
public:
    int size;
    vector<ll> tree;
    
    min_segTree(int n) {
        for (size = 1; size < n; size <<= 1);
        tree.resize(size << 1);
        
        for (int i = 0; i < (size << 1); ++i) {
            tree[i] = 1e12;
        }
    }
    
    void update(int pos, int x) {
        int idx = size + pos - 1;
        tree[idx] = x;
        idx >>= 1;
        
        while (idx) {
            tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
            idx >>= 1;
        }
    }
    
    ll getMin(int pos, int left, int right, int start, int end) {
        if (left > end || right < start) {
            return 1e12;
        }
        if (left <= start && end <= right) {
            return tree[pos];
        }
        
        int mid = (start + end) >> 1;
        
        return min(getMin(pos * 2, left, right, start, mid), getMin(pos * 2 + 1, left, right, mid + 1, end));
    }
};

int n, m;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    int num, a, b;
    
    min_segTree minSegTree(n);
    
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        minSegTree.update(i, num);
    }

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        cout << minSegTree.getMin(1, a, b, 1, minSegTree.size) << "\n";
    }
    
  
    return 0;
}
