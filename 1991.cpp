// 1991
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int n;

char tree[26][2];

void preOrder(char node) {
    if (node != '.') {
        cout << node;
        preOrder(tree[node - 65][0]);
        preOrder(tree[node - 65][1]);
    }
}

void inOrder(char node) {
    if (node != '.') {
        inOrder(tree[node - 65][0]);
        cout << node;
        inOrder(tree[node - 65][1]);
    }
}

void postOrder(char node) {
    if (node != '.') {
        postOrder(tree[node - 65][0]);
        postOrder(tree[node - 65][1]);
        cout << node;
    }
}



int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char p, l, r;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> p >> l >> r;
        tree[p - 65][0] = l;
        tree[p - 65][1] = r;
    }
    
    preOrder('A');
    cout << "\n";
    inOrder('A');
    cout << "\n";
    postOrder('A');

    return 0;
}
