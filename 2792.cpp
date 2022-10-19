// 2792
#include <iostream>
#include <vector>
#include <math.h>



using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, num;
    
    cin >> n >> m;
    
    vector<int> arr;
    
    for (int i = 0; i < m; ++i) {
        cin >> num;
        arr.push_back(num);
    }
    
    int left = 1;
    int right = 1e9;
    int ans = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        long long temp = 0;
        for (int i = 0; i < m; ++i) {
            temp += (long long)(ceil((double)arr[i] / (double)mid));
        }
        
        if (temp <= n) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << ans;
    
    return 0;
}
