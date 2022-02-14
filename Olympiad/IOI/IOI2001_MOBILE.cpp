// annotshy

#include <bits/stdc++.h>

#define Task "CF"
#define sz(x) (int) x.size()
#define MOD 1000000007

using namespace std;

const int maxn = 105;

int n;
struct BIT2D {
  vector<vector<int> > T;
  int n, m;

  void Reset(int _n, int _m) {
    n = _n, m = _m;
    T.resize(n + 1);
    for(int i = 1; i <= n; ++ i) T[i].resize(m + 1);
  }

  void Update(int x, int y, int val) {
    for(; x <= n; x += x & -x) {
      for(int z = y; z <= m; z += z & -z) T[x][z] += val;
    }
  }

  int Get(int x, int y) {
    int res = 0;
    for(; x; x -= x & -x) {
      for(int z = y; z; z -= z & -z) res += T[x][z];
    }
    return res;
  }

  int Query(int x, int y, int u, int v) {
    return Get(u, v) - Get(u, y - 1) - Get(x - 1, v) + Get(x - 1, y - 1);
  }
} myBIT;

void Solve(int Test) {
  while(1) {
    int t; cin >> t;
    if(t == 3) return;
    if(t == 0) {
      cin >> n;
      myBIT.Reset(n, n);
    } else if(t == 1) {
      int x, y, val; cin >> x >> y >> val;
      ++ x, ++ y;
      myBIT.Update(x, y, val);
    } else {
      int x, y, u, v; cin >> x >> y >> u >> v;
      ++ x, ++ y, ++ u, ++ v;
      cout << myBIT.Query(x, y, u, v) << "\n";
    }
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
