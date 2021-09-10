// 1541

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ans, num, brace;

int main(void){
    string exp;
    cin >> exp;
    
    for (int i = 0; i < exp.size(); ++i){
        char c = exp[i];
        if (c == '-' || c == '+'){
            if (brace == 1)
                ans -= num;
            else
                ans += num;
            num = 0;
            
            if (c == '-'){
                if (brace == 0)
                    brace = 1;
            }
        }
        else {
            num = num * 10 + (c - '0');
            if (i == exp.size() - 1){
                if (brace == 1)
                    ans -= num;
                else
                    ans += num;
            }
        }
        
    }
    
    cout << ans << endl;
    
    return 0;
}
