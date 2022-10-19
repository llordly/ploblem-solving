/*
20300 서강근육맨
그리디
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

typedef long long ll;


int n;

ll ans;

ll Max(ll a, ll b) {
    return a > b ? a : b;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    ll num;

    vector<ll> protein;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        protein.push_back(num);
    }

    sort(protein.begin(), protein.end());

    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; ++i) {
            ans = Max(ans, protein[i] + protein[n - i - 1]);
        }
    } else {
        for (int i = 0; i < n / 2; ++i) {
            ans = Max(ans, protein[i] + protein[n - i - 2]);
        }
        ans = Max(ans, protein[n - 1]);
    }

    cout << ans;


    return 0;
}