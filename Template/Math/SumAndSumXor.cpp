// annotshy

#include <bits/stdc++.h>

#define Task "CF"
#define pb push_back
#define sz(x) (int) x.size()
#define F first
#define S second
// #define int long long
#define MOD 998244353

using namespace std;

const int maxn = 200005;

long long sum, Xor;

void Solve(int Test) {
  cin >> sum >> Xor;
  long long And = (sum - Xor) / 2;
  if(sum % 2 != Xor % 2) {
    cout << 0;
    return;
  }
  if((And & Xor)) {
    cout << 0;
    return;
  }
  long long ans = (1ll << __builtin_popcountll(Xor));
  if(Xor == sum) cout << ans - 2;
  else cout << ans;
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

/*no pain no gain*/
