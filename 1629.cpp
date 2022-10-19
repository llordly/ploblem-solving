// 1629

#include <iostream>
#include <vector>

using namespace std;

long long mul(long long a, long long b, long long c) {
    long long ans = 1;
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

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long a, b, c;
    cin >> a >> b >> c;
    cout << mul(a, b, c);
    
    return 0;
}

