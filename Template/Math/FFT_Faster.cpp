// annotshy
#include <bits/stdc++.h>

#define Task ""
#define int long long

using namespace std;
using cd = complex<double>;

const int maxn = 100005;
const double PI = acos(-1);

int n, k;

void FFT(vector<cd> & a, bool invert) {
  int n = a.size();
  for(int i = 1, j = 0; i < n; ++ i) {
    int bit = n >> 1;
    for(; j & bit; bit >>= 1)
      j ^= bit;
    j ^= bit;
    if(i < j)
      swap(a[i], a[j]);
  }
  for(int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for(int i = 0; i < n; i += len) {
      cd w(1);
      for(int j = 0; j < len / 2; ++ j) {
        cd u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }

  if(invert) {
    for(cd &x : a) x /= n;
  }
}

vector<int> Mul(vector<int> &a, vector<int> &b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int sz = 1;
  while(sz < (int) a.size() + (int) b.size()) sz *= 2;
  fa.resize(sz); fb.resize(sz);
  FFT(fa, false);
  FFT(fb, false);
  for(int i = 0; i < sz; ++ i) fa[i] *= fb[i];
  FFT(fa, true);
  vector<int> result(sz);
  for(int i = 0; i < sz; ++ i) {
    result[i] = round(fa[i].real());
    if(result[i]) result[i] = 1;
  }
  return result;
}

void Solve() {
  cin >> n >> k;
  vector<int> a;
  a.resize(1001);
  for(int i = 1; i <= n; ++ i) {
    int x; cin >> x;
    a[x] = 1;
  }
  vector<int> c(1);
  c[0] = 1;
  for(; k; k /= 2, a = Mul(a, a)) {
    if(k & 1) c = Mul(c, a);
  }
  for(int i = 1; i < c.size(); ++ i) {
    if(c[i]) cout << i << " ";
  }
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

