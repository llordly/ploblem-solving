//1764

#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    //    ios::ios_base::sync_with_stdio(false);
    //    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string input;
    set<string> listen, look, listenLook;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        listen.insert(input);
    }
    for (int i = 0; i < m; ++i) {
        cin >> input;
        look.insert(input);
    }
    set_intersection(listen.begin(), listen.end(), look.begin(), look.end(), inserter(listenLook, listenLook.begin()));
    cout << listenLook.size() << "\n";
    for (set<string>::iterator iter = listenLook.begin(); iter != listenLook.end(); iter++) cout << *iter << "\n";
    return 0;
}
