#14888

#include <stdio.h>
#include <cstdlib>


int n;
int number[11];
int oper[4];
int oper2[4];
// [0] = +, [1] = -, [2] = *, [3] = /

int max = -1000000001;
int min = 1000000001;

void cal(int N, int temp){
    if(N == n - 1){
        if(temp < min)
            min = temp;
        if(temp > max)
            max = temp;
        }
    else {
        int a = temp;
        int b = number[N + 1];
        int result = 0;
        for(int i = 0; i < 4; ++i){
            if(oper[i] > 0){
                if(i == 0) result = a + b;
                else if(i == 1) result = a - b;
                else if(i == 2) result = a * b;
                else if(i == 3) result = a / b;
                temp = result;
                oper[i]--;
                cal(N + 1, temp);
                oper[i]++;
            }
        }
    }
}

int main(void){
    int i;
    scanf("%d", &n);
    for(i = 0; i < n; ++i){
        scanf("%d", &number[i]);
    }
    for(i = 0; i < 4; ++i){
        scanf("%d", &oper[i]);
    }
    cal(0, number[0]);
    printf("%d\n%d\n", max, min);
    return 0;
}
