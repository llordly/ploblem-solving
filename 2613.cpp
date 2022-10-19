// 2613
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
vector<int> ansGroup;

bool isPossible(int mid) {
    int sum = 0;
    int group = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > mid) return false;
        sum += arr[i];
        if (sum > mid) {
            sum = arr[i];
            group++;
        }
    }
    group++;
    return group <= m;
}

void printAns(int mid) {
    int sum = 0;
    int count = 0;
    int groupCnt = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum > mid) {
            sum = arr[i];
            ansGroup.push_back(count);
            count = 0;
            groupCnt++;
        }
        count++;
        
        if (m - groupCnt == n - i) {
            ansGroup.push_back(count);
            for (int j = 0; j < n - i; ++j)
                ansGroup.push_back(1);
            return;
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;
    
    int left = 0;
    int right = 0;
    int ans = 300000;
    
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        cin >> num;
        arr.push_back(num);
        right += num;
        if (num > left) left = num;
    }
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (isPossible(mid)) {
            right = mid - 1;
            if (mid < ans) ans = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << "\n";
    printAns(left);
    for (int i = 0; i < m; ++i) {
        cout << ansGroup[i] << " ";
    }
    

    return 0;
}
