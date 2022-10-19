/*
20115 에너지 드링크
그리디
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int n;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int amount;

    vector<double> drink;

    for (int i = 0; i < n; ++i) {
        cin >> amount;
        drink.push_back(amount);
    }

    sort(drink.begin(), drink.end());

    double ans = 0;

    for (int i = 0; i < n - 1; ++i) {
        ans += drink[i];
    }

    ans /= 2;
    ans += drink[n - 1];
    cout << ans;

    return 0;
}