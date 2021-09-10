// 10814
#include <iostream>
#include <vector>
#include <algorithm>

int n;

using namespace std;


bool cmp(pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}

int main(void){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    cin >> n;
    vector<pair<int, string>> con(n);
    
    for (int i = 0; i < n; ++i){
        cin >> con[i].first >> con[i].second;
    }
    stable_sort(con.begin(), con.end(), cmp);
    
    for (int i = 0; i < n; ++i){
        cout << con[i].first << " " << con[i].second << "\n";
    }
  
    return 0;
}
