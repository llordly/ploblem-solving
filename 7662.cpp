//7662

#include <iostream>
#include <set>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, k;
    long long n;
    string oper;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> k;
        
        multiset<long long> mulset;
        multiset<long long>::iterator iter;
        
        for (int j = 0; j < k; ++j) {
            cin >> oper >> n;
            if (oper == "I") {
                mulset.insert(n);
            } else if (oper == "D") {
                if (mulset.empty()) continue;
                if (n == 1) {
                    iter = mulset.end();
                    iter--;
                    mulset.erase(iter);
                } else {
                    mulset.erase(mulset.begin());
                }
                
            }
        }
        if (mulset.empty()) cout << "EMPTY" << "\n";
        else {
            iter = mulset.end();
            iter--;
            cout << *iter << " " << *mulset.begin() << "\n";
        }
    }
    return 0;
}

