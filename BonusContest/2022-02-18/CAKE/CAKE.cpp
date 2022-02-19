#include<bits/stdc++.h>

#define Task "CAKE"
#define F first
#define S second

using namespace std;

const int maxn = 200005;

int n, T;
pair<int, int> a[maxn];

namespace Sub1 {

  void solve() {
    multiset<int> s;
    int ans = 0;
    for(int i = 1; i <= n; ++ i) {
      s.insert(a[i].S);
      long long res = a[i].F;
      int cnt = 0;
      for(auto it = s.begin(); it != s.end(); ++ it) {
        if(res + (*it) > T) break;
        res += *it;
        cnt ++;
      }
      ans = max(ans, cnt);
    }
    cout << ans << "\n";
  }
}

namespace Full {

  void solve() {
    priority_queue<int> PQ;
    long long res = 0;
    int ans = 0;
    for(int i = 1; i <= n; ++ i) {
      PQ.push(a[i].S);
      res += a[i].F - a[i - 1].F + a[i].S;
      while(PQ.size() && res > T) {
        res -= PQ.top();
        PQ.pop();
      }
      ans = max(ans, (int) PQ.size());
    }
    cout << ans << "\n";
  }
}

void Solve(int Test) {
  cin >> n >> T;
  for(int i = 1; i <= n; ++ i) {
    cin >> a[i].F >> a[i].S;
  }
//  if(n <= 1000)
//    Sub1::solve();
//  else
    Full::solve();
}

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
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
