// 13549
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 1e9
using namespace std;

vector<int> dist(100001, INF);

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
    heap.push({0, start});
    dist[start] = 0;
    
    while (!heap.empty()) {
        auto node = heap.top();
        heap.pop();
        int dis = node.first;
        int now = node.second;
        
        if (dis > dist[now]) continue;
        
        if (now + 1 >= 0 && now + 1 <= 100000) {
            if (dist[now + 1] > dis + 1) {
                dist[now + 1] = dis + 1;
                heap.push({dis + 1, now + 1});
            }
        }
        
        if (now - 1 >= 0 && now - 1 <= 100000) {
            if (dist[now - 1] > dis + 1) {
                dist[now - 1] = dis + 1;
                heap.push({dis + 1, now - 1});
            }
        }
    
        if (now * 2 >= 0 && now * 2 <= 100000) {
            if (dist[now * 2] > dis) {
                dist[now * 2] = dis;
                heap.push({dis, now * 2});
            }
        }
    }
}

int n, k;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    
    dijkstra(n);
    
    cout << dist[k];
    
    return 0;
}



