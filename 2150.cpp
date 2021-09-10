//2150
//Conneted_component

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <cstring>

using namespace std;

int visited[10000];
int finish[10000];
vector<vector<int>> scc;

vector<vector<int>> adj(10000);
vector<vector<int>> radj(10000);

int vsize;
int t = 0;
int com = 0;

void DFS(int v) {
    visited[v] = 1;

    for (int next : adj[v]) {
        if (!visited[next])
            DFS(next);
    }
    finish[t++] = v;
}

void RDFS(int v, vector<int> &newscc) {
    newscc.push_back(v);
    visited[v] = 1;
    
    for (int next: radj[v]) {
        if (!visited[next])
            RDFS(next, newscc);
    }
}

int main(void) {
    int x, y, e;
    scanf("%d %d", &vsize, &e);
    
    for (int i = 0; i < e; ++i) {
        scanf("%d %d", &x, &y);
        x -= 1;
        y -= 1;
        adj[x].push_back(y);
        radj[y].push_back(x);
    }

    for (int i = 0; i < vsize; ++i) {
        if (visited[i] == 0) {
            DFS(i);
        }
    }

    memset(visited, 0, sizeof(visited));
    for (int j = vsize - 1; j >= 0; --j) {
        int root = finish[j];
        if (visited[root] == 0) {
            vector<int> newscc;
            RDFS(root, newscc);
            sort(newscc.begin(), newscc.end());
            scc.push_back(newscc);
        }
    }

    sort(scc.begin(), scc.end());
    printf("%d\n", scc.size());

    for (int i = 0; i < scc.size(); ++i) {
        vector<int> s = scc[i];
        ++com;
        for (int j = 0; j < s.size(); ++j) {
            printf("%d ", s[j] + 1);
        }
        printf("-1\n");
    }

    return 0;
}


