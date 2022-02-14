/*
  Problem: CF_220B
*/

#include <bits/stdc++.h>

#define Task ""

using namespace std;

const int maxn = 100005;
int n, m, k, a[maxn], Block;
int cnt[maxn], ans[maxn];
long long res = 0;
vector<int> val;

struct Query {
  int l, r, id;
} Q[maxn];

bool cmp(Query a, Query b) {
  if(a.l / Block != b.l / Block) return a.l / Block < b.l / Block;
  return a.r > b.r;
}

void Add(int x) {
  res -= (cnt[x] == val[x - 1]);
  ++ cnt[x];
  res += (cnt[x] == val[x - 1]);
}

void Del(int x) {
  res -= (cnt[x] == val[x - 1]);
  -- cnt[x];
  res += (cnt[x] == val[x - 1]);
}

void Solve() {
  cin >> n >> m;
  Block = sqrt(n) + 1;
  for(int i = 1; i <= n; ++ i) cin >> a[i], val.push_back(a[i]);
  sort(val.begin(), val.end());
  val.resize(unique(val.begin(), val.end()) - val.begin());
  for(int i = 1; i <= n; ++ i) {
    a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin() + 1;
  }
  for(int i = 1; i <= m; ++ i) {
    int l, r; cin >> l >> r;
    Q[i] = {l, r, i};
  }
  sort(Q + 1, Q + m + 1, cmp);
  int curL = 1, curR = 0;
  for(int i = 1; i <= m; ++ i) {
    int L = Q[i].l, R = Q[i].r, id = Q[i].id;
    while(curL < L) Del(a[curL ++]);
    while(curL > L) Add(a[-- curL]);
    while(curR > R) Del(a[curR --]);
    while(curR < R) Add(a[++ curR]);
    ans[id] = res;
  }
  for(int i = 1; i <= m; ++ i) cout << ans[i] << "\n";
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  if(fopen(Task".inp", "r")) {
     freopen(Task".inp", "r", stdin);
     freopen(Task".out", "w", stdout);
  }
  Solve();
}

