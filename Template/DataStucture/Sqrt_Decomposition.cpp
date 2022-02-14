// annotshy

/*
  Problem: CF_348C
*/

#include <bits/stdc++.h>

#define Task ""
#define int long long

using namespace std;

const int maxn = 100005;

int n, m, q, sz[maxn], a[maxn], cnt_big = 0, Block, dd[maxn];
int intersect[320][maxn];
vector<int> S[maxn];
long long ans_big[maxn], big[maxn], add[maxn];

/*
  su dung sqrt decomposition O(q sqrt(n))
  + chia 2 tap co sz > can n va < can n
  neu tap nho: xet tung phan tu de update, su dung mang intersect de tinh so
                    phan tu trong tap lon
  neu tap lon: luu 1 mang so lan tang gia tri de tinh toan
*/

void Solve() {
  cin >> n >> m >> q;
  Block = sqrt(n) + 1;
  for(int i = 1; i <= n; ++ i) cin >> a[i];
  for(int i = 1; i <= m; ++ i) {
    cin >> sz[i];
    S[i].resize(sz[i] + 1);
    for(int j = 1; j <= sz[i]; ++ j) cin >> S[i][j];
  }
  for(int i = 1; i <= m; ++ i) {
    if(sz[i] > Block) {
      big[++ cnt_big] = i;
      for(int j = 1; j <= sz[i]; ++ j) dd[S[i][j]] ++, ans_big[i] += a[S[i][j]];
      for(int j = 1; j <= m; ++ j) {
        for(int k = 1; k <= sz[j]; ++ k) intersect[cnt_big][j] += dd[S[j][k]];
      }
      for(int j = 1; j <= sz[i]; ++ j) dd[S[i][j]] = 0;
    }
  }
  while(q --) {
    char t; cin >> t;
    if(t == '?') {
      int id; cin >> id;
      long long ans = 0;
      for(int i = 1; i <= cnt_big; ++ i) ans += 1ll * add[big[i]] * intersect[i][id];
      if(sz[id] > Block) {
        ans += ans_big[id];
      } else {
        for(int i = 1; i <= sz[id]; ++ i) ans += a[S[id][i]];
      }
      cout << ans << "\n";
    } else {
      int id, val; cin >> id >> val;
      if(sz[id] > Block) {
        add[id] += val;
      } else {
        for(int i = 1; i <= sz[id]; ++ i) a[S[id][i]] += val;
        for(int i = 1; i <= cnt_big; ++ i) ans_big[big[i]] += 1ll * val * intersect[i][id];
      }
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
  Solve();
}

