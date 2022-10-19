// 2661
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

int n;
bool ans = false;

string num[3] = {"1", "2", "3"};

void backtracking(string arr) {
    if (ans) return;
    if (arr.length() == n) {
        cout << arr;
        ans = true;
        return;
    }
    
    for (int i = 0; i < 3; ++i) {
        string temp = arr + num[i];
        int pos = temp.length();
        bool check = true;
        for (int j = 1; j <= pos / 2; ++j) {
            if (temp.substr(pos - j * 2, j) == temp.substr(pos - j)) {
                check = false;
                break;
            }
        }
        if (check) {
            backtracking(arr + num[i]);
        }
    }
    
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    cin >> n;
    backtracking("");
    
    
    return 0;
}
