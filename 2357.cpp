// 2357
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

class max_segTree {
public:
    vector<ll> tree;
    int size;
    
    max_segTree(int n) {
        for (size = 1; size < n; size *= 2);
        tree.resize(size * 2);
        for (int i = 0; i < tree.size(); ++i) {
            tree[i] = -1;
        }
    }

    void updateMax(int pos, ll x) {
        int idx = size + pos - 1;
        
        while (idx) {
            tree[idx] = max(tree[idx], x);
            idx /= 2;
        }
    }
    
    ll getMax(int pos, int left, int right, int start, int end) {
        if (left > end || right < start) {
            return 0;
        }
        if (left <= start && end <= right) {
            return tree[pos];
        }
        
        int mid = (start + end) / 2;
        return max(getMax(pos * 2, left, right, start, mid),getMax(pos * 2 + 1, left, right, mid + 1, end));
    }
};

class min_segTree {
public:
    vector<ll> tree;
    int size;
    
    min_segTree(int n) {
        for (size = 1; size < n; size *= 2);
        tree.resize(size * 2);
        for (int i = 0; i < tree.size(); ++i) {
            tree[i] = 1e10;
        }
    }
    
    void updateMin(int pos, ll x) {
        int idx = size + pos - 1;
        
        while (idx) {
            tree[idx] = min(tree[idx], x);
            idx /= 2;
        }
    }
    
    ll getMin(int pos, int left, int right, int start, int end) {
        if (left > end || right < start) {
            return 1e10;
        }
        if (left <= start && end <= right) {
            return tree[pos];
        }
        
        int mid = (start + end) / 2;
        return min(getMin(pos * 2, left, right, start, mid), getMin(pos * 2 + 1, left, right, mid + 1, end));
    }
};


int n, m;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    min_segTree minTree(n);
    max_segTree maxTree(n);
    
    ll num;
    
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        minTree.updateMin(i, num);
        maxTree.updateMax(i, num);
    }
    
    int a, b;
    
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        cout << minTree.getMin(1, a, b, 1, minTree.size) << " ";
        cout << maxTree.getMax(1, a, b, 1, maxTree.size) << "\n";
    }
    
   
    
  
    return 0;
}
