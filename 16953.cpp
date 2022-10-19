// 16953
#include <iostream>
#include <vector>
#include <queue>


using namespace std;
typedef long long ll;

ll a, b;



int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    queue<pair<ll, ll>> q;
    q.push({a, 0});

    ll ans = 0;

    while (!q.empty()) {
        auto node = q.front();
        q.pop();

        if (node.first == b) {
            ans = node.second;
            break;
        }

        ll one = node.first * 2;
        ll two = node.first * 10 + 1;
        if (one <= b)
            q.push({one, node.second + 1});
        if (two <= b)
            q.push({two, node.second + 1});
    }

    if (ans) cout << ans + 1;
    else cout << -1;



    return 0;
}

