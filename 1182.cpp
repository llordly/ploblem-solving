// 1182
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int n, s, ans;
int arr[21];

void combi(int pos, int cnt, int sum) {
    if (cnt == n || pos == n) return;
    
    combi(pos + 1, cnt + 1, sum + arr[pos]);
    if (sum + arr[pos] == s) ans++;
    combi(pos + 1, cnt, sum);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> s;
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    combi(0, 0, 0);
    cout << ans;
  
    return 0;
}


