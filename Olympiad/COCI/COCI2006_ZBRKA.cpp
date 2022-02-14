// annotshy

#include <bits/stdc++.h>

#define Task "CF"
#define MOD 1000000007

using namespace std;

const int maxn = 1005;

int n, C;
int dp[maxn][10005];

void Add(int &x, int y) {
	x += y;
	if(x >= MOD) x -= MOD;
}

void Sub(int &x, int y) {
	x -= y;
	if(x < 0) x += MOD;
}

void Solve(int Test) {
  cin >> n >> C;
  dp[0][0] = 1;
  for(int i = 1; i <= n; ++ i) {
  	dp[i][0] = 1;
  	for(int j = 1; j <= C; ++ j) {
  		Add(dp[i][j], dp[i][j - 1]);
  		Add(dp[i][j], dp[i - 1][j]);
  		if(j - i >= 0) Sub(dp[i][j], dp[i - 1][j - i]);
  	}
  }
  cout << dp[n][C] << "\n";
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
