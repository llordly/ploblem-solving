// 15645
#include <iostream>
#include <vector>



using namespace std;

int n;

int Max(int a, int b) {
    return a > b ? a : b;
}

int Min(int a, int b) {
    return a > b ? b : a;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;
    cin >> n;
    vector<int> maxDp(3, 0);
    vector<int> minDp(3, 0);
    
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        int maxA = maxDp[0]; int maxB = maxDp[1]; int maxC = maxDp[2];
        int minA = minDp[0]; int minB = minDp[1]; int minC = minDp[2];
        
        maxDp[0] = Max(maxA, maxB) + a;
        minDp[0] = Min(minA, minB) + a;
        
        maxDp[1] = Max(Max(maxA, maxB), maxC) + b;
        minDp[1] = Min(Min(minA, minB), minC) + b;
        
        maxDp[2] = Max(maxB, maxC) + c;
        minDp[2] = Min(minB, minC) + c;
    }
    
    cout << Max(Max(maxDp[0], maxDp[1]), maxDp[2]) << " ";
    cout << Min(Min(minDp[0], minDp[1]), minDp[2]);
    
    return 0;
}
