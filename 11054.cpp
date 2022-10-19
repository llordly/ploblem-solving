// 11054
#include <iostream>
#include <vector>


using namespace std;

int Max(int a, int b) {
    return a > b ? a : b;
}

int n;

vector<int> arr;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        arr.push_back(num);
    }
    
    vector<int> front(n);
    vector<int> back(n);
    
    for (int i = 0; i < n; ++i) {
        front[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                front[i] = Max(front[i], front[j] + 1);
            }
        }
    }
    
    for (int i = n - 1; i >= 0; --i) {
        back[i] = 1;
        for (int j = n - 1; j > i; --j) {
            if (arr[j] < arr[i]) {
                back[i] = Max(back[i], back[j] + 1);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int temp = front[i] + back[i];
        ans = Max(ans, temp);
    }

    cout << ans - 1;
    return 0;
}
