// 3273
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>

using namespace std;


int n, x;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> arr;
    int num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        arr.push_back(num);
    }
    cin >> x;
    
    sort(arr.begin(), arr.end());
    
    int left = 0;
    int right = n - 1;
    int temp = 0;
    int ans = 0;
    
    while (left < right) {
        temp = arr[left] + arr[right];
        
        if (temp == x) {
            ans++;
            left++;
            right--;
        }
        else if (temp < x) left++;
        else right--;
    }
    
    cout << ans;

    return 0;
}
