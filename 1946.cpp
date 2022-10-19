// 1946

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t, n, a, b;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        cin >> n;
        vector<pair<int, int>> arr;
        vector<bool> check(n, true);
        int ans = 1;
        for (int j = 0; j < n; ++j) {
            cin >> a >> b;
            arr.push_back({a, b});
        }
        
        sort(arr.begin(), arr.end());

        int min = arr[0].second;
        for (int j = 1; j < n; ++j) {
            if (arr[j].second < min) {
                ans++;
                min = arr[j].second;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
