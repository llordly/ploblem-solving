// 1931

#include <stdio.h>
#include <vector>
#include <algorithm>

int N;

std::vector<std::pair<int, int>> con;

bool cmp(std::pair<int, int>a, std::pair<int, int>b){
    if (a.second == b.second) {
        return a.first < b.first;
    }
    else {
        return a.second < b.second;
    }
}

int main(void){
    int a, b;
    scanf("%d", &N);
    
    for (int i = 0; i < N; ++i){
        scanf("%d %d", &a, &b);
        con.push_back(std::make_pair(a, b));
    }
    sort(con.begin(), con.end(), cmp);
    
    int end = con[0].second;
    int ans = 1;
    for (int i = 1; i < N; ++i){
        if (con[i].first >= end){
            ans++;
            end = con[i].second;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
