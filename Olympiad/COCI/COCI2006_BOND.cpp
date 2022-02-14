// annotshy

#include <bits/stdc++.h>

#define Task "CF"

using namespace std;

const int maxn = 25;

int n;
int a[maxn][maxn];
double dp[2][(1 << 20) + 5];

void Solve(int Test) {
  cin >> n;
  for(int i = 1; i <= n; ++ i) {
  	for(int j = 0; j < n; ++ j) cin >> a[i][j];
  }
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++ i) {
		for(int mask = 0; mask < (1 << n); ++ mask) {
			if(dp[(i - 1) & 1][mask] == 0) continue;
			for(int j = 0; j < n; ++ j) {
				if(mask >> j & 1) continue;
				int nexmask = mask | (1 << j);
				dp[i & 1][nexmask] = max(dp[i & 1][nexmask], dp[(i - 1) & 1][mask] * a[i][j] / 100);
			}
			dp[(i - 1) & 1][mask] = 0;
		}
	}
	cout << fixed << setprecision(6) << dp[n & 1][(1 << n) - 1] * 100 << "\n";
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