/*
1062 가르침
구현, 백트래킹
*/

#include <iostream>
#include <string>
#include <vector>


using namespace std;

int n, k;


char words[50][26];
int ans;

int Max(int a, int b) {return a > b ? a : b;}


void backtracking(vector<char> dic, int cnt, int idx) {
    if (cnt == k - 5) {
        int temp = 0;
        for (int i = 0; i < n; ++i) {
            bool check = true;
            for (int j = 0; j < 26; ++j) {
                if (words[i][j] && !dic[j]) {
                    check = false;
                    break;
                }
            }
            if (check) temp++;
        }
        ans = Max(ans, temp);
        return;
    }

    //26개의 알파벳중에서 k개를 선택하는 조합을 구한다.
    for (int i = idx; i < 26; ++i) {
        if (dic[i]) {
            continue;
        } else {
            vector<char> new_dic = dic;
            new_dic[i] = 1;
            backtracking(new_dic, cnt + 1, i + 1);
        }
    }
}




int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    string word;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> word;
        for (int j = 4; j < word.size() - 4; ++j) {
            words[i][word[j] - 'a'] = 1;
        }
    }


    vector<char> dic(26, 0);
    dic[0] = 1;
    dic['c'-'a'] = 1;
    dic['t'-'a'] = 1;
    dic['i'-'a'] = 1;
    dic['n'-'a'] = 1;

    backtracking(dic, 0, 0);
    

    cout << ans;


    return 0;
}