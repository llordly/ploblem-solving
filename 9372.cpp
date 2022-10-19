// 9372
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cmath>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t, n, m, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
        }
        cout << n - 1 << "\n";
    }
    
    
    return 0;
}
