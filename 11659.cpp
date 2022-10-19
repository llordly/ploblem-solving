// 11659

#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, num, a, b;
    cin >> n >> m;
    vector<int> arr(n + 1);
    arr[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        arr[i] = arr[i - 1] + num;
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << "\n";
    }
    
    return 0;
}

