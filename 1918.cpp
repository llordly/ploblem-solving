// 1918
#include <iostream>
#include <vector>
#include <stack>


using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    stack<char> s;
    string input;
    cin >> input;
    
    for (int i = 0; i < input.size(); ++i) {
        char x = input[i];
        if (x >= 65 && x <= 90) {
            cout << x;
            continue;
        }
        if (s.empty()) {
            s.push(x);
            continue;
        }
        
        if (x == '*' || x == '/') {
            while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
                cout << s.top();
                s.pop();
            }
            s.push(x);
        } else if (x == '+' || x == '-') {
            while (!s.empty() && s.top() != '(') {
                cout << s.top();
                s.pop();
            }
            s.push(x);
        } else if (x == '(') {
            s.push(x);
        } else if (x == ')') {
            while (!s.empty() && s.top() != '(') {
                cout << s.top();
                s.pop();
            }
            s.pop();
        } else {
            continue;
        }
    }
    
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    
    return 0;
}
