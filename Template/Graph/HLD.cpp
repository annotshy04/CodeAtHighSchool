// annotshy

#include <bits/stdc++.h>
#define Task "CF"
#define pb push_back
#define MOD 1000000007
#define F first
#define S second
#define int long long

using namespace std;

const int maxn = 100005;

int n, q;
vector<int> ke[maxn];
int nChain = 1, pos[maxn], chainIn[maxn], chainHead[maxn], nPos = 0, isVer[maxn];
int Size[maxn], par[maxn], color[maxn];
int Tpos[maxn * 4];

void DFS(int u) {
  Size[u] = 1;
  for(auto v : ke[u]) {
    if(v == par[u]) continue;
    par[v] = u;
    DFS(v);
    Size[u] += Size[v];
  }
}

void HLD(int u) {
  if(chainHead[nChain] == 0) chainHead[nChain] = u;
  chainIn[u] = nChain;
  pos[u] = ++ nPos;
  isVer[nPos] = u;
  int mxvt = 0;
  for(auto v : ke[u]) {
    if(v == par[u]) continue;
    if(Size[v] > Size[mxvt]) mxvt = v;
  }
  if(mxvt) {
    HLD(mxvt);
  }
  for(auto v : ke[u]) {
    if(v == par[u] || v == mxvt) continue;
    ++ nChain;
    HLD(v);
  }
}

void Update(int node, int l, int r, int id) {
  if(l == r) {
    if(Tpos[node]) Tpos[node] = 0;
    else Tpos[node] = l;
    return;
  }
  int mid = (l + r) >> 1;
  if(id <= mid) Update(node * 2, l, mid, id);
  else Update(node * 2 + 1, mid + 1, r, id);
  if(Tpos[node * 2]) Tpos[node] = Tpos[node * 2];
  else Tpos[node] = Tpos[node * 2 + 1];
}

int Get(int node, int l, int r, int u, int v) {
  if(l > v || r < u) return 0;
  if(l >= u && r <= v) return Tpos[node];
  int mid = (l + r) >> 1;
  int L = Get(node * 2, l, mid, u, v);
  int R = Get(node * 2 + 1, mid + 1, r, u, v);
  if(L) return L;
  return R;
}

void Solve() {
  cin >> n >> q;
  for(int i = 1; i < n; ++ i) {
    int u, v; cin >> u >> v;
    ke[u].pb(v);
    ke[v].pb(u);
  }
  DFS(1);
  HLD(1);
  while(q --) {
    int t, u; cin >> t >> u;
    if(t == 0) {
      color[pos[u]] ^= 1;
      Update(1, 1, nPos, pos[u]);
    } else {
      int uchain = chainIn[u], ans = 2e9;
      while(1) {
        if(uchain == 1) {
          int x = Get(1, 1, nPos, 1, pos[u]);
          if(color[x]) ans = min(ans, x);
          break;
        }
        int x = Get(1, 1, nPos, pos[chainHead[uchain]], pos[u]);
        if(color[x]) ans = min(ans, x);
        u = par[chainHead[uchain]];
        uchain = chainIn[u];
      }
      if(ans == 2e9) ans = -1;
      else ans = isVer[ans];
      cout << ans << "\n";
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
  int test = 1;
//  cin >> test;
  while(test --) {
    Solve();
  }
}
