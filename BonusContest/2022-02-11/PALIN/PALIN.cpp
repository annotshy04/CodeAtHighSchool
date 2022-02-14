#include<bits/stdc++.h>

#define Task "PALIN"
#define MOD 1000000007

using namespace std;

const int maxn = 10005;

string s, t;
int k, l[15], n;
long long P[maxn], H[3][maxn], base = 119;

long long Get(int t, int l, int r) {
  if(t == 1) return (H[t][r] - H[t][l - 1] * P[r - l + 1] % MOD + MOD) % MOD;
  return (H[t][l] - H[t][r + 1] * P[r - l + 1] % MOD + MOD) % MOD;
}

bool Check(int l, int r) {
  if(l > r) return 1;
  long long cur1 = Get(1, l, r);
  long long cur2 = Get(2, l, r);
  return cur1 == cur2;
}

namespace Full {

  int dp[maxn][(1 << 13) + 5], palin[maxn][15];

  void Solve() {
    for(int j = 0; j < (1 << k); ++ j) {
      for(int i = 0; i <= n; ++ i) {
        dp[i][j] = 2e9;
      }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++ i) {
      for(int x = 1; x <= k; ++ x) {
        if(i >= l[x]) palin[i][x] = Check(i - l[x] + 1, i);
      }
    }
    for(int i = 1; i <= n; ++ i) {
      for(int premask = 0; premask < (1 << k); ++ premask) {
        for(int x = 1; x <= k; ++ x) {
          if(premask >> (x - 1) & 1) continue;
          if(i >= l[x]) {
            int mask = premask ^ (1 << (x - 1));
            if(palin[i][x]) {
              dp[i][mask] = min(dp[i][mask], dp[i - l[x]][premask] + l[x]);
            }
          }
        }
        if(premask) dp[i][premask] = min(dp[i][premask], dp[i - 1][premask] + 1);
        else dp[i][premask] = dp[i - 1][premask];
      }
    }
    int ans = 2e9;
    for(int i = 1; i <= n; ++ i) {
      ans = min(ans, dp[i][(1 << k) - 1]);
    }
    if(ans == 2e9) ans = -1;
    cout << ans << "\n";
  }
}

void Solve(int Test) {
  cin >> s;
  n = s.size();
  s = " " + s;
  P[0] = 1;
  for(int i = 1; i <= n; ++ i) P[i] = P[i - 1] * base % MOD;
  for(int i = 1; i <= n; ++ i) {
    H[1][i] = (H[1][i - 1] * base % MOD + s[i]) % MOD;
  }
  for(int i = n; i >= 1; -- i) {
    H[2][i] = (H[2][i + 1] * base % MOD + s[i]) % MOD;
  }
  cin >> k;
  for(int i = 1; i <= k; ++ i) cin >> l[i];
  Full::Solve();

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
