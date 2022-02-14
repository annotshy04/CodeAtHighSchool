// annotshy

#include <bits/stdc++.h>

#define Task "CF"
#define sz(x) (int) x.size()
#define MOD 1000000007

using namespace std;

const int maxn = 105;

int n;
int a[maxn][maxn], dp[maxn][maxn];

void Solve(int Test) {
  cin >> n;
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= i; ++ j) cin >> a[i][j];
  }
  dp[1][1] = a[1][1];
  for(int i = 1; i < n; ++ i) {
    for(int j = 1; j <= i; ++ j) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i + 1][j + 1]);
    }
  }
  cout << *max_element(dp[n] + 1, dp[n] + n + 1) << "\n";
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
