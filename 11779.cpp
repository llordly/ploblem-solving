// 11779
#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int n, m;

vector<vector<pair<int, int>>> adj;
vector<int> dist;
vector<int> path;

void dijkstra(int start) {
    fill(dist.begin(), dist.end(), INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
    heap.push({0, start});
    dist[start] = 0;
    path[start] = 0;

    while (!heap.empty()) {
        auto node = heap.top();
        heap.pop();

        int dis = node.first;
        int now = node.second;

        if (dis > dist[now]) continue;

        for (auto x : adj[now]) {
            int newDis = dis + x.second;
            if (dist[x.first] > newDis) {
                dist[x.first] = newDis;
                heap.push({newDis, x.first});
                path[x.first] = now;
//                cout << "now : " << now << "  next node : " << x.first << "  newDis : " << newDis << "\n";
            }
        }

    }

}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    int start, end;
    cin >> n >> m;
    adj.resize(n + 1);
    dist.resize(n + 1);
    path.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    cin >> start >> end;

    dijkstra(start);


    cout << dist[end] << "\n";

    int f = end;
    vector<int> ans;
    ans.push_back(end);
    while (path[f] != 0) {
        ans.push_back(path[f]);
        f = path[f];
    }

    cout << ans.size() << "\n";

    while (!ans.empty()) {
        cout << ans.back() << " ";
        ans.pop_back();
    }

    return 0;
}
