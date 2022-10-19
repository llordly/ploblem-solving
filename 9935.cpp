// 9935
#include <iostream>
#include <vector>
#include <stack>


using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string sentence, bomb;
    cin >> sentence >> bomb;
    string s = "";
    
    for (int i = 0; i < sentence.size(); ++i) {
        s.push_back(sentence[i]);
        if (s.size() >= bomb.size()) {
            if (s.back() == bomb.back()) {
                bool check = true;
                for (int j = 1; j < bomb.size(); ++j) {
                    if (s[s.size() - 1 - j] != bomb[bomb.size() - 1 - j]) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    for (int j = 0; j < bomb.size(); ++j) {
                        s.pop_back();
                    }
                }
            }
        }
    }
    if (s.size() == 0) cout << "FRULA";
    else {
        for (int i = 0; i < s.size(); ++i) {
            cout << s[i];
        }
    }

    return 0;
}

