#include <bits/stdc++.h>

#define Task "DSP"
#define pb push_back
#define F first
#define S second

using namespace std;

const int maxn = 100005;

int n, m, q;
struct Edge {
  int u, v, w;
} ed[maxn];
vector<pair<int, int> > adj[maxn];
long long d[maxn];

void DIJK() {
  for(int i = 1; i <= n; ++ i) {
    d[i] = 1e18;
  }
  d[1] = 0;
  priority_queue<pair<int, int> > PQ;
  PQ.push({0, 1});
  while(PQ.size()) {
    int u = PQ.top().S;
    long long l = -PQ.top().S;
    PQ.pop();
    if(l > d[u]) continue;
    for(auto v : adj[u]) {
      if(d[v.F] > d[u] + v.S) {
        d[v.F] = d[u] + v.S;
        PQ.push({- d[v.F], v.F});
      }
    }
  }
}

namespace BF {

  void Solve() {
    while(q --) {
      int t; cin >> t;
      if(t == 1) {
        for(int i = 1; i <= n; ++ i) adj[i].clear();
        for(int i = 1; i <= m; ++ i) {
          adj[ed[i].u].pb({ed[i].v, ed[i].w});
        }
        DIJK();
        int v; cin >> v;
        if(d[v] == 1e18) d[v] = -1;
        cout << d[v] << "\n";
      } else {
        int k; cin >> k;
        while(k --) {
          int x; cin >> x;
          ed[x].w ++;
        }
      }
    }
  }
}

void Solve() {
  cin >> n >> m >> q;
  for(int i = 1; i <= m; ++ i) {
    int u, v, w; cin >> u >> v >> w;
    ed[i] = {u, v, w};
  }
  if(n <= 1000 && m <= 1000 && q <= 100) {
    BF::Solve();
    return;
  }
  int ok = 0;
  while(q --) {
    int t; cin >> t;
    if(t == 1) {
      if(!ok) DIJK();
      int v; cin >> v;
      if(d[v] == 1e18) d[v] = -1;
      cout << d[v] << "\n";
      ok = 1;
    } else {
      int k; cin >> k;
      while(k --) {
        int x; cin >> x;
        ed[x].w ++;
      }
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
  Solve();
}

