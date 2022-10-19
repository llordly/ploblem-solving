/*
1758 알바생 강호
그리디
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

typedef long long ll;

int n;
ll ans;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    vector<ll> tip;
    ll num;

    cin >> n;


    for (int i = 0; i < n; ++i) {
        cin >> num;
        tip.push_back(num);
    }

    sort(tip.begin(), tip.end(), greater<ll>());


    for (int i = 0; i < n; ++i) {
        int temp = tip[i] - i;
        if (temp > 0) ans += temp;
    }

    cout << ans;
}