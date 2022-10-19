// 12852
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>

using namespace std;

bool visited[1000001];
int path[1000001];

int bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int cnt = 0;
    
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int temp;
            auto node = q.front();
            q.pop();

            if (node == 1) return cnt;
            
            if (node % 3 == 0 && !visited[node / 3]) {
                temp = node / 3;
                q.push(temp);
                visited[temp] = true;
                path[temp] = node;
            }
            if (node % 2 == 0 && !visited[node / 2]) {
                temp = node / 2;
                q.push(temp);
                visited[temp] = true;
                path[temp] = node;
            }
            if (node - 1 > 0 && !visited[node - 1]) {
                temp = node - 1;
                q.push(temp);
                visited[temp] = true;
                path[temp] = node;
            }
        }
        cnt++;
    }
    return 0;
}

int n;

void printAns(int x) {
    if (x == 0) return;
    printAns(path[x]);
    cout << x << " ";
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    
    cout << bfs(n) << "\n";
    printAns(1);
    
    
    return 0;
}
