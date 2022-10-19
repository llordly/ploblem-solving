// 16928

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj(101);
bool visited[101];
int dis[101];

void bfs() {
    queue<int> q;
    visited[1] = true;
    q.push(1);
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        visited[node] = true;
        for (int i = 1; i <= 6; ++i) {
            int newNode = node + i;
            if (newNode > 100) continue;
            if (adj[newNode] != 0) newNode = adj[newNode];
            if (!visited[newNode]) {
                q.push(newNode);
                visited[newNode] = true;
                dis[newNode] = dis[node] + 1;
            }
        }
    }
}

int main(void) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < n + m; ++i) {
        cin >> x >> y;
        adj[x] = y;
    }
    bfs();
    cout << dis[100];
    
    return 0;
}

