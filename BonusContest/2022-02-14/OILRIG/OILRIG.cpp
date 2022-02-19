#include<bits/stdc++.h>

#define Task "OILRIG"
#define pb push_back
#define F first
#define S second
#define int long long

using namespace std;

const int maxn = 3005;

int n;
struct DATA {
  int a, b, c;
} rig[maxn];
int par[maxn], m = 0, child[maxn], d[maxn], val[maxn];
vector<int> adj[maxn];
long long best[maxn], sum[maxn], g[maxn][maxn * 2];

void Pre_DFS(int u) {
  for(auto v : adj[u]) {
    if(v == par[u]) continue;
    par[v] = u;
    d[v] = d[u] + 1;
    Pre_DFS(v);
  }
}

void Find(int u, int s) {
  if(d[u] != d[s] + 1) val[++ m] = rig[u].a;
  for(auto v : adj[u]) {
    if(v == par[u]) continue;
    Find(v, s);
  }
}

// Prepare for subtask 1 and 2

//void Calc(int u, int mask, int len) {
//  for(int i = 1; i <= n; ++ i) vis[i] = 0;
//  int need = 0;
//  long long res = 0;
//  for(int i = 0; i < len; ++ i) {
//    if(mask >> i & 1) {
//      int v = adj[u][i];
//      vis[v] = 1;
//      need += rig[v].b;
//      res += rig[v].c;
//    }
//  }
//  int can = 0;
//  for(int i = 1; i <= m; ++ i) {
//    if(vis[val[i].S]) continue;
//    if(can < need) can ++;
//    else {
//      res += val[i].F;
//    }
//  }
//  if(can < need) return;
//  best[u] = max(best[u], res);
//}

namespace Sub1 {

  int child[maxn];
  long long ans = 0;

  bool Colapse(int u) {
    int have = 0;
    if(child[u] == 1) have = 1;
    for(auto v : adj[u]) {
      if(v == par[u]) continue;
      if(Colapse(v)) return 1;
      if(have && child[v]) return 1;
      child[u] += child[v];
    }
    return 0;
  }

  long long Get_Ans(int u, int mask) {
    if(mask >> (u - 1) & 1) return best[u];
    long long res = rig[u].a;
    for(auto v : adj[u]) {
      if(v == par[u]) continue;
      res += Get_Ans(v, mask);
    }
    return res;
  }

  void Solve() {
    for(int mask = 0; mask < (1 << n); ++ mask) {
      for(int i = 1; i <= n; ++ i) {
        if(mask >> (i - 1) & 1) child[i] = 1;
        else child[i] = 0;
      }
      if(Colapse(1)) continue;
      ans = max(ans, Get_Ans(1, mask));
    }
    cout << ans << "\n";
  }
}

namespace Sub_2_3 {

  long long dp[maxn][2];

  void DFS(int u) {
    dp[u][0] = sum[u], dp[u][1] = best[u];
    long long cur = rig[u].a;
    for(auto v : adj[u]) {
      if(v == par[u]) continue;
      DFS(v);
      cur += max(dp[v][0], dp[v][1]);
    }
    dp[u][1] = max(dp[u][1], cur);
  }

  void Solve() {
    DFS(1);
    cout << max(dp[1][0], dp[1][1]) << "\n";
  }
}

void Solve(int Test) {
  cin >> n;
  for(int i = 1; i <= n; ++ i) cin >> rig[i].a >> rig[i].b >> rig[i].c;
  for(int i = 1; i < n; ++ i) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  Pre_DFS(1);
  int delta = n;
  for(int u = 1; u <= n; ++ u) {
    int cnt = 0;
    for(auto v : adj[u]) {
      if(v == par[u]) continue;
      best[u] += rig[v].a;
      child[++ cnt] = v;
    }
    m = 0;
    Find(u, u);
    sort(val + 1, val + m + 1);
    long long cur = 0;
    for(int i = 1; i <= m; ++ i) {
      best[u] += val[i];
      cur += val[i];
    }
    sum[u] = best[u];
    for(int i = 0; i <= cnt; ++ i) {
      for(int j = -n; j <= n; ++ j) g[i][j + delta] = -1e18;
    }
    g[0][delta] = 0;
    for(int i = 1; i <= cnt; ++ i) {
      int id = child[i];
      for(int x = -n; x <= n; ++ x) {
        g[i][x + delta] = max(g[i][x + delta], g[i - 1][x + delta] + rig[id].a);
        if(x + 1 <= n) g[i][x + delta] = max(g[i][x + delta], g[i - 1][x + 1 + delta]);
        if(x - rig[id].b >= -n) g[i][x + delta] = max(g[i][x + delta], g[i - 1][x - rig[id].b + delta] + rig[id].c);
      }
    }
    for(int i = 1; i <= m + 1; ++ i) {
      best[u] = max(best[u], cur + g[cnt][i - 1 + delta]);
      cur -= val[i];
    }
  }
  if(n <= 20) {
   Sub1::Solve();
   return;
  }
  Sub_2_3::Solve();
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
