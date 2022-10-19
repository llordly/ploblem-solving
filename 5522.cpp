// 5522
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cmath>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 0;
    int a;
    for (int i = 0; i < 5; ++i) {
        cin >> a;
        n += a;
    }
    cout << n;
    
    return 0;
}
