#15651

#include <stdio.h>

int n, m;
int permutation[8];
bool visited[8];

void backtraking(int cnt){
    if (cnt == m){
        for (int i = 0; i < m; ++i){
            printf("%d ", permutation[i]);
        }
        printf("\n");
    }
    else{
        for (int i = 1;  i <= n; ++i){
                permutation[cnt] = i;
                backtraking(cnt + 1);
        }
    }
}

int main(void){
    scanf("%d %d", &n, &m);
    backtraking(0);
    return 0;
}
