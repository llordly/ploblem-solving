// 15654
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

vector<int> permutation;
vector<bool> visited;
int ans[9];

void backtracking(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int i = 0; i < n; ++i) {
        if (cnt == 0) {
            visited[i] = true;
            ans[0] = permutation[i];
            backtracking(cnt + 1);
            visited[i] = false;
        } else {
            if (!visited[i]) {
                visited[i] = true;
                ans[cnt] = permutation[i];
                backtracking(cnt + 1);
                visited[i] = false;
            }
        }
    }
    
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        cin >> num;
        permutation.push_back(num);
    }
    
    visited.resize(n);
    fill(visited.begin(), visited.end(), false);
    sort(permutation.begin(), permutation.end());
    
    backtracking(0);
    
    return 0;
}



