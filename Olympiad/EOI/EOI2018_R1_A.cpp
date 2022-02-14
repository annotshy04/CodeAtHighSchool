// annotshy

#include <bits/stdc++.h>

#define Task "CF"
#define pb push_back
/*Task name: Super Beautiful Number*/


using namespace std;

const int maxn = 200005;

long long n, vis[15];
vector<int> num;

bool Calc(int pos, long long sum, int ok, int last = -1) {
  if(pos == (int) num.size()) {
    if(last % 2 == 0 && sum > n) {
      cout << sum << "\n";;
      return 1;
    }
    return 0;
  }
  int lim = num[pos];
  if(ok) lim = 0;
  for(int d = lim; d <= 9; ++ d) {
    if(vis[d]) continue;
    vis[d] = 1;
    if(d == 0 && pos == 0) vis[0] = 0;
    int nexok = ok;
    if(d > lim) nexok = 1;
    if(Calc(pos + 1, sum * 10 + d, nexok, d) == 1) return 1;
    vis[d] = 0;
  }
  return 0;
}

void Solve(int Test) {
  cin >> n;
  long long x = n;
  for(int i = 0; i <= 9; ++ i) vis[i] = 0;
  num.clear();
  while(x) {
    num.pb(x % 10);
    x /= 10;
  }
  if(num.size() > 10) {
    cout << -1 << "\n";
    return;
  }
  reverse(num.begin(), num.end());
  if(Calc(0, 0, 0, -1) == 1) return;
  reverse(num.begin(), num.end());
  num.pb(0);
  reverse(num.begin(), num.end());
  if(num.size() > 10) {
    cout << -1 << "\n";
    return;
  }
  for(int i = 0; i <= 9; ++ i) vis[i] = 0;
  if(Calc(0, 0, 0, -1) == 1) return;
  cout << -1 << "\n";
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
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

/*no pain no gain*/
