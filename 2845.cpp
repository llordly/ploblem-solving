// 2845
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int l, p;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;
    cin >> l >> p;
    int mul = l * p;
    for (int i = 0; i < 5; ++i) {
        cin >> num;
        cout << num - mul << " ";
    }
   
    
    return 0;
}
