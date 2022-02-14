// annotshy

#include <bits/stdc++.h>

#define Task "CF"
#define pb push_back

using namespace std;

const int maxn = 200005;

int n, child[maxn];
vector<int> adj[maxn];
int ans = 2e9;
multiset<int> s;

void Pre_DFS(int u, int p) {
  child[u] = 1;
  for(auto v : adj[u]) {
    if(v == p) continue;
    Pre_DFS(v, u);
    child[u] += child[v];
  }
}

void DFS(int u, int p = -1) {
  for(auto v : adj[u]) {
    if(v == p) continue;
    int non_sub_tree = n - child[v];
    int balanced = non_sub_tree / 2;
    auto it = s.lower_bound(balanced);
    if(it != s.end()) {
      int a = *it, b = child[v], c = n - a - b;
      ans = min(ans, max({a, b, c}) - min({a, b, c}));
    }
    if(it != s.begin()) {
      -- it;
      int a = *it, b = child[v], c = n - a - b;
      ans = min(ans, max({a, b, c}) - min({a, b, c}));
    }
    s.insert(non_sub_tree);
    DFS(v, u);
    s.erase(s.find(non_sub_tree));
    s.insert(child[v]);
  }
}

void Solve(int Test) {
  cin >> n;
  for(int i = 1; i < n; ++ i) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  Pre_DFS(1, 1);
  DFS(1);
  cout << ans << "\n";
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
