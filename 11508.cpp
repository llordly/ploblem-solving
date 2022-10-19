/*

*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int n;
int ans;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> milk;
    int price;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> price;
        milk.push_back(price);
    }

    sort(milk.begin(), milk.end(), greater<int>());


    int q = n / 3;
    int r = n % 3;

    for (int i = 0; i <= q; ++i) {
        if (i == q) {
            for (int j = i * 3; j < i * 3 + r; ++j) {
                ans += milk[j];
            }
        } else {
            for (int j = i * 3; j < i * 3 + 2; ++j) {
                ans += milk[j];
            }
        }
    }

    cout << ans;

}