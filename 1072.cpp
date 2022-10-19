// 1072
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long x, y;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> x >> y;
    
    long long win = y * 100 / x;
    long long loose = x - y;
    
    long long start = x;
    long long end = 2e9;
    long long ans = 0;
    
    if (win >= 99) cout << -1;
    else {
        while (start <= end) {
            long long mid = (start + end) / 2;
            
            long long temp = (mid - loose) * 100 / mid;
            if (temp > win) {
                end = mid - 1;
                ans = mid;
            } else {
                start = mid + 1;
            }
        }
        
        if (ans == 0) cout << -1;
        else cout << ans - x;
    }
    
    return 0;
}
