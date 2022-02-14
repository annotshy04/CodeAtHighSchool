#include<bits/stdc++.h>

#define Task "COVERCIR"
#define int long long

using namespace std;

const int maxn = 200005;

long long n, u, v, d;

namespace full {

  long long Calc(long long x) {
    if(x < 0 || x >= n) return 1e18;
    return max(x, min(2 * (d - 1) + n - d - x - 1, 2 * (n - d - x - 1) + d - 1));
  }

  void Solve() {
    d = min(v - u, n - v + u);
    if(d == 0) {
      cout << n / 2 << "\n";
      return;
    }
    if(d == 1) {
      cout << (n + 1) / 2 - 1 << "\n";
      return;
    }
    long long x1, x2, x3;
    x1 = (d + n - 3) / 2;
    x2 = (2 * n - d - 3)/ 3;
    x3 = (n - 2 * d);
    long long res = min({Calc(x1), Calc(x2), Calc(x3)});
    res = min({res, Calc(x1 + 1), Calc(x2 + 1), Calc(x3 + 1)});
    cout << res << "\n";
  }
}

void Solve(int Test) {
  cin >> n >> u >> v;
  if(u > v) swap(u, v);
  full::Solve();
}

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  if(fopen(Task".inp", "r")) {
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
  }
  int test = 1;
  cin >> test;
  for(int i = 1; i <= test; ++ i) {
    Solve(i);
  }
}
