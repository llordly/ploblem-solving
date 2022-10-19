// 1967

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
vector<vector<pair<int, int>>> adj;

int farDis = -1;
int farNode;


void dfs(int start) {
    stack<pair<int, int>> s;
    s.push({start, 0});
    bool visited[100001] = {false};
    visited[start] = true;
    
    while (!s.empty()) {
        pair<int, int> node = s.top();
        s.pop();
        int v = node.first;
        int dis = node.second;
        
        for (auto x : adj[v]) {
            int adjN = x.first;
            int adjDis = x.second;
            if (!visited[adjN]) {
                int newDis = dis + adjDis;
                s.push({adjN, newDis});
                visited[adjN] = true;
                if (newDis > farDis) {
                    farDis = newDis;
                    farNode = adjN;
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v, otherV, dis;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> v >> otherV >> dis;
        adj[v].push_back({otherV, dis});
        adj[otherV].push_back({v, dis});
    }
    
    dfs(1);
    farDis = 0;
    dfs(farNode);
    cout << farDis;
    
    return 0;
}

