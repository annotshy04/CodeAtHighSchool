// annotshy

#include <bits/stdc++.h>

#define Task "CF"

using namespace std;

const int maxn = 100005;

int n, a[maxn], b[maxn];
int cntA[maxn * 2], cntB[maxn * 2], ok[2][maxn * 2];
int numGroup = 0, ingroupA[maxn], ingroupB[maxn], szA[maxn * 2], szB[maxn * 2];

/*
  a bit is avaiable if numbit 1 in a = numbit0 in b in each group, vice versa
*/
bool Check(int bit) {
  for(int i = 1; i <= numGroup; ++ i) cntA[i] = cntB[i] = 0;
  for(int i = 1; i <= n; ++ i) {
    if(a[i] >> bit & 1) cntA[ingroupA[i]] ++;
    if(b[i] >> bit & 1) cntB[ingroupB[i]] ++;
  }
  for(int i = 1; i <= numGroup; ++ i) {
    if(szA[i] != szB[i]) return 0;
    if(cntA[i] != szB[i] - cntB[i]) return 0;
    if(szA[i] - cntA[i] != cntB[i]) return 0;
  }
  for(int i = 1; i <= numGroup; ++ i) szA[i] = szB[i] = ok[0][i] = ok[1][i] = 0;
  int newcnt = 0;
  for(int i = 1; i <= n; ++ i) {
    if(a[i] >> bit & 1) {
      int x = ingroupA[i];
      if(!ok[0][x]) ok[0][x] = ++ newcnt;
      ingroupA[i] = ok[0][x];
    } else {
      int x = ingroupA[i];
      if(!ok[1][x]) ok[1][x] = ++ newcnt;
      ingroupA[i] = ok[1][x];
    }
    if(!(b[i] >> bit & 1)) {
      int x = ingroupB[i];
      if(!ok[0][x]) ok[0][x] = ++ newcnt;
      ingroupB[i] = ok[0][x];
    } else {
      int x = ingroupB[i];
      if(!ok[1][x]) ok[1][x] = ++ newcnt;
      ingroupB[i] = ok[1][x];
    }
  }
  numGroup = newcnt;
  for(int i = 1; i <= n; ++ i) {
    szA[ingroupA[i]] ++;
    szB[ingroupB[i]] ++;
  }
  return 1;
}

void Solve(int Test) {
  cin >> n;
  for(int i = 1; i <= n; ++ i) cin >> a[i];
  for(int j = 1; j <= n; ++ j) cin >> b[j];
  int res = 0;
  numGroup = 1;
  for(int i = 1; i <= n; ++ i) {
    ingroupA[i] = numGroup;
    ingroupB[i] = numGroup;
    szA[ingroupA[i]] ++;
    szB[ingroupB[i]] ++;
  }
  for(int bit = 30; bit >= 0; -- bit) {
    if(Check(bit)) res += (1 << bit);
  }
  for(int i = 1; i <= numGroup; ++ i) cntA[i] = cntB[i] = szA[i] = szB[i] = 0;
  cout << res << "\n";
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  if(fopen(Task".inp", "r")) {
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
  }
  int test = 1;
  cin >> test;
  for(int i = 1; i <= test; ++ i) {
    Solve(i);
  }
}

/*no pain no gain*/
