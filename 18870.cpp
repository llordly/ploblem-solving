//18870

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> arr, comArr;
    
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        arr.push_back(x);
        comArr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    
    for (int i = 0; i < n; ++i) {
        int c = comArr[i];
        cout << lower_bound(arr.begin(), arr.end(), c) - arr.begin() << " ";
    }
    
    return 0;
}
