// 6549

#include <iostream>
#include <vector>


using namespace std;
typedef long long ll;

int n;
vector<int> histogram;


ll Min(ll a, ll b) {
    return a > b ? b : a;
}

ll Max(ll a, ll b) {
    return a > b ? a : b;
}

ll Min(ll a, ll b, ll c) {
    return Min(Min(a, b), c);
}

ll Max(ll a, ll b, ll c) {
    return Max(Max(a, b), c);
}

ll dnq(int start, int end, int n) {
    if (n == 1) {
        return histogram[start];
    }
    int mid = (start + end) / 2;
    int cnt = 2;
    ll tempMax = Min(histogram[mid], histogram[mid + 1]);
    ll tempArea = tempMax * cnt;
    
    int left = mid;
    int right = mid + 1;
    
    for (int i = 0; i < n - 2; ++i) {
        if (left == start) right++;
        else if (right == end) left--;
        else {
            if (histogram[left - 1] >= histogram[right + 1]) left--;
            else right++;
        }
        tempMax = Min(tempMax, histogram[left], histogram[right]);
        cnt++;
        tempArea = Max(tempMax * cnt, tempArea);
    }
    
    return Max(dnq(start, mid, mid - start + 1), dnq(mid + 1, end, end - mid), tempArea);
}



int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int height;
    cin >> n;
    while (n) {
        histogram.clear();
        for (int i = 0; i < n; ++i) {
            cin >> height;
            histogram.push_back(height);
        }
        cout << dnq(0, n - 1, n) << "\n";
        cin >> n;
    }
    
    return 0;
}
