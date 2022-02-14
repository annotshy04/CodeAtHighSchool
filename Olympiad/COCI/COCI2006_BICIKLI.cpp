// annotshy

#include <bits/stdc++.h>

#define Task "CF"
#define MOD 1000000000
#define pb push_back

using namespace std;

const int maxn = 200005;

int n, m;
vector<int> adj[maxn], ke[maxn];
int vis[maxn], deg[maxn];
bool iscycle = 0, ok[3][maxn], usable[maxn];
long long dp[maxn];

void Pre_DFS(int u, bool used[], int t) {
  used[u] = 1;
  if(t == 1) {
    for(auto v : adj[u]) {
      if(used[v]) continue;
      Pre_DFS(v, used, t);
    }
  } else {
    for(auto v : ke[u]) {
      if(used[v]) continue;
      Pre_DFS(v, used, t);
    }
  }
}

void DFS(int u) {
  vis[u] = 2;
  for(auto v : adj[u]) if(usable[v]) {
    if(vis[v]) {
      if(vis[v] == 2) iscycle = 1;
      continue;
    } 
    DFS(v);
  }
  vis[u] = 1;
}

void Solve(int Test) {
  cin >> n >> m;
  for(int i = 1; i <= m; ++ i) {
  	int u, v; cin >> u >> v;
  	adj[u].pb(v);
    ke[v].pb(u);
  }
  Pre_DFS(1, ok[1], 1);
  Pre_DFS(2, ok[2], 2);
  for(int i = 1; i <= n; ++ i) if(ok[1][i] && ok[2][i]) usable[i] = 1;
  DFS(1);
  if(iscycle) {
  	if(vis[2]) cout << "inf" << "\n";
    return; 
  }
  for(int i = 1; i <= n; ++ i) {
    if(usable[i]) {
      for(auto v : adj[i]) deg[v] ++;
    }
  }
  queue<int> q;
  dp[1] = 1;
  q.push(1);
  int ok = 0;
  while(q.size()) {
    int u = q.front();
    q.pop();
    for(auto v : adj[u]) {
      dp[v] += dp[u];
      if(dp[v] >= MOD) {
        dp[v] -= MOD;
        ok = 1;
      }
      if(-- deg[v] == 0) q.push(v);
    }
  }
  if(!ok) cout << dp[2] << "\n";
  else {
    int x = dp[2];
    int cnt = 0;
    while(x) {
      x /= 10;
      ++ cnt;
    }
    for(int i = 1; i <= 9 - cnt; ++ i) cout << 0;
    cout << dp[2] << "\n";
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