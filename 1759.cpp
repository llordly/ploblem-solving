// 1759
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int l, c;

char cipher[16];
char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

// a e i o u
// 최소 모음 1개, 자음 2개

void backtracking(int pos, int cnt, string str) {
    if (cnt == l) {
        int vowel = 0;
        int consonant = 0;
        for (int i = 0; i < l; ++i) {
            bool check = false;
            for (int j = 0; j < 5; ++j) {
                if (str[i] == vowels[j]) {
                    check = true;
                    vowel++;
                    break;
                }
            }
            if (!check) consonant++;
        }

        if (vowel >= 1 && consonant >= 2) {
            cout << str << "\n";
        }
        return;
    }
    if (pos == c) return;

    backtracking(pos + 1, cnt + 1, str + cipher[pos]);
    backtracking(pos + 1, cnt, str);
    return;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> l >> c;
    
    for (int i = 0; i < c; ++i) {
        cin >> cipher[i];
    }
    
    sort(cipher, cipher + c);
    
    backtracking(0, 0, "");

    return 0;
}
