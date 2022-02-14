// annotshy
 
#include <bits/stdc++.h>
 
#define Task "CF"
#define sz(x) (int) x.size()
#define MOD 1000000007
 
using namespace std;
 
const int maxn = 105;
 
/*
  a[l] = d = l + (d - l)
  a[l + 1] = d + 1 = (l + 1) + (d - l)
  ...
  a[r] = d + (r - l) = r + (d - l)
  id = const => maintain max (d - l)
*/
int n, m;
struct IT {
 
  vector<int> tree, lazy;
  int n;
 
  IT(int _n) {
    n = _n;
    tree.resize(4 * n + 1, -2e9);
    lazy.resize(4 * n + 1, -2e9);
  }
 
  void PushDown(int node, int l, int r) {
    if(l == r || lazy[node] == -2e9) return;
    tree[node * 2] = max(tree[node * 2], lazy[node]);
    lazy[node * 2] = max(lazy[node * 2], lazy[node]);
    tree[node * 2 + 1] = max(tree[node * 2 + 1], lazy[node]);
    lazy[node * 2 + 1] = max(lazy[node * 2 + 1], lazy[node]);
    lazy[node] = -2e9;
  }
 
  void Update(int node, int l, int r, int u, int v, int val) {
    PushDown(node, l, r);
    if(l > v || r < u) return;
    if(l >= u && r <= v) {
      tree[node] = max(tree[node], val);
      lazy[node] = max(lazy[node], val);
      return;
    }
    int mid = (l + r) >> 1;
    Update(node * 2, l, mid, u, v, val);
    Update(node * 2 + 1, mid + 1, r, u, v, val);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
  }
 
  int Get(int node, int l, int r, int id) {
    PushDown(node, l, r);
    if(l == r) return tree[node];
    int mid = (l + r) >> 1;
    if(id <= mid) return Get(node * 2, l, mid, id);
    return Get(node * 2 + 1, mid + 1, r, id);
  }
 
  void Update(int l, int r, int val) {Update(1, 1, n, l, r, val);}
  int Get(int id) {return Get(1, 1, n, id);}
};
 
void Solve(int Test) {
  cin >> n >> m;
  IT myIT(n);
  for(int i = 1; i <= m; ++ i) {
    int l, r, d; cin >> l >> r >> d;
    myIT.Update(l, r, d - l);
  }
  for(int i = 1; i <= n; ++ i) {
    cout << max(0, myIT.Get(i) + i) << " ";
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