#include <bits/stdc++.h>

#define Task "COMMANDO"
#define F first
#define S second
#define int long long

using namespace std;

const int maxn = 1000005;

int n, a, b, c, s[maxn];
int st[maxn], top = 0;
int dp[maxn], p[maxn], q[maxn];
double x[maxn];
pair<int, int> line[maxn];
/*
  dp[i] = max(dp[j] + (s[i] - s[j]) ^ 2 * a + (s[i] - s[j]) * b + c)
  dp[j] + (s[i] ^ 2 - 2 * s[i] * s[j] + s[j] ^ 2) * a + (s[i] - s[j]) * b + c
  (dp[j] + s[j] ^ 2 * a - s[j] * b) + (- 2 * a * s[j]) * s[i] + s[i] ^ 2 * a + s[i] * b + c
  -> line = {- 2 * a * s[j], dp[j] + s[j] ^ 2 * a - s[j] * b}
*/

bool Check(int i, int j, int k) {
  if(line[i].F == line[j].F) return 0;
  if(top == 1) return 1;
  double x1 = 1.0 * (line[j].S - line[i].S) / (line[i].F - line[j].F);
  double x2 = 1.0 * (line[k].S - line[i].S) / (line[i].F - line[k].F);
  return (x1 > x2);
}

void Solve() {
  cin >> n >> a >> b >> c;
  for(int i = 1; i <= n; ++ i) {
    int x; cin >> x;
    s[i] = s[i - 1] + x;
  }
  st[++ top] = 0;
  line[0] = {-2 * a * s[0], 0};
  x[top] = -2e9, p[top] = -2 * a * s[0], q[top] = 0;
  for(int i = 1; i <= n; ++ i) {
    int pos = upper_bound(x + 1, x + top + 1, s[i]) - x - 1;
    dp[i] = p[pos] * s[i] + q[pos] + s[i] * s[i] * a + s[i] * b + c;
    line[i] = {-2 * s[i] * a, dp[i] + s[i] * s[i] * a - s[i] * b};
    while(top > 0 && !Check(i, st[top], st[top - 1])) -- top;
    st[++ top] = i;
    if(top == 1) x[top] = -2e9;
    else {
      p[top] = line[i].F, q[top] = line[i].S;
      x[top] = 1.0 * (q[top] - q[top - 1]) / (p[top - 1] - p[top]);
    }
  }
  cout << dp[n] << "\n";
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

