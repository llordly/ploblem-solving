// 2512
#include <iostream>
#include <vector>




using namespace std;

int n;
vector<int> arr;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num, total;
    cin >> n;
    
    int max = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> num;
        arr.push_back(num);
        if (num > max) max = num;
    }
    
    cin >> total;
    
    int low = 1;
    int high = max;
    int ans = 0;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        int temp = 0;
        
        for (int i = 0; i < n; ++i) {
            if (arr[i] >= mid) {
                temp += mid;
            } else {
                temp += arr[i];
            }
        }
        
        if (temp <= total) {
            low = mid + 1;
            ans = mid;
        } else {
            high = mid - 1;
        }
    }
    
    
    cout << ans;
    
    return 0;
}
