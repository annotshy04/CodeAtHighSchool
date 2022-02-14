/*
  Problem: FOUNDSTRING - Dai Ca Di Hoc
*/

#include <bits/stdc++.h>
#define Task "FOUNSTRING"
using namespace std;

const int base = 100003;
const long long MM = 1ll*MOD*MOD;
const int maxc = 2e9;

int n, m, Next[1000001][26], cnt = 1;
string s, x;
bool leaf[1000001];

void Add(string s) {
    int x = 1;
    for(char &c : s) {
        int i = c - 'a';
        if(Next[x][i] == 0) Next[x][i] = ++cnt;
        x = Next[x][i];
    }
    leaf[x] = 1;
}
bool found(string s) {
    int x = 1;
    for(char &c : s) {
        int i = c - 'a';
        if(Next[x][i] == 0) return 0;
        x = Next[x][i];
    }
    return leaf[x];
}
int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; ++ i) {
        cin >> s;
        Add(s);
    }
    cin >> m;
    while(m --) {
        cin >> x;
        if(found(x)) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}
