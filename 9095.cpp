//9095

#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int arr[12] = {0, 1, 2, 4, 7, 13, 24, 0, 0, 0, 0, 0};
    
    for (int i = 7; i < 12; ++i){
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    
    int test;
    for (int i = 0; i < n; ++i){
        cin >> test;
        cout << arr[test] << "\n";
    }
    return 0;
}

