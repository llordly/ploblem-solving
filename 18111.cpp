//18111
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <limits.h>
#include <stdio.h>
#include <set>

using namespace std;

int maxHeight = 0;
int minTime = INT_MAX;
int n, m, b, num;
int minH = INT_MAX;
int maxH = -1;

vector<int> arr;


int mineCraft(int height, int b) {
    int time = 0;
    int block = b;
    for (int i = 0; i < n * m; ++i) {
        int diff = height - arr[i];
        if (diff > 0) {
            if (diff <= block) {
                block -= diff;
                time += diff;
            } else {
                return -1;
            }
        } else if (diff < 0) {
            block -= diff;
            time -= (2 * diff);
        }
    }
    return time;
}

int main(void) {
    cin >> n >> m >> b;
    for (int i = 0; i < n * m; ++i) {
        scanf("%d", &num);
        arr.push_back(num);
        if (num > maxH) {
            maxH = num;
        }
        if (num < minH) {
            minH = num;
        }
    }
    
    sort(arr.begin(), arr.end(), greater<>());
    
    for (int i= minH; i <= maxH; ++i) {
        int h = i;
        int time = mineCraft(h, b);
        if (time == -1) { continue; }
        else {
            if (time < minTime) {
                minTime = time;
                maxHeight = h;
            }
            if (time == minTime) {
                if (h > maxHeight) {
                    maxHeight = h;
                }
            }
        }
    }
    
    printf("%d %d", minTime, maxHeight);
    return 0;
}
