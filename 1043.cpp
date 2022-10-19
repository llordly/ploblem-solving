// 1043

#include <iostream>
#include <vector>

using namespace std;

int parent[51];
int truemen[51];
vector<vector<int>> party;
int n;

void init() {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
}

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y) {
        if (x < y) parent[y] = x;
        else parent[x] = y;
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, truePeople, num, partyPeople, member;
    cin >> n >> m >> truePeople;
    init();
    int bef;
    int ans = 0;
    for (int i = 0; i < truePeople; ++i) {
        cin >> num;
        truemen[i] = num;
        if (i > 0) Union(num, bef);
        bef = num;
    }
    
    party.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> partyPeople;
        int before;
        for (int j = 0; j < partyPeople; ++j) {
            cin >> member;
            party[i].push_back(member);
            if (j > 0) Union(member, before);
            before = member;
        }
    }
    
    if (truePeople == 0) cout << m;
    else {
        int test = truemen[0];
        for (int i = 0; i < m; ++i) {
            bool check = true;
            for (int x : party[i]) {
                int a = Find(x);
                int b = Find(test);
                if (a == b) {
                    check = false;
                    break;
                }
            }
            if (check) ans++;
        }
        cout << ans;
    }

    return 0;
}
