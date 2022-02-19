// annotshy

#include <bits/stdc++.h>

#define Task "CF"
#define F first
#define S second

using namespace std;

const int maxn = 100005;

int n, k;
int a[maxn], s[maxn];

bool maximize(long long &x, long long y) {
	if(x < y) {x = y; return 1;}
	return 0;
}

//namespace BF {
//
//	long long dp[205][205];
//	int tr[205][205];
//
//	void Solve() {
//		memset(dp, -0x3f, sizeof dp);
//		dp[0][0] = 0;
//		for(int i = 1; i <= n; ++ i) {
//			for(int j = 0; j < k; ++ j) if(dp[i - 1][j] >= 0) {
//				for(int x = i; x < n; ++ x) {
//					if(maximize(dp[x][j + 1], dp[i - 1][j] + (s[n] - s[x]) * (s[x] - s[i - 1]))) {
//						tr[x][j + 1] = i - 1;
//					}
//				}
//			}
//		}
//		long long ans = -1;
//		int pos = 0;
//		for(int i = 1; i <= n; ++ i) {
//     if(maximize(ans, dp[i][k])) pos = i;
//		}
//		vector<int> id;
//		while(pos) {
//			id.push_back(pos);
//			pos = tr[pos][k];
//			k --;
//		}
//		cout << ans << "\n";
//		reverse(id.begin(), id.end());
//		for(auto x : id) cout << x << " ";
//	}
//} // BF

namespace Full {

  pair<int, long long> line[maxn];
  long long p[maxn], q[maxn];
  double x[maxn];
  long long dp[2][maxn];
  int st[maxn], top = 0, tr[205][maxn];

  bool Check(int i, int j, int k) {
    if(line[i].F == line[j].F || line[i].F == line[k].F) return 0;
    double x1 = 1.0 * (line[i].S - line[j].S) / (line[j].F - line[i].F);
    double x2 = 1.0 * (line[i].S - line[k].S) / (line[k].F - line[i].F);
    return (x1 > x2);
  }

  void Update(int i) {
    while(top > 1 && !Check(i, st[top], st[top - 1])) -- top;
    st[++ top] = i;
    p[top] = line[i].F, q[top] = line[i].S;
    if(top == 1) x[top] = -2e9;
    else {
//      assert(p[top - 1] != p[top]);
      x[top] = 1.0 * (q[top] - q[top - 1]) / (p[top - 1] - p[top]);
    }

  }

  void Solve() {
    for(int i = 0; i < 2; ++ i) {
      for(int j = 0; j < n; ++ j) dp[i][j] = -2e9;
    }
    dp[0][0] = 0;
    for(int t = 1; t <= k; ++ t) {
      top = 0;
      for(int i = 0; i < n; ++ i) {
        if(dp[(t - 1) & 1][i] >= 0) line[i] = {s[i], dp[(t - 1) & 1][i]};
      }
      for(int i = 1; i < n; ++ i) {
        if(dp[(t - 1) & 1][i - 1] >= 0)
          Update(i - 1);
        int pos = upper_bound(x + 1, x + top + 1, s[i] - s[n]) - x - 1;
        if(pos <= 0) continue;
        int id = st[pos];
        dp[t & 1][i] = dp[(t - 1) & 1][id] + 1ll * (s[i] - s[id]) * (s[n] - s[i]);
        tr[t][i] = id;
      }
      for(int i = 0; i < n; ++ i) {
        if(dp[(t - 1) & 1][i] >= 0) dp[(t - 1) & 1][i] = -2e9;
      }
    }
    long long ans = -1;
		int pos = 0;
		for(int i = 1; i <= n; ++ i) {
     if(maximize(ans, dp[k & 1][i])) pos = i;
		}
		vector<int> id;
		while(pos) {
			id.push_back(pos);
			pos = tr[k][pos];
			k --;
		}
		cout << ans << "\n";
		reverse(id.begin(), id.end());
		for(auto x : id) cout << x << " ";
  }
}

void Solve(int Test) {
  cin >> n >> k;
  for(int i = 1; i <= n; ++ i) cin >> a[i], s[i] = s[i - 1] + a[i];
//  if(n <= 200 && k <= 200) {
//  	BF::Solve();
//  	return;
//  }
  Full::Solve();
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