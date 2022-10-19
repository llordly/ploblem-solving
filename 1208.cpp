// 1208
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

typedef long long ll;

ll arr[41], l[4000001], r[4000001];

ll n, s, ans;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> s;
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
  
    ll half = n / 2;
    
    for (int i = 0; i < (1 << half); ++i) {
        ll temp = 0;
        for (int j = 0; j < half; ++j) {
            if (i & (1 << j)) {
                temp += arr[j];
            }
        }
        l[temp + 2000000]++;
    }
    
    
    
    for (int i = 0; i < (1 << (n - half)); ++i) {
        ll temp = 0;
        for (int j = 0; j < n - half; ++j) {
            if (i & (1 << j)) {
                temp += arr[j + half];
            }
        }
        r[temp + 2000000]++;
    }

    ll left = 0, right = 4000000;
    
    if (!s) ans--;
    s += 4000000;

    while (left <= 4000000 && right >= 0) {
        if (left + right == s) {
            ans += l[left] * r[right];
            left++;
            right--;
        } else if (left + right > s) {
            right--;
        } else if (left + right < s) {
            left++;
        }
    }

    cout << ans;
    
    return 0;
}
