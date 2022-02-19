#include<bits/stdc++.h>

#define Task "BURGER"
#define MOD 1000000007

using namespace std;

const int maxn = 100005;

int n, k;
int a[maxn], Xor[maxn];
int l[maxn], r[maxn];

bool In(int x, int l, int r) {
  return (l <= x && x <= r);
}

void Add(int &x, int y) {
  x += y;
  if(x >= MOD) x -= MOD;
}

namespace Sub1 {

  int Calc(int pos, int num) {
    if(num == k) {
      if(pos > n) return 0;
      return In(Xor[n] ^ Xor[pos - 1], l[k], r[k]);
    }
    int res = 0;
    for(int i = pos; i <= n; ++ i) {
      if(In(Xor[i] ^ Xor[pos - 1], l[num], r[num])) {
        Add(res, Calc(i + 1, num + 1));
      }
    }
    return res;
  }

  void solve() {
    cout << Calc(1, 1) << "\n";
  }
}

namespace Sub2 {

  int dp[105][505];

  void solve() {
    dp[0][0] = 1;
    for(int i = 1; i <= k; ++ i) {
      for(int j = 1; j <= n; ++ j) {
        for(int x = 0; x < j; ++ x) {
          if(In(Xor[j] ^ Xor[x], l[i], r[i])) Add(dp[i][j], dp[i - 1][x]);
        }
      }
    }
    cout << dp[k][n] << "\n";
  }
}

namespace Full {

  int cnt = 1;
  int nex[maxn * 35][2], val[maxn * 35];
  int dp[320][maxn];

  void Update(int x, int delta) {
    int node = 1;
    for(int i = 30; i >= 0; -- i) {
      int c = (x >> i & 1);
      if(!nex[node][c]) nex[node][c] = ++ cnt;
      node = nex[node][c];
      Add(val[node], delta);
    }
  }

  int Get(int x, int y) {
    int res = 0;
    int node = 1;
    for(int i = 30; i >= 0; -- i) {
      int bit_x = (x >> i & 1);
      int bit_y = (y >> i & 1);
      if(!bit_y) {
        Add(res, val[nex[node][bit_x ^ 1]]);
        node = nex[node][bit_x];
      } else {
        node = nex[node][bit_x ^ 1];
      }
      if(!node) return res;
    }
    Add(res, val[node]);
    return res;

  }

  void solve() {
    dp[0][0] = 1;
    for(int i = 1; i <= k; ++ i) {
      for(int x = 0; x <= cnt; ++ x) nex[x][0] = nex[x][1] = val[x] = 0;
      cnt = 1;
      for(int j = 1; j <= n; ++ j) {
        Update(Xor[j - 1], dp[i - 1][j - 1]);
        dp[i][j] = (Get(Xor[j], l[i]) - Get(Xor[j], r[i] + 1) + MOD) % MOD;
      }
    }
    cout << dp[k][n] << "\n";
  }
}

void Solve(int Test) {
  cin >> n >> k;
  for(int i = 1; i <= n; ++ i) {
    cin >> a[i];
    Xor[i] = Xor[i - 1] ^ a[i];
  }
  for(int i = 1; i <= k; ++ i) cin >> l[i] >> r[i];
//  if(n <= 100 && k <= 4)
//    Sub1::solve();
//  else if(n <= 500 && k <= 100)
//    Sub2::solve();
//  else
    Full::solve();
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
