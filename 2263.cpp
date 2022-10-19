// 2263
#include <iostream>
#include <vector>

using namespace std;

vector<int> inO;
vector<int> postO;
int idx[100001];
int n;

void preOrder(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return;
    
    int root = postO[postEnd];
    cout << root << " ";
    
    int lSize = idx[root] - inStart;
    preOrder(inStart, idx[root] - 1, postStart, postStart + lSize - 1);
    preOrder(idx[root] + 1, inEnd, postStart + lSize, postEnd - 1);
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        inO.push_back(num);
    }
    for (int i = 0; i < n; ++i) {
        cin >> num;
        postO.push_back(num);
    }
    
    for (int i = 0; i < n; ++i) {
        idx[inO[i]] = i;
    }
    
    preOrder(0, n - 1, 0, n - 1);

    return 0;
}

