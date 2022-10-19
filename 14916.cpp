/*
14916 거스름돈
그리디
*/

#include <iostream>


using namespace std;


int n;

void solve() {
    int cnt = 0;

    cnt = n / 5;
    n %= 5;

    if (n % 2 == 0) {
        cnt += n / 2;
        n %= 2;
    }

    while ((n % 2 != 0) && cnt) {
        cnt--;
        n += 5;
        if (n % 2 == 0) {
            cnt += (n / 2);
            break;
        }
    }

    if (cnt) cout << cnt;
    else cout << -1;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    solve();
}