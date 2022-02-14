// annotshy

#include <bits/stdc++.h>

#define Task "CF"

using namespace std;

const int maxn = 200005;

int n, k;
int a[maxn];
long long s[maxn];

bool maximize(long long &x, long long y) {
	if(x < y) {x = y; return 1;}
	return 0;
}

namespace BF {

	long long dp[205][205];
	int tr[205][205];

	void Solve() {
		memset(dp, -0x3f, sizeof dp);
		dp[0][0] = 0;
		for(int i = 1; i <= n; ++ i) {
			for(int j = 0; j < k; ++ j) if(dp[i - 1][j] >= 0) {
				for(int x = i; x < n; ++ x) {
					if(maximize(dp[x][j + 1], dp[i - 1][j] + (s[n] - s[x]) * (s[x] - s[i - 1]))) {
						tr[x][j + 1] = i - 1;
					}
				}
			}
		}
		long long ans = -1;
		int pos = 0;
		for(int i = 1; i <= n; ++ i) {
     if(maximize(ans, dp[i][k])) pos = i;
		}
		vector<int> id;
		while(pos) {
			id.push_back(pos);
			pos = tr[pos][k];
			k --;
		}
		cout << ans << "\n";
		reverse(id.begin(), id.end());
		for(auto x : id) cout << x << " ";
	}
} // BF

void Solve(int Test) {
  cin >> n >> k;
  for(int i = 1; i <= n; ++ i) cin >> a[i], s[i] = s[i - 1] + a[i];
  if(n <= 200 && k <= 200) {
  	BF::Solve();
  	return;
  }
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
