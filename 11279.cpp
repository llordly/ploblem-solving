//11279

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, input;
    cin >> n;
    priority_queue<int, vector<int>, less<int>> heap;
    
    for (int i = 0; i < n; ++i) {
        cin >> input;
        if (input == 0) {
            if (heap.empty()) {
                cout << 0 << "\n";
            } else {
                cout << heap.top() << "\n";
                heap.pop();
            }
        } else {
            heap.push(input);
        }
    }
    
    return 0;
}
