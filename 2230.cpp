// 2230
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;


int n, m;

int Min(int a, int b) { return a < b ? a : b; }

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    vector<int> arr;
    int num;
    
    for (int i = 0; i < n; ++i) {
        cin >> num;
        arr.push_back(num);
    }
    
    sort(arr.begin(), arr.end());
    int start = 0;
    int end = 0;
    int min = 2e9;
    int diff;
    
    while (end < n && start < n) {
        diff = arr[end] - arr[start];
        
        if (diff >= m) {
            min = Min(min, diff);
            start++;
        } else {
            end++;
        }
    }
    cout << min;
    
    return 0;
}
