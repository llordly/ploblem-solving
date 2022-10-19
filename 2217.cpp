/*
2217 로프
그리디
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int Max(int a, int b) { return a > b ? a : b; }


int n;
int ans;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> lope;
    int w;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> w;
        lope.push_back(w);
    }

    sort(lope.begin(), lope.end());

    for (int i = 0; i < n; ++i) {
        ans = Max(ans, lope[i] * (n - i));
    }

    cout << ans;
}