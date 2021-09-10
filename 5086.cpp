// 5086

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> arr;

int main(void){
    int a, b;
    while(true){
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        arr.push_back(make_pair(a, b));
    }
    for (int i = 0; i < arr.size(); ++i){
        int c = arr[i].first;
        int d = arr[i].second;
        if (d % c == 0)
            cout << "factor" << endl;
        else if (c % d == 0)
            cout << "multiple" << endl;
        else
            cout << "neither" << endl;
    }
    
    return 0;
}
