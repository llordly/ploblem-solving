// 11286

#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, input;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        if (input == 0) {
            if (q.empty()) cout << "0" << "\n";
            else {
                cout << q.top().first * q.top().second << "\n";
                q.pop();
            }
        } else {
            q.push({abs(input), input/abs(input)});
        }
    }
    return 0;
}

