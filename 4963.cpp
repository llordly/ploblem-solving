// 4936
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>

using namespace std;

int dx[8] = {0, 0, 1, -1, -1, 1, -1, 1};
int dy[8] = {-1, 1, 0, 0, -1, 1, 1, -1};




int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int w, h;
    while(true) {
        cin >> w >> h;
        if (w == 0 && h == 0) return 0;
        
        int arr[51][51] = {0};
        bool visited[51][51] = {false};
        int cnt = 0;
        
        
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> arr[i][j];
            }
        }
        
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (arr[i][j] && !visited[i][j]) {
                    queue<pair<int, int>> q;
                    visited[i][j] = true;
                    q.push({i, j});
                    
                    while (!q.empty()) {
                        auto node = q.front();
                        q.pop();
                        
                        int x = node.first;
                        int y = node.second;
                        
                        for (int i = 0; i < 8; ++i) {
                            int nx = x + dx[i];
                            int ny = y + dy[i];
                            
                            if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                                if (arr[nx][ny] && !visited[nx][ny]) {
                                    q.push({nx, ny});
                                    visited[nx][ny] = true;
                                }
                            }
                        }
                    }
                    cnt++;
                }
            }
        }
        
        cout << cnt << "\n";
    }
    
    
    return 0;
}
