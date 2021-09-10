//1697

#include <iostream>
#include <queue>

using namespace std;

vector<int> visited(100001);

int n, k;
int main(void) {
//    ios::ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    cin >> n >> k;
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));
    int ans;
    
    while(!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();
        int num = node.first;
        int dis = node.second;
        visited[num] = true;
        if(num == k) {
            ans = dis;
            break;
        }
        if (num + 1 >= 0 && num + 1 <= 100000)
            if(!visited[num + 1])
                q.push(make_pair(num + 1, dis + 1));
        if (num - 1 >= 0 && num - 1 <= 100000)
            if(!visited[num - 1])
                q.push(make_pair(num - 1, dis + 1));
        if (num * 2 >= 0 && num * 2 <= 100000) {
            if(!visited[num * 2])
                q.push(make_pair(num * 2,dis + 1));
        }
    }
    
    cout << ans;
    
    return 0;
}
