// annotshy

#include <bits/stdc++.h>

#define Task "CONTAINER"

using namespace std;

const int maxn = 200005;

int m, w, n;
int a[maxn], tree[maxn * 4];

void Build(int node, int l, int r) {
  if(l == r) {
    tree[node] = w;
    return;
  }
  int mid = (l + r) >> 1;
  Build(node * 2, l, mid);
  Build(node * 2 + 1, mid + 1, r);
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

void Update(int node, int l, int r, int id, int val) {
  if(l == r) {
    tree[node] -= val;
    return;
  }
  int mid = (l + r) >> 1;
  if(id <= mid) Update(node * 2, l, mid, id, val);
  else Update(node * 2 + 1, mid + 1, r, id, val);
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int Get(int node, int l, int r, int id) {
  if(l == r) return l;
  int mid = (l + r) >> 1;
  if(tree[node * 2] >= a[id]) return Get(node * 2, l, mid, id);
  return Get(node * 2 + 1, mid + 1, r, id);
}

void Solve(int Test) {
  cin >> m >> w >> n;
  for(int i = 1; i <= n; ++ i) cin >> a[i];
  m = min(n, m);
  Build(1, 1, m);
  for(int i = 1; i <= n; ++ i) {
    if(a[i] > tree[1]) cout << -1 << "\n";
    else {
      int pos = Get(1, 1, m, i);
      cout << pos << "\n";
      Update(1, 1, m, pos, a[i]);
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
  // cin >> test;
  for(int i = 1; i <= test; ++ i) {
    Solve(i);
  }
}

/*no pain no gain*/
