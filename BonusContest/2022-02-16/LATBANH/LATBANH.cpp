#include<bits/stdc++.h>

#define Task "LATBANH"
#define F first
#define S second

using namespace std;

const int maxn = 1000005;

int n, k;
pair<int, int> a[105];
bool can[maxn];

namespace Sub1 {

  int cur[2], ans = 2e9;

  void Calc(int mask) {
    cur[0] = cur[1] = 0;
    int t = 0;
    for(int i = 0; i < 2 * n; ++ i) {
      if(mask >> (i - 1) & 1) {
        if(!can[i]) return;
        t ^= 1;
      }
      cur[t] ++;
    }
    if(cur[0] != n || cur[1] != n) return;
    ans = min(ans, __builtin_popcount(mask));
  }

  void Solve() {
    for(int mask = 0; mask < (1 << (n * 2)); ++ mask) {
      Calc(mask);
    }
    if(ans == 2e9) ans = -1;
    cout << ans << "\n";
  }
}

namespace Sub3 {
  int dp[2005][2005];

  void Solve() {
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int i = 1; i <= 2 * n; ++ i) {
      for(int j = 0; j <= min(i, n); ++ j) {
        if(j - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        if(can[i] && i - j - 1 <= n && i - j - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][i - j - 1] + 1);
      }
    }
    if(dp[2 * n][n] > 2 * n) dp[2 * n][n] = -1;
    cout << dp[2 * n][n] << "\n";
  }

}

void Solve(int Test) {
  cin >> n >> k;
  for(int i = 1; i <= k; ++ i) {
    cin >> a[i].F >> a[i].S;
    for(int j = a[i].F; j <= a[i].S; ++ j) can[j] = 1;
  }
  if(n <= 10) {
    Sub1::Solve();
    return;
  }
  if(can[n]) {
    cout << 1 << "\n";
    return;
  }
  for(int i = 0; i < n; ++ i) {
    if(can[i] && can[i + n]) {
      cout << 2 << "\n";
      return;
    }
  }
  if(n <= 1000) {
    Sub3::Solve();
    return;
  }
  cout << -1 << "\n";
}

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
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
