// 3003
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;
    int arr[6] = {1, 1, 2, 2, 2, 8};
    
    for (int i = 0; i < 6; ++i) {
        cin >> num;
        cout << arr[i] - num << " ";
    }
   
    
    return 0;
}
