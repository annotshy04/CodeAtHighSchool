// annotshy

#include <bits/stdc++.h>

#define Task ""
#define pb push_back

using namespace std;

const int maxn = 200005;

// never get impossible!
int n;
vector<int> adj[maxn];
int nChild[maxn], par_centroid[maxn], processed[maxn];
int descent[maxn];
char ans[maxn];

int Find_size(int u, int p = -1) {
  if(processed[u]) return 0;
  nChild[u] = 1;
  for(auto v : adj[u]) {
    if(v != p) nChild[u] += Find_size(v, u);
  }
  return nChild[u];
}

int Find_centroid(int u, int p, int n) {
  for(auto v : adj[u]) {
    if(v == p || processed[v]) continue;
    if(nChild[v] * 2 > n) return Find_centroid(v, u, n);
  }
  return u;
}

void Build_centroid(int u = 1, int p = -1) {
  int centroid = Find_centroid(u, p, Find_size(u));
  processed[centroid] = 1;
  if(p != -1) descent[p] ++;
  par_centroid[centroid] = p;
  for(auto v : adj[centroid]) {
    if(!processed[v]) Build_centroid(v, centroid);
  }
}

void Solve(int Test) {
  cin >> n;
  for(int i = 1; i < n; ++ i) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  for(int i = 1; i <= n; ++ i) ans[i] = 'Z' + 1;
  Build_centroid();
  for(int i = 1; i <= n; ++ i) {
    if(!descent[i]) {
      int u = i;
      char c = 'Z';
      while(u != -1) {
        if(c < ans[u]) ans[u] = c --;
        u = par_centroid[u];
      }
    }
  }
  for(int i = 1; i <= n; ++ i) cout << ans[i] << " ";
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  if(fopen(Task".inp", "r")) {
     freopen(Task".inp", "r", stdin);
//     freopen(Task".out", "w", stdout);
  }
  int test = 1;
//  cin >> test;
  for(int i = 1; i <= test; ++ i) {
    Solve(i);
  }
}

