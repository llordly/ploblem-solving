// 11444
#include <iostream>
#include <vector>
#define MOD 1000000007

typedef unsigned long ul;

using namespace std;

ul n;

vector<vector<ul>> mulMat(vector<vector<ul>> a, vector<vector<ul>> b) {
    vector<vector<ul>> result(2);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            ul temp = 0;
            for (int k = 0; k < 2; ++k) {
                temp += (a[i][k] * b[k][j]) % MOD;
            }
            temp %= MOD;
            result[i].push_back(temp);
        }
    }
    return result;
}

void fib(ul n, vector<vector<ul>> a) {
    vector<vector<ul>> ans {
        {1, 0},
        {0, 1}
    };
    while (n > 0) {
        if (n % 2 != 0) {
            ans = mulMat(ans, a);
        }
        a = mulMat(a, a);
        n /= 2;
    }
    cout << ans[0][1];
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<vector<ul>> fibo {
        {1, 1},
        {1, 0}
    };
    cin >> n;
    
    fib(n, fibo);
    
    return 0;
}
