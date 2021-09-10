//1620

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int n, m;
vector<string> poketmon;
map<string, int> poketDic;

int main(void) {
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    string input;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        poketmon.push_back(input);
        poketDic.insert(make_pair(input, i + 1));
    }
    for (int i = 0; i < m; ++i) {
        cin >> input;
        if (input[0] >= 65) {
            cout << poketDic[input] << "\n";
        } else {
            cout << poketmon[stoi(input) - 1] << "\n";
        }
    }
    return 0;
}
