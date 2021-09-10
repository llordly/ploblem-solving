// 11399
#include <stdio.h>
#include <vector>
#include <algorithm>

int n;

std::vector<int> people;

int main(void){
    scanf("%d", &n);
    int t;
    for (int i = 0; i < n; ++i){
        scanf("%d", &t);
        people.push_back(t);
    }
    sort(people.begin(), people.end());
    
    int ans = 0;
    for (int i = 0; i < n; ++i){
        int sum = 0;
        for (int j = 0; j <= i; ++j){
            sum += people[j];
        }
        ans += sum;
    }
    printf("%d\n", ans);
    
    return 0;
}
