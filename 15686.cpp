// 15686
#include <iostream>
#include <vector>


using namespace std;

int n, m;
int ans = 1e9;

vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
pair<int, int> permutation[14];
bool visited[14];


int Min(int a, int b) {
    return a > b ? b : a;
}

void backtracking(int cnt, int idx) {
    if (cnt == m) {
        int temp = 0;
        for (int i = 0; i < home.size(); ++i) {
            int min = 1e9;
            for (int j = 0; j < m; ++j) {
                int manhattan = abs(home[i].first - permutation[j].first) + abs(home[i].second - permutation[j].second);
                min = Min(min, manhattan);
            }
            temp += min;
        }
        ans = Min(ans, temp);
        return;
    }
    
    for (int i = idx; i < chicken.size(); ++i) {
        if (!visited[i]) {
            visited[i] = true;
            permutation[cnt] = chicken[i];
            backtracking(cnt + 1, i);
            visited[i] = false;
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
        for (int j = 0; j < n; ++j) {
            cin >> num;
            if (num == 1) home.push_back({i, j});
            if (num == 2) chicken.push_back({i, j});
        }
    }
    
    backtracking(0, 0);
    cout << ans;
    
    
    return 0;
}
