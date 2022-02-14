// annotshy

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define Task "CF"
#define pb push_back
#define MOD 998244353
#define F first
#define S second

//#define int long long

//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int maxn = 105;

int m, n;
char a[maxn][maxn];
int from, to, in[maxn][maxn], out[maxn][maxn];
pair<int, int> s, t;

struct Dinic {

  struct Edge {
    int u, v, c, f;
  };
  int nEdge = -1, h[20005], start[20005];
  vector<int> adj[20005];
  vector<Edge> edge;

  void Add(int u, int v, int w) {
    edge.pb({u, v, w, 0});
    adj[u].pb(edge.size() - 1);
    edge.pb({v, u, 0, 0});
    adj[v].pb(edge.size() - 1);
  }

  bool BFS(int _s, int _t) {
    memset(h, -1, sizeof h);
    memset(start, 0, sizeof start);
    h[_s] = 0;
    queue<int> Q;
    Q.push(_s);
    while(Q.size()) {
      int u = Q.front();
      Q.pop();
      for(auto id : adj[u]) {
        int v = edge[id].v;
        if(h[v] == -1 && edge[id].c > edge[id].f) {
          h[v] = h[u] + 1;
          Q.push(v);
        }
      }
    }
    return h[_t] != -1;
  }

  int DFS(int u, int delta, int _t) {
    if(delta == 0) return delta;
    if(u == _t) return delta;
    for(int &i = start[u]; i < (int) adj[u].size(); i ++) {
      int id = adj[u][i];
      int v = edge[id].v;
      if(h[v] == h[u] + 1 && edge[id].c > edge[id].f) {
        int x = DFS(v, min(delta, edge[id].c - edge[id].f), _t);
        if(x) {
          edge[id].f += x;
          edge[id ^ 1].f -= x;
          return x;
        }
      }
    }
    return 0;
  }

  int MaxFlow(int from, int to) {
    int ans = 0;
    while(BFS(from, to)) {
      while(int x = DFS(from, 2e9, to))
        ans += x;
    }
    return ans;
  }
} myFlow;

int Decode(int i, int j) {
  return m * (i - 1) + j;
}

void Solve(int Test) {
  cin >> n >> m;
  int cnt = 0;
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= m; ++ j) {
      cin >> a[i][j];
      if(a[i][j] == '.') continue;
      in[i][j] = ++ cnt;
      out[i][j] = ++ cnt;
    }
  }
  from = cnt + 1, to = cnt + 2;
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= m; ++ j) {
      if(a[i][j] == '.') continue;
      if(a[i][j] == 'S') {
        myFlow.Add(from, out[i][j], 2e9);
        s = {i, j};
      } else if(a[i][j] == 'T') {
        myFlow.Add(in[i][j], to, 2e9);
        t = {i, j};
      }
      else myFlow.Add(in[i][j], out[i][j], 1);
      for(int k = i + 1; k <= n; ++ k) {
        if(a[k][j] != '.') {
          myFlow.Add(out[i][j], in[k][j], 1);
          myFlow.Add(out[k][j], in[i][j], 1);
        }
      }
      for(int k = j + 1; k <= m; ++ k) {
        if(a[i][k] != '.') {
          myFlow.Add(out[i][j], in[i][k], 1);
          myFlow.Add(out[i][k], in[i][j], 1);
        }
      }
    }
  }
  if(s.F == t.F || s.S == t.S) {
    cout << -1 << "\n";
    return;
  }
  cout << myFlow.MaxFlow(from, to) << "\n";
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  if(fopen(Task".inp", "r")) {
     freopen(Task".inp", "r", stdin);
     freopen(Task".out", "w", stdout);
  }
  int test = 1;
//  cin >> test;
  for(int i = 1; i <= test; ++ i) {
    Solve(i);
  }
}
