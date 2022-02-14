#include <bits/stdc++.h>

#define Task "NOTEL"
#define MOD 1000000007

using namespace std;

const int maxn = 2005;

int n, k;
//vector<vector<int> > dp;
int dp[maxn][maxn], sum[maxn][maxn];

void Solve() {
  cin >> n >> k;
//  dp.resize(k + 1);
//  for(int i = 1; i <= k; ++ i) dp[i].resize(n + 1);
//  suppose x1 >= x2 >= ... >= xk
  for(int i = 1; i <= k; ++ i) {
    if(i == 1) {
      for(int j = 0; j <= n; ++ j) dp[i][j] = sum[i][j] = 1;
    } else {
      for(int j = 0; j <= n; ++ j) {
        for(int x = j; x <= n; ++ x) {
          if(j + x > n) break;
          sum[i][j + x] = (sum[i][j + x] + dp[i - 1][x]) % MOD;
          dp[i][j] = (dp[i][j] + sum[i][j + x]) % MOD;
        }
      }
    }
  }
  cout << sum[k][n];
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  if(fopen(Task".inp", "r")) {
     freopen(Task".inp", "r", stdin);
     freopen(Task".out", "w", stdout);
  }
  Solve();
}

