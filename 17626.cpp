// 17626

#include <iostream>
#include <stdlib.h>

using namespace std;

int pow[224];
int dp[50001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 1; i <= 223; ++i) {
        pow[i] = i * i;
    }
    
    int n;
    cin >> n;
    
    for (int i = 3; i <= n; ++i) {
        int min = 10000000;
        for (int j = 1; j * j <= i; ++j) {
            int temp = i - pow[j];
            if (min > dp[temp] + 1)
                min = dp[temp] + 1;
        }
        dp[i] = min;
        
    }
    cout << dp[n];
    return 0;
}

