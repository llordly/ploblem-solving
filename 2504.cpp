/*
*/

#include <iostream>
#include <string>
#include <stack>


using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    stack<int> s;
    string line;

    cin >> line;

    int ans = 0;

    for (int i = 0; i < line.size(); ++i) {
        // cout << "i: " << i << "\n";
        if (s.empty()) {
            if (line[i] == ']' || line[i] == ')') {
                cout << 0;
                return 0;
            }
        }

        // -1 = '[', -2 = '(', -3 = ']', -4 = ')'
        if (line[i] == '[') {
            s.push(-1);
        } else if (line[i] == '(') {
            s.push(-2);
        } else if (line[i] == ']') {
            int temp = 0;
            while (!s.empty()) {
                int a = s.top();
                s.pop();

                if (a > 0) {
                    temp += a;
                } else if (a == -2) {
                    cout << 0;
                    return 0;
                } else if (a == -1) {
                    if (temp == 0) {
                        s.push(3);
                        // cout << "push 3\n";
                    } else {
                        s.push(3 * temp);
                        // cout << "push 3 * x\n";
                    }
                    break;
                }
            }
            if (s.empty()) {
                cout << 0;
                return 0;
            }
        } else if (line[i] == ')') {
            int temp = 0;
            while (!s.empty()) {
                int a = s.top();
                s.pop();

                if (a > 0) {
                    temp += a;
                } else if (a == -1) {
                    cout << 0;
                    return 0;
                } else if (a == -2) {
                    if (temp == 0) {
                        s.push(2);
                        // cout << "push 2\n";
                    } else {
                        s.push(2 * temp);
                        // cout << "push 2 * x\n";
                    }
                    break;
                }
            }
            if (s.empty()) {
                cout << 0;
                return 0;
            }
        }
    }

    if (s.top() == -1 || s.top() == -2) {
        cout << 0;
        return 0;
    }

    while(!s.empty()) {
        ans += s.top();
        // cout << "ans: " << ans << "\n";
        s.pop();
    }

    cout << ans;

    return 0;
}