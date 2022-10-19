// 15666
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n, m;

vector<int> arr;
int ans[9];
bool visited[9];

void backtracking(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    int before = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != before) {
            if (cnt == 0) {
                ans[cnt] = arr[i];
                before = arr[i];
                backtracking(cnt + 1);
            } else {
                if (arr[i] >= ans[cnt - 1]) {
                    ans[cnt] = arr[i];
                    before = arr[i];
                    backtracking(cnt + 1);
                }
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
        arr.push_back(num);
    }
    
    sort(arr.begin(), arr.end());

    backtracking(0);
    
    
    return 0;
}
