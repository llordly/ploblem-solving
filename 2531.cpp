/*
2531 회전초밥
투 포인터(슬라이딩 윈도우)
*/

#include <iostream>


using namespace std;


int N, d, k, c;

int sushi[3001];
int dish[30001];

int Max(int a, int b) {return a > b ? a : b;}



int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> d >> k >> c;


    for (int i = 0; i < N; ++i) {
        cin >> dish[i];
    }

    int ans = 0;
    int temp = 0;


    int start = 0;


    for (int i = 0; i < N; ++i) {
        sushi[dish[i]]++;
        if (sushi[dish[i]] == 1) temp++;

        if (i >= k - 1) {
            if (sushi[c]) {
                ans = Max(ans, temp);
            } else {
                ans = Max(ans, temp + 1);
            }

            sushi[dish[start]]--;
            if (!sushi[dish[start++]]) temp--;
        }
    }

    for (int i = 0; i < k - 1; ++i) {
        sushi[dish[i]]++;
        if (sushi[dish[i]] == 1) temp++;

        if (sushi[c]) {
            ans = Max(ans, temp);
        } else {
            ans = Max(ans, temp + 1);
        }

        sushi[dish[start]]--;
        if (!sushi[dish[start++]]) temp--;
    }

    cout << ans;


    return 0;
}