// 3020
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int n, h;

vector<int> down;
vector<int> up;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    int ans = 1;


    cin >> n >> h;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (i % 2) down.push_back(num);
        else up.push_back(num);
    }

    sort(down.begin(), down.end());
    sort(up.begin(), up.end());

    int min = 200001;

    for (int i = 1; i <= h; ++i) {
        int downCnt = down.size() - (lower_bound(down.begin(), down.end(), i) - down.begin());
        int upCnt = up.size() - (upper_bound(up.begin(), up.end(), h - i) - up.begin());

        int sum = downCnt + upCnt;
        if (min == sum) ans++;
        if (min > sum) {
            min = sum;
            ans = 1;
        }
    }

    cout << min << " " << ans;


    return 0;
}
