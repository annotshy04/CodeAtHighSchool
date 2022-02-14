#include<bits/stdc++.h>

#define Task "GARDCUT"
#define F first
#define S second
#define pb push_back

using namespace std;

const int maxn = 305;

int m, n, res = 2e9;
char a[maxn][maxn];
int dx[4] = {1, 0, 0};
int dy[4] = {0, 1, -1};
int dp[105][105][10005];

void Calc(int u, int v, int sum) {
  if(dp[u][v][sum]) return;
  dp[u][v][sum] = 1;
  for(int i = 0; i < 3; ++ i) {
    int x = u + dx[i];
    int y = v + dy[i];
    if(x < 0 || y < 0 || x > m || y > n) continue;
    if(i == 0) {
      if(y != 0 && y != n) {
        if(a[x][y] == a[x][y + 1]) continue;
      }
      Calc(x, y, sum + y);
    } else {
      if(dp[x][y][sum]) continue;
      if(x != 0 && x != m) {
        if(a[x][max(v, y)] == a[x + 1][max(v, y)]) continue;
      }
      Calc(x, y, sum);
    }
  }
}

void Solve(int Test) {
  cin >> m >> n;
  for(int i = 1; i <= m; ++ i) {
    for(int j = 1; j <= n; ++ j) cin >> a[i][j];
  }
  Calc(0, 0, 0);
  int ans = 2e9;
  for(int i = 0; i <= n; ++ i) {
    for(int s = 0; s <= m * n; ++ s) {
      if(dp[m][i][s]) {
        ans = min(ans, abs(s - (m * n - s)));
      }
    }
  }
  cout << ans << "\n";
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
