#include<bits/stdc++.h>

#define Task "CF"

using namespace std;

const int maxn = 200005;

int n;
int s[maxn], t[maxn];

namespace Sub2 {

	long long dp[2][(1 << 16) + 5][20];

	void Solve() {
		for(int i = 0; i <= 1; ++ i) {
			for(int mask = 0; mask < (1 << n); ++ mask) {
				for(int j = 1; j <= n; ++ j) {
					dp[i][mask][j] = 1e18;
				}
			}
		}
		for(int i = 1; i <= n; ++ i) {
//			if(s[i] == 1)
        dp[1][(1 << (i - 1))][i] = 0;
		}
		for(int i = 2; i <= n; ++ i) {
			for(int mask = 0; mask < (1 << n); ++ mask) {
				for(int j = 1; j <= n; ++ j) if(mask >> (j - 1) & 1) {
					if(dp[(i - 1) & 1][mask][j] == 1e18) continue;
					for(int x = 1; x <= n; ++ x) {
						if(mask >> (x - 1) & 1) continue;
						int nexmask = mask + (1 << (x - 1));
						dp[i & 1][nexmask][x] = min(dp[i & 1][nexmask][x], dp[(i - 1) & 1][mask][j] + max(0, t[j] - s[x]));
					}
					dp[(i - 1) & 1][mask][j] = 1e18;
				}
			}
		}
		long long ans = 1e18;
		for(int i = 1; i <= n; ++ i) {
			ans = min(ans, dp[n & 1][(1 << n) - 1][i]);
		}
		if(ans == 1e18) ans = 0;
		cout << ans << "\n";
	}
}

void Solve(int Test) {
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		cin >> s[i] >> t[i];
	}
	if(n <= 16) {
		Sub2::Solve();
		return;
	}
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
