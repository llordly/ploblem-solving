//11723

#include <iostream>
#include <string.h>

using namespace std;

int main(void) {
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int set[20] = {0, };
    string operation;
    int m, operand;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> operation;
        if (operation == "add") {
            cin >> operand;
            set[operand - 1] = 1;
        } else if (operation == "remove") {
            cin >> operand;
            set[operand - 1] = 0;
        } else if (operation == "check") {
            cin >> operand;
            if (set[operand - 1]) cout << 1 << "\n";
            else cout << 0 << "\n";
        } else if (operation == "toggle") {
            cin >> operand;
            set[operand - 1] = !set[operand - 1];
        } else if (operation == "all") {
            for (int j = 0; j < 20; ++j) {
                set[j] = 1;
            }
        } else if (operation == "empty") {
            memset(set, 0, 20 * sizeof(int));
        }
    }
   
    return 0;
}
