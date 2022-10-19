// 10830

#include <iostream>
#include <vector>
#define MOD 1000

using namespace std;

int n;
long long b;

vector<vector<long long>> A;

vector<vector<long long>> mulMatrix(vector<vector<long long>> A, vector<vector<long long>> B) {
    vector<vector<long long>> result(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int temp = 0;
            for (int l = 0; l < n; ++l) {
                temp += (A[i][l] * B[l][j]);
            }
            temp %= MOD;
            result[i].push_back(temp);
        }
    }
    return result;
}

void mul (vector<vector<long long>> A, long long b) {
    vector<vector<long long>> ans(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                ans[i][j] = 1;
            }
        }
    }
    
    while (b > 0) {
        if (b % 2 != 0) {
            ans = mulMatrix(ans, A);
        }
        A = mulMatrix(A, A);
        b /= 2;
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    cin >> n >> b;
    A.resize(n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> num;
            A[i].push_back(num);
        }
    }
    
    mul(A, b);
    

    return 0;
}
