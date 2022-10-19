// 17219

#include <iostream>
#include <map>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    string url, pw;
    cin >> n >> m;
    map<string, string> dic;
    for (int i = 0; i < n; ++i) {
        cin >> url >> pw;
        dic.insert({url, pw});
    }
    for (int i = 0; i < m; ++i) {
        cin >> url;
        cout << dic.find(url)->second << "\n";
    }
    return 0;
}

