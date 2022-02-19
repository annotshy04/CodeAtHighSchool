// annotshy

#include <bits/stdc++.h>

#define Task "CF"
#define F first
#define S second

using namespace std;

const int maxn = 100005;

int n, a[maxn];
long long dp[(1 << 20) + 5][25], match[25][25];

int binary_1(int x) {
  int res = 0;
  while(x) {
    res += (x % 2 == 1);
    x /= 2;
  }
  return res;
}

int ternary_1(int x) {
  int res = 0;
  while(x) {
    res += (x % 3 == 1);
    x /= 3;
  }
  return res;
}

bool ok(int x, int y) {
  if(binary_1(x) == binary_1(y)) return 1;
  if(ternary_1(x) == ternary_1(y)) return 1;
  return 0;
}

namespace BF {

  int p[55], res = 0;

  void solve() {
    for(int i = 1; i <= n; ++ i) p[i] = i;
    do {
      int ok = 1;
      for(int i = 1; i < n; ++ i) {
        ok &= match[p[i]][p[i + 1]];
      }
      res += ok;
    } while(next_permutation(p + 1, p + n + 1));
    cout << res << "\n";
  }
}

void Solve(int Test) {
  cin >> n;
  for(int i = 1; i <= n; ++ i) cin >> a[i];
  for(int i = 1; i <= n; ++ i) {
    for(int j = i + 1; j <= n; ++ j) {
      match[i][j] = match[j][i] = ok(a[i], a[j]);
    }
    dp[(1 << (i - 1))][i] = 1;
  }
  if(n <= 4) {
    BF::solve();
    return;
  }
  for(int mask = 0; mask < (1 << n); ++ mask) {
    for(int i = 1; i <= n; ++ i) {
      if(!(mask >> (i - 1) & 1)) continue;
      for(int j = 1; j <= n; ++ j) {
        if(!match[i][j]) continue;
        if(!(mask >> (j - 1) & 1)) continue;
        dp[mask][i] += dp[mask ^ (1 << (i - 1))][j];
      }
    }
  }
  long long res = 0;
  for(int i = 1; i <= n; ++ i) res += dp[(1 << n) - 1][i];
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
  // cin >> test;
  for(int i = 1; i <= test; ++ i) {
    Solve(i);
  }
}

/*no pain no gain*/
