#include<bits/stdc++.h>

#define Task "ADDITION"
#define int long long

using namespace std;

const int maxn = 200005;

int a, b, c, n;

namespace Sub1 {

  void Solve() {
    int res = 0;
    for(int x = 0; 1ll * x * a <= n; ++ x) {
      for(int y = 0; 1ll * y * b + x * a <= n; ++ y) {
        if((n - (x * a + y * b)) % c == 0) {
          ++ res;
        }
      }
    }
    cout << res << "\n";
  }
}

void Solve(int Test) {
  cin >> a >> b >> c >> n;
  if(n <= 1000000) {
    Sub1::Solve();
    return;
  }
  int res = 0;
  int X, Y;
  int d = __gcd(a, b);
  int M = a, N = b;
  int xm = 1;
  int xn = 0;
  while(N) {
    int q = M / N;
    int r = M - q * N;
    int xr = xm - q * xn;
    M = N, xm = xn;
    N = r, xn = xr;
  }
  int p = b / d;
  int q = a / d;
  for(int z = 0; 1ll * z * c <= n; ++ z) {
    int C = n - c * z;
    if(C % d) continue;
    X = xm * (C / d);
    Y = ((d - a * xm) / b) * (C / d);
    double lk1 = - 1.0 * X / p;
    int lk = ceil(lk1);
    double rk1 = 1.0 * Y / q;
    int rk = floor(rk1);
    res += (rk - lk + 1);
  }
  cout << res << "\n";
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
