// 2467
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;



int n;
vector<int> arr;
int a, b;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    int num;
    
    for (int i = 0; i < n; ++i) {
        cin >> num;
        arr.push_back(num);
    }
    
    sort(arr.begin(), arr.end());
    
    int left = 0;
    int right = n - 1;
    a = arr[0];
    b = arr[n - 1];
    int temp = 0;
    int min = abs(a + b);
    
    while (left < right) {
        temp = arr[left] + arr[right];
        
        if (abs(temp) < min) {
            min = abs(temp);
            a = arr[left];
            b = arr[right];
        }
        if (temp == 0) {
            break;
        }
        if (temp > 0) {
            right--;
        } else {
            left++;
        }
    }
    
    cout << a << " " << b;
    
    return 0;
}
