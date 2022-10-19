// 5525

#include <iostream>
#include <vector>

using namespace std;

int sol(string s, int n, int m) {
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int o = 0;
        if (s[i] == 'O') continue;
        
        while (s[i + 1] == 'O' && s[i + 2] == 'I') {
            o++;
            if (o == n) {
                o--;
                ans++;
            }
            i += 2;
        }
    }
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    string s;
    cin >> n >> m >> s;
    cout << sol(s, n, m);
    
    
    return 0;
}

