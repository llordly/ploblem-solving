// 12851
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>


using namespace std;

int n, k;

vector<int> visited(100001);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));
    int t = -1;
    int ans = 0;
    
    while(!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();
        int num = node.first;
        int dis = node.second;
        visited[num] = true;
        
        if (num == k && dis == t) ans++;
        if(num == k && t == -1) {
            t = dis;
            ans++;
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
    
    cout << t << "\n" << ans;
    

    return 0;
}
