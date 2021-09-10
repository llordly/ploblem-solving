// 1037

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int n;

int main(void){
    int div;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> div;
        arr.push_back(div);
    }
    sort(arr.begin(), arr.end());
    cout << arr[0] * arr[arr.size() - 1] << endl;
    return 0;
}
