#include<bits/stdc++.h>

#define Task "PUZZLAND"
#define pb push_back
#define F first
#define S second

using namespace std;

const int maxn = 35;

int n, m;
char label[maxn];
map<char, int> node;

namespace Full {

  vector<int> adj[maxn];
  int vis[maxn];

  bool DFS(int u, string res, int numnode) {
    if(u == n) {
      if(numnode != n) return 0;
      cout << res << "\n";
      return 1;
    }
    for(auto v : adj[u]) {
      if(vis[v]) continue;
      vis[v] = 1;
      if(DFS(v, res + label[v], numnode + 1)) return 1;
      vis[v] = 0;
    }
    return 0;
  }

  void Solve() {
    for(int i = 1; i <= n; ++ i) adj[i].clear(), vis[i] = 0;
    for(int i = 1; i <= m; ++ i) {
      char a, b; cin >> a >> b;
      int u = node[a], v = node[b];
      adj[u].pb(v);
      adj[v].pb(u);
    }
    for(int i = 2; i < n; ++ i) {
      if((int) adj[i].size() <= 1) {
        cout << "IMPOSSIBLE" << "\n";
        return;
      }
    }
    for(int i = 1; i <= n; ++ i) if(adj[i].size()) {
      sort(adj[i].begin(), adj[i].end(), [&] (int x, int y) {
        return label[x] < label[y];
      });
    }
    string cur = "";
    cur += label[1];
    vis[1] = 1;
    if(!DFS(1, cur, 1)) cout << "IMPOSSIBLE" << "\n";
  }
}

void Solve(int Test) {
  cin >> n >> m;
  node.clear();
  for(int i = 1; i <= n; ++ i) {
    cin >> label[i];
    node[label[i]] = i;
  }
  Full::Solve();
}

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  if(fopen(Task".inp", "r")) {
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
  }
  int test = 1;
  cin >> test;
  for(int i = 1; i <= test; ++ i) {
    Solve(i);
  }
}
