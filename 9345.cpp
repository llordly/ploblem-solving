// 9345
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class min_segTree {
public:
    int size;
    vector<int> tree;
    
    min_segTree(int n) {
        for (size = 1; size < n; size *= 2);
        tree.resize(size * 2);
        
        for (int i = 0; i < tree.size(); ++i) {
            tree[i] = 1e9;
        }
    }
    
    int getValue(int pos) {
        int idx = size + pos - 1;
        return tree[idx];
    }
    
    void update(int pos, int x) {
        int idx = size + pos - 1;
        tree[idx] = x;
        idx /= 2;
        
        while (idx) {
            tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
            idx /= 2;
        }
    }
    
    int getMin(int pos, int left, int right, int start, int end) {
        if (left > end || right < start) {
            return 1e9;
        }
        if (left <= start && end <= right) {
            return tree[pos];
        }
        
        int mid = (start + end) / 2;
        return min(getMin(pos * 2, left, right, start, mid), getMin(pos * 2 + 1, left, right, mid + 1, end));
    }
};


class max_segTree {
public:
    int size;
    vector<int> tree;
    
    max_segTree(int n) {
        for (size = 1; size < n; size *= 2);
        tree.resize(size * 2);
        
        for (int i = 0; i < tree.size(); ++i) {
            tree[i] = 0;
        }
    }
    
    int getValue(int pos) {
        int idx = size + pos - 1;
        return tree[idx];
    }
    
    void update(int pos, int x) {
        int idx = size + pos - 1;
        tree[idx] = x;
        idx /= 2;
        
        while (idx) {
            tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
            idx /= 2;
        }
    }
    
    int getMax(int pos, int left, int right, int start, int end) {
        if (left > end || right < start) {
            return 0;
        }
        if (left <= start && end <= right) {
            return tree[pos];
        }
        
        int mid = (start + end) / 2;
        return max(getMax(pos * 2, left, right, start, mid), getMax(pos * 2 + 1, left, right, mid + 1, end));
    }
};


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, n, k, q, a, b;
    
    cin >> T;
    
    while (T--) {
        cin >> n >> k;
        max_segTree maxSegtree(n);
        min_segTree minSegtree(n);
        
        for (int i = 0; i < n; ++i) {
            minSegtree.update(i + 1, i);
            maxSegtree.update(i + 1, i);
        }
        
        
        for (int i = 0; i < k; ++i) {
            cin >> q >> a >> b;
            if (q == 0) {
                int x = minSegtree.getValue(a + 1);
                int y = minSegtree.getValue(b + 1);
                minSegtree.update(b + 1, x);
                minSegtree.update(a + 1, y);
                maxSegtree.update(b + 1, x);
                maxSegtree.update(a + 1, y);
            } else {
                int l = minSegtree.getMin(1, a + 1, b + 1, 1, minSegtree.size);
                int r = maxSegtree.getMax(1, a + 1, b + 1, 1 , maxSegtree.size);
                
                if (l == a && r == b) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
    
    
  
    return 0;
}
