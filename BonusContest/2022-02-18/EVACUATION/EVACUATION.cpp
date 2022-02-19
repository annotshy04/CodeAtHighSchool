#include<bits/stdc++.h>

#define Task "EVACUATION"
#define pb push_back

using namespace std;

const int maxn = 200005;

int n;
struct DATA {
  int v, d, t;
};
vector<DATA> adj[maxn];
bool leaf[maxn];

namespace Sub1 {

  bool DFS(int u, int par, int t) {
    if(leaf[u]) return 1;
    for(auto p : adj[u]) {
      int v = p.v, d = p.d;
      if(p.t < t + d) continue;
      if(v == par) continue;
      if(DFS(v, u, t + d)) return 1;
    }
    return 0;
  }

  void solve() {
    int res = 0;
    for(int i = 1; i <= n; ++ i) {
      if(leaf[i]) {
        ++ res;
        continue;
      }
      res += DFS(i, i, 0);
    }
    cout << res << "\n";
  }
}

namespace Full {

  int dp[maxn][3], res = 0;

  void DFS(int u, int par) {
    if(leaf[u]) {
      dp[u][1] = dp[u][2] = 1e9;
    } else dp[u][1] = dp[u][2] = -1;
    for(auto p : adj[u]) {
      int v = p.v, d = p.d, t = p.t;
      if(v == par) continue;
      DFS(v, u);
      int val = min(dp[v][1] - d, t - d);
      if(dp[u][1] < val) dp[u][1] = val;
      else if(dp[u][2] < val) dp[u][2] = val;
    }
  }

  void Reroot(int u, int par) {
    if(dp[u][1] != -1 || dp[u][2] != -1) ++res;
    for(auto p : adj[u]) {
      int v = p.v, d = p.d, t = p.t;
      if(v == par) continue;
      int val = min(dp[v][1] - d, t - d), nexval;
      if(dp[u][1] == val) nexval = min(dp[u][2] - d, t - d);
      else nexval = min(dp[u][1] - d, t - d);
      int save_1 = dp[v][1], save_2 = dp[v][2];
      if(dp[v][1] < nexval) dp[v][1] = nexval;
      else if(dp[v][2] < nexval) dp[v][2] = nexval;
      Reroot(v, u);
      dp[v][1] = save_1;
      dp[v][2] = save_2;
    }
  }

  void solve() {
    DFS(1, 1);
    Reroot(1, 1);
    cout << res << "\n";
  }
}

void Solve(int Test) {
  cin >> n;
  for(int i = 1; i < n; ++ i) {
    int u, v, d, t;
    cin >> u >> v >> d >> t;
    adj[u].pb({v, d, t});
    adj[v].pb({u, d, t});
  }
  for(int i = 1; i <= n; ++ i) {
    if((int) adj[i].size() == 1) leaf[i] = 1;
  }
  if(n <= 1000)
    Sub1::solve();
  else
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
