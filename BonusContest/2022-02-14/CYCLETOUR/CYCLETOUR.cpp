#include<bits/stdc++.h>

#define Task "CYCLETOUR"
#define pb push_back
#define F first
#define S second

using namespace std;

const int maxn = 200005;

int n, m;
vector<pair<int, int> > adj[maxn];

namespace Sub1 {

  struct EDGE {
    int u, v, t;
  } ed[25];
  int used[25], in[25], vis[25], res;

  int Calc(int mask) {
    int type1 = 0;
    for(int i = 1; i <= n; ++ i) in[i] = 0;
    for(int i = 1; i <= m; ++ i) {
      if(mask >> (i - 1) & 1) {
        used[i] = 1;
        in[ed[i].u] ++;
        in[ed[i].v] ++;
        type1 += ed[i].t;
      } else used[i] = 0;
      vis[i] = 0;
    }
    if(type1 != 2) return 0;
    int root = 0;
    for(int i = 1; i <= n; ++ i) if(in[i]) {
      if(in[i] != 2) return 0;
      root = i;
    }
    int u = root, numedge = 0;
    while(1) {
      int cur = u;
      if(u == root && numedge != 0) {
        return (numedge == __builtin_popcount(mask));
      }
      for(auto v : adj[u]) {
        if(used[v.S] && !vis[v.S]) {
          vis[v.S] = 1;
          u = v.F;
          numedge ++;
          break;
        }
      }
      if(cur == u) break;
    }
    return 0;
  }

  void Solve() {
    for(int i = 1; i < n; ++ i) {
      int u, v; cin >> u >> v;
      adj[u].pb({v, i});
      adj[v].pb({u, i});
      ed[i] = {u, v, 0};
    }
    for(int i = n; i <= m; ++ i) {
      int u, v; cin >> u >> v;
      adj[u].pb({v, i});
      adj[v].pb({u, i});
      ed[i] = {u, v, 1};
    }
    res = 0;
    for(int mask = 0; mask < (1 << m); ++ mask) {
      res += Calc(mask);
    }
    cout << res << "\n";
  }
}

void Solve(int Test) {
  cin >> n >> m;
//  if(n <= 20 && m <= 20) {
    Sub1::Solve();
//    return;
//  }
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
