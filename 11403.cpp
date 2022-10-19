// 11430

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> adj;

int exist[100][100] = {0};
int n;

void dfs(int start) {
    bool visited[100]={false};
    stack<int> s;
    s.push(start);
    
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        
        for (int x : adj[node]) {
            if (!visited[x]) {
                s.push(x);
                visited[x] = true;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (visited[i]) exist[start][i] = true;
    }
    
}

    
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int input;
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> input;
            if (input) adj[i].push_back(j);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        dfs(i);
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << exist[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

