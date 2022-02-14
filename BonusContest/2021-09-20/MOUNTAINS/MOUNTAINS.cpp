#include <bits/stdc++.h>

#define Task "MOUNTAINS"
#define int long long
#define pb push_back

using namespace std;

const int maxn = 300005;

int n, h[maxn], L[maxn], R[maxn];

struct BIT {
  int T[maxn];

  void Update(int x) {
    for(; x < maxn; x += x & - x) T[x] ++;
  }

  int Get(int x) {
    int res = 0;
    for(; x; x -= x & - x) res += T[x];
    return res;
  }
} Tl, Tr;

void Solve() {
  cin >> n;
  vector<int> v;
  for(int i = 1; i <= n; ++ i) cin >> h[i], v.pb(h[i]);
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  for(int i = 1; i <= n; ++ i) {
    h[i] = lower_bound(v.begin(), v.end(), h[i]) - v.begin() + 1;
  }
  for(int i = 1; i <= n; ++ i) {
    L[i] = Tl.Get(h[i] - 1);
    Tl.Update(h[i]);
  }
  for(int i = n; i >= 1; -- i) {
    R[i] = Tr.Get(h[i] - 1);
    Tr.Update(h[i]);
  }
  int res = 0;
  for(int i = 1; i <= n; ++ i) {
    res += L[i] * R[i];
  }
  cout << res;
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

