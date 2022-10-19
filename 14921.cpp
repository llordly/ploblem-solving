// 14921
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;


int n;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> arr;
    cin >> n;
    int num;
    
    for (int i = 0; i < n; ++i) {
        cin >> num;
        arr.push_back(num);
    }
    
    sort(arr.begin(), arr.end());
    
    int start = 0;
    int end = n - 1;
    int min = 2e9 + 1;
    int temp = 2e9 + 1;
    int sign = 1;
    
    while (start < end) {
        temp = arr[start] + arr[end];
        if (abs(temp) < min) {
            min = abs(temp);
            sign = temp / abs(temp);
        }
        if (temp > 0) {
            end--;
        } else start++;
    }
    
    cout << min * sign;
    
    return 0;
}
