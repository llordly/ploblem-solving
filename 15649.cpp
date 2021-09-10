#15649

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
            if(!visited[i]){
                permutation[cnt] = i;
                visited[i] = true;
                backtraking(cnt + 1);
                visited[i] = false;
            }
        }
    }
}

int main(void){
    scanf("%d %d", &n, &m);
    backtraking(0);
    return 0;
}
