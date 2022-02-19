// annotshy

#include <bits/stdc++.h>

#define Task "CONTAINER"

using namespace std;

const int maxn = 200005;

int m, w, n;
int a[maxn], cur[maxn];

void Solve(int Test) {
  cin >> m >> w >> n;
  for(int i = 1; i <= n; ++ i) cin >> a[i];
  for(int i = 1; i <= m; ++ i) cur[i] = w;
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= m + 1; ++ j) {
      if(j == m + 1) cout << -1 << "\n";
      else if(cur[j] >= a[i]) {
        cur[j] -= a[i];
        cout << j << "\n";
        break;
      }
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  if(fopen(Task".inp", "r")) {
    freopen(Task".inp", "r", stdin);
    freopen(Task".ans", "w", stdout);
  }
  int test = 1;
  // cin >> test;
  for(int i = 1; i <= test; ++ i) {
    Solve(i);
  }
}

/*no pain no gain*/