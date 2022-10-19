// 9019

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


void bfs(int a, int b) {
    bool visited[10000] = {false};
    char op[10000] = "";
    int path[10000] = {0};
    queue<int> q;
    q.push(a);
    path[a] = a;
    op[a] = '0';
    
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == b) break;
        int d = (2 * node) % 10000;
        int s = node - 1;
        if (s == -1) s = 9999;
        int rotate[4];
        int part = node;
        for (int i = 3; i >= 0; --i) {
            rotate[i] = part % 10;
            part /= 10;
        }
        int l = 0;
        int r = 0;
        int pow = 1000;
        for (int i = 1; i < 5; ++i) {
            l += rotate[i % 4] * pow;
            pow /= 10;
        }
        pow = 1000;
        for (int i = 3; i < 7; ++i) {
            r += rotate[i % 4] * pow;
            pow /= 10;
        }
        if (!visited[d]) {
            q.push(d);
            visited[d] = true;
            path[d] = node;
            op[d] = 'D';
        }
        if (!visited[s]) {
            q.push(s);
            visited[s] = true;
            path[s] = node;
            op[s] = 'S';
        }
        if (!visited[l]) {
            q.push(l);
            visited[l] = true;
            path[l] = node;
            op[l] = 'L';
        }
        if (!visited[r]) {
            q.push(r);
            visited[r] = true;
            path[r] = node;
            op[r] = 'R';
        }
    }
    stack<char> s;
    int temp = path[b];
    s.push(op[b]);
    while (temp != a) {
        s.push(op[temp]);
        temp = path[temp];
    }
    string ans = "";
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    cout << ans << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        bfs(a, b);
    }
    
    return 0;
}

