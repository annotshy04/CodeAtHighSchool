#include<bits/stdc++.h>

#define Task "CHIENTRANH"
#define F first
#define S second
#define pb push_back

using namespace std;

const int maxn = 100005;

int n, l, m;
int pos[maxn], in[maxn];
vector<pair<int, int> > adj[maxn];
int d[55][maxn];

bool isbamboo() {
  for(int i = 2; i <= n - 1; ++ i) {
    if(adj[i].size() != 2) return 0;
  }
  if((int) adj[1].size() != 1) return 0;
  if((int) adj[n].size() != 1) return 0;
  return 1;
}

void Sub1() {
  int last = -1;
  vector<pair<int, int> > ans;
  for(int i = 1; i <= n; ++ i) {
    if(!in[i]) continue;
    if(last != -1) ans.pb({last, in[i]});
    last = in[i];
  }
  for(auto &x : ans) {
    if(x.F > x.S) swap(x.F, x.S);
  }
  sort(ans.begin(), ans.end());
  for(auto x : ans) cout << x.F - 1 << " " << x.S - 1 << "\n";
}

namespace Sub2 {

  queue<int> q;
  vector<int> conquer[maxn];
  int dist[maxn];

  void Solve() {
    for(int i = 1; i <= l; ++ i) {
      conquer[pos[i]].pb(i);
      q.push(pos[i]);
    }
    while(q.size()) {
      int u = q.front();
      q.pop();
      if((int) conquer[u].size() > 1) continue;
      for(auto p : adj[u]) {
        int v = p.F;
        if(!dist[v]) {
          dist[v] = dist[u] + 1;
          conquer[v].pb(conquer[u][0]);
          q.push(v);
        } else if(dist[v] == dist[u] + 1) {
          conquer[v].pb(conquer[u][0]);
        }
      }
    }
    vector<pair<int, int> > ans;
    for(int u = 1; u <= n; ++ u) {
      for(auto x : conquer[u]) {
        for(auto y : conquer[u]) if(x < y) ans.pb({x, y});
      }
    }
    sort(ans.begin(), ans.end(), [&] (pair<int, int> p, pair<int, int> q) {
      if(p.F != q.F) return p.F < q.F;
      return p.S < q.S;
    });
    for(int i = 0; i < (int) ans.size(); ++ i) {
      if(i == 0 || (ans[i] != ans[i - 1])) {
        cout << ans[i].F - 1 << " " << ans[i].S - 1 << "\n";
      }
    }
  }
}

void DIJK(int s, int dist[]) {
  for(int i = 1; i <= n; ++ i) dist[i] = 2e9;
  dist[s] = 0;
  priority_queue<pair<int, int> > PQ;
  PQ.push({0, s});
  while(PQ.size()) {
    int u = PQ.top().S;
    int l = -PQ.top().F;
    PQ.pop();
    if(l > dist[u]) continue;
    for(auto p : adj[u]) {
      int v = p.F, w = p.S;
      if(dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        PQ.push({-dist[v], v});
      }
    }
  }
}

bool nofightincity() {
  for(int i = 1; i <= n; ++ i) {
    int mn = 2e9;
    for(int j = 1; j <= l; ++ j) {
      if(mn > d[j][i]) mn = d[j][i];
      else if(mn == d[j][i]) return 0;
    }
  }
  return 1;
}

namespace Sub3 {

  void Solve() {
    for(int i = 1; i <= n; ++ i) {
      int mn = 0;
      d[0][i] = 2e9;
      for(int j = 1; j <= l; ++ j) {
        if(d[mn][i] > d[j][i]) mn = j;
      }
      in[i] = mn;
    }
    vector<pair<int, int> > ans;
    for(int u = 1; u <= n; ++ u) {
      for(auto v : adj[u]) {
        if(in[u] != in[v.F]) {
          ans.pb({min(in[u], in[v.F]), max(in[u], in[v.F])});
        }
      }
    }
    sort(ans.begin(), ans.end(), [&] (pair<int, int> p, pair<int, int> q) {
      if(p.F != q.F) return p.F < q.F;
      return p.S < q.S;
    });
    for(int i = 0; i < (int) ans.size(); ++ i) {
      if(i == 0 || (ans[i] != ans[i - 1])) {
        cout << ans[i].F - 1 << " " << ans[i].S - 1 << "\n";
      }
    }
  }
}

void Solve(int Test) {
  cin >> n >> l >> m;
  for(int i = 1; i <= l; ++ i) cin >> pos[i], ++ pos[i], in[pos[i]] = i;
  int mxW = 0;
  for(int i = 1; i <= m; ++ i) {
    int u, v, w; cin >> u >> v >> w;
    ++ u, ++ v;
    adj[u].pb({v, w});
    adj[v].pb({u, w});
    mxW = max(mxW, w);
  }
  if(isbamboo()) {
    Sub1();
    return;
  }
  if(mxW == 1) {
    Sub2::Solve();
    return;
  }
  for(int i = 1; i <= l; ++ i) {
    DIJK(pos[i], d[i]);
  }
//  if(nofightincity()) {
    Sub3::Solve();
    return;
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
