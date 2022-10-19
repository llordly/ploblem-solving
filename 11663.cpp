/*

*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n, m;



int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> point;
    cin >> n >> m;
    int num;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        point.push_back(num);
    }

    sort(point.begin(), point.end());


    int a, b;

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;

        int start = lower_bound(point.begin(), point.end(), a) - point.begin();
        int end = upper_bound(point.begin(), point.end(), b) - point.begin();
        cout << end - start << "\n";
    }

    return 0;
}