// 1517
#include <iostream>
#include <vector>


using namespace std;

long long ans = 0;
int list[500001], sorted[500001];

void merge(int start, int mid, int end) {
    int left = start;
    int right = mid + 1;
    int p = start;
    int cnt = 0;
    
    while (left <= mid && right <= end) {
        if (list[left] <= list[right]) {
            sorted[p++] = list[left++];
            ans += cnt;
        } else {
            sorted[p++] = list[right++];
            cnt++;
        }
    }
    
    if (left > mid) {
        for (int i = right; i <= end; ++i) {
            sorted[p++] = list[i];
        }
    } else {
        for (int i = left; i <= mid; ++i) {
            sorted[p++] = list[i];
            ans += cnt;
        }
    }
    for (int i = start; i <= end; ++i) {
        list[i] = sorted[i];
    }
}

void merge_sort(int start, int end) {
    int mid;
    if (start < end) {
        mid = (start + end) / 2;
        merge_sort(start, mid);
        merge_sort(mid + 1, end);
        merge(start, mid, end);
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        list[i] = num;
    }
    merge_sort(0, n - 1);
    cout << ans;
   
    
    return 0;
}


