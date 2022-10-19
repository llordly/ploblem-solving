// 13172
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

typedef long long ll;

using namespace std;

int m, n, s;
ll X = 1000000007;
ll ans = 0;

ll mul(ll a, ll b, ll c) {
    ll ans = 1;
    while (b > 0) {
        if (b % 2 != 0) {
            ans *= a;
            ans %= c;
        }
        a *= a;
        a %= c;
        b /= 2;
    }
    return ans;
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}



int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m;
    
    // s / n
    // a * b^-1 mod X
    // b^-1 = b^X -2 mod X
    for (int i = 0; i < m; ++i) {
        cin >> n >> s;
        int fac = gcd(n, s);
        n /= fac;
        s /= fac;
        ans += (s * mul(n, X - 2, X)) % X;
        ans %= X;
    }
    
    cout << ans;
    
    return 0;
}
