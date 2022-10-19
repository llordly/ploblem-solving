//2696

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

int T, M;

void solve(int m) {
    int num;
    vector<int> ans;
    int mid = 0;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int, vector<int>, less<int>> max_heap;
    
    for (int i = 0; i < m; ++i) {
        cin >> num;
        
        
        if (i == 0) {
            mid = num;
            ans.push_back(mid);
            continue;
        }
        
        if (num > mid) {
            min_heap.push(num);
        } else max_heap.push(num);
        
        if (!(i & 1)) {
            if (min_heap.size() > max_heap.size()) {
                max_heap.push(mid);
                mid = min_heap.top();
                min_heap.pop();
            } else if (min_heap.size() < max_heap.size()) {
                min_heap.push(mid);
                mid = max_heap.top();
                max_heap.pop();
            }
            ans.push_back(mid);
        }
    }
    
    cout << ans.size() << '\n';
    
    for (int i = 0; i < ans.size(); ++i) {
        if (i != 0 && i % 10 == 0) cout << '\n';
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    
    while (T--) {
        cin >> M;
        solve(M);
    }
    
    
    return 0;
}





