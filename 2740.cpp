// 2740

#include <iostream>
#include <vector>


using namespace std;

int n, m, k;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int input;
    
    cin >> n >> m;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> input;
            a[i].push_back(input);
        }
    }
    
    cin >> m >> k;
    vector<vector<int>> b(m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> input;
            b[i].push_back(input);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            int temp = 0;
            for (int l = 0; l < m; ++l) {
                temp += a[i][l] * b[l][j];
            }
            cout << temp << " ";
        }
        cout << "\n";
    }
    
    
    return 0;
}

