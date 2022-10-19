// 2473
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;


int n;

int Min(int a, int b) { return a < b ? a : b; }

typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    vector<ll> arr;
    ll num;
    
    for (int i = 0; i < n; ++i) {
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());
    
    ll a = 0;
    ll b = 0;
    ll c = 0;
    
    ll min = 1e10;
    
    for (int i = 0; i < n; ++i) {
        int start = 0;
        int end = n - 1;
        
        if (i == 0) start = 1;
        if (i == n - 1) end = n - 2;
        
        
        ll temp = 0;
        
        while (start < end) {
            temp = arr[start] + arr[end] + arr[i];
            if (abs(temp) < min) {
                min = abs(temp);
                a = arr[start];
                b = arr[i];
                c = arr[end];
            }
            if (temp < 0) {
                start++;
                if (start == i) start++;
            } else {
                end--;
                if (end == i) end--;
            }
        }
    }
    
    ll ans[3] = {a, b, c};
    sort(ans, ans + 3);
    for (int i = 0; i < 3; ++i) {
        cout << ans[i] << " ";
    }
    
    return 0;
}
