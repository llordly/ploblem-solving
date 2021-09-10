// 1010

#include <iostream>
#include <vector>

using namespace std;


vector<pair<int, int>> arr;

int combi[31][31];
int n;

int com(int n, int r){
    if (n == r || r == 0){
        combi[n][r] = 1;
        return 1;
    }
    if(combi[n][r])
        return combi[n][r];
    else
        return combi[n][r] = com(n - 1, r - 1) + com(n - 1, r);
}

int main(void){
    int a, b;

    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }
    for (int i = 0; i < n; ++i){
        int c = arr[i].first;
        int d = arr[i].second;
        if (c >= d){
            if (d > c - d)
                cout << com(c, c - d) << endl;
            else
                cout << com(c, d) << endl;
        }
        else{
            if (c > d - c)
                cout << com(d, d - c) << endl;
            else
                cout << com(d, c) << endl;
        }
    }
    return 0;
}
