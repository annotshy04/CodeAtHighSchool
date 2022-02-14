// annotshy

/*
  Problem: Suffix Array Edu-Codeforces
*/

#include <bits/stdc++.h>
using namespace std;

const int base = 100003;
const int maxn = 400005;

int n, ra[maxn], rb[maxn], sa[maxn], G, pos[maxn], lcp[maxn];
string s;

bool comp(int x,int y){
    if(ra[x] != ra[y]) return ra[x] < ra[y];
    return ra[x + G] < ra[y + G];
}

void SuffixArray(){
    n = s.length();
    s = " " + s;
    for(int i = 1; i <= n; ++i){
        sa[i] = i;
        ra[i] = s[i];
    }
    for(G = 1; G <= n; G *= 2){
        sort(sa + 1, sa + n + 1, comp);
        for(int i = 1; i <= n; ++ i) {
            rb[sa[i]] = rb[sa[i - 1]] + comp(sa[i - 1], sa[i]);
        }
        for(int i = 1; i <= n; ++ i) ra[i] = rb[i];
        if(ra[sa[n]] == n) break;
    }
    cout << n << " ";
    for(int i = 1; i <= n; ++ i) cout << sa[i] - 1 << " ";
    cout << "\n";
}

void BuildLCP(){
    int k = 0;
    for(int i = 1; i <= n; ++ i) pos[sa[i]] = i;
    for(int i = 1; i <= n; ++ i) if(pos[i] != n) {
        int j = sa[pos[i] + 1];
        while(s[i + k] == s[j + k]) ++ k;
        lcp[pos[i]] = k;
        if(k > 0) -- k;
    }
    cout << 0 << " ";
    for(int i = 1; i < n; ++ i) cout << lcp[i] << " ";
}

void Solve(){
    cin >> s;
    n = s.length();
    SuffixArray();
    BuildLCP();
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int test = 1;
//    cin >> test;
    while(test --){
        Solve();
    }
}
