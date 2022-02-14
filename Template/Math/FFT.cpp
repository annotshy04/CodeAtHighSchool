// annotshy

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define Task "POST2"
#define pb push_back
#define MOD 998244353
#define F first
#define S second

#define int long long

//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
using namespace __gnu_pbds;
using namespace std;
using cd = complex<double>;

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int maxn = 400005;
const double PI = acos(-1);

int n;

void fft(vector<cd> & a, bool invert) {
  int n = a.size();
  if(n == 1)
    return;
  vector<cd> a0(n / 2), a1(n / 2);
  for(int i = 0; 2 * i < n; ++ i) {
    a0[i] = a[2 * i];
    a1[i] = a[2 * i + 1];
  }
  fft(a0, invert);
  fft(a1, invert);
  double ang = 2 * PI / n * (invert ? -1 : 1);
  cd w(1), wn(cos(ang), sin(ang));
  for(int i = 0; 2 * i < n; ++ i) {
    a[i] = a0[i] + w * a1[i];
    a[i + n / 2] = a0[i] - w * a1[i];
    if(invert) {
      a[i] /= 2;
      a[i + n / 2] /= 2;
    }
    w *= wn;
  }
}

vector<int> Mul(vector<int> const& a, vector<int> const& b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int sz = 1;
  while (sz < (int) a.size() + (int) b.size())
    sz <<= 1;
  fa.resize(sz);
  fb.resize(sz);
  fft(fa, false);
  fft(fb, false);
  for(int i = 0; i < sz; i++)
    fa[i] *= fb[i];
  fft(fa, true);
  vector<int> result(sz);
  for(int i = 0; i < sz; i++)
    result[i] = round(fa[i].real());
  return result;
}

void Solve(int Test) {
  cin >> n;
  vector<int> a(100001), b(100001);
  for(int i = 1; i <= n; ++ i) {
    int x; cin >> x;
    a[x + 50000] ++;
  }
  for(int i = 1; i <= n; ++ i) {
    int x; cin >> x;
    b[x + 50000] ++;
  }
  vector<int> c = Mul(a, b);
  long long res = 0;
  for(int i = 1; i <= n; ++ i) {
    int x; cin >> x;
    res += c[x + 100000];
  }
  cout << res << "\n";
}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  if(fopen(Task".inp", "r")) {
     freopen(Task".inp", "r", stdin);
     freopen(Task".out", "w", stdout);
  }
  int test = 1;
//  cin >> test;
  for(int i = 1; i <= test; ++ i) {
    Solve(i);
  }
}
