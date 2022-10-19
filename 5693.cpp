// 5693
#include <iostream>
#include <vector>


using namespace std;

vector<int> btree;

void postOrder(int inStart, int inEnd) {
    if (inStart > inEnd) return;

    int root = btree[inStart];
    int lSize = 0;

    for (int i = inStart; i <= inEnd; ++i) {
        if (btree[i] > root) {
            lSize = i - inStart - 1;
            break;
        }
    }

    postOrder(inStart + 1, inStart + lSize);
    postOrder(inStart + lSize + 1, inEnd);
    cout << root << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;

    while(cin >> num) {
        btree.push_back(num);
    }

    postOrder(0, btree.size() - 1);

    return 0;
}
