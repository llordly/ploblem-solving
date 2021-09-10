#9663

#include <stdio.h>
#include <cstdlib>

int N;
int queen[15];
int result = 0;

bool isPossible(int cnt){
    for (int i = 0; i < cnt; ++i){
        if (queen[i] == queen[cnt])
            return false;
        if (abs(queen[i] - queen[cnt]) == cnt - i)
            return false;
    }
    return true;
}

void backtraking(int cnt){
    if (cnt == N){
        result++;
        return;
    }
    else{
        for (int i = 0; i < N; ++i){
            queen[cnt] = i;
            if (isPossible(cnt))
                backtraking(cnt + 1);
        }
    }
}

int main(void){
    scanf("%d", &N);
    backtraking(0);
    printf("%d\n", result);
    return 0;
}
