#include<bits/stdc++.h>

#define Task "EQUALDEL"
#define pb push_back

using namespace std;

const int maxn = 100005;

int n, a[maxn];

int Subtask() {
  if(n <= 10) return 1;
  if(n <= 1000) return 2;
  return 3;
}

namespace Sub1 {

  int res = 1e9;

  void Calc(int pos, int type, int del) {
    if(pos == n + 1) {
      res = min(res, del);
      return;
    }
    int ntype = type;
    if(pos == n) {
      Calc(pos + 1, ntype, del);
    } else {
      if(ntype == -1) {
        if(a[pos] < a[pos + 1]) ntype = 0, Calc(pos + 1, ntype, del);;
        if(a[pos] > a[pos + 1]) ntype = 1, Calc(pos + 1, ntype, del);;
      } else {
        if(a[pos] < a[pos + 1] && ntype == 0) Calc(pos + 1, ntype, del);
        else if(a[pos] > a[pos + 1] && ntype == 1) Calc(pos + 1, ntype, del);
      }
    }
    for(int i = pos + 1; i <= n; ++ i) {
      if(a[i] != a[pos]) continue;
      if(i == n) {
        Calc(i + 1, ntype, del + 1);
      } else {
        ntype = type;
        if(ntype == -1) {
          if(a[pos] < a[i + 1]) ntype = 0,  Calc(i + 1, ntype, del + 1);
          if(a[pos] > a[i + 1]) ntype = 1,  Calc(i + 1, ntype, del + 1);
        } else {
          if(a[pos] < a[i + 1] && ntype == 0) Calc(i + 1, ntype, del + 1);
          else if(a[pos] > a[i + 1] && ntype == 1) Calc(i + 1, ntype, del + 1);
        }
      }
    }
  }

  void Solve() {
    res = 1e9;
    Calc(1, -1, 0);
    if(res == 1e9) res = -1;
    cout << res << "\n";
  }
}

int dp[maxn][2];

namespace Sub2 {

  void Solve() {
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = dp[1][1] = 0;
    for(int i = 2; i <= n + 1; ++ i) {
      for(int flag = 0; flag <= 1; ++ flag) {
        if(dp[i - 1][flag] < 1e9) {
          if(i == n + 1) {
             dp[i][flag] = min(dp[i][flag], dp[i - 1][flag]);
          } else {
            if((a[i - 1] < a[i] && flag == 0) || (a[i - 1] > a[i] && flag == 1))
              dp[i][flag] = min(dp[i][flag], dp[i - 1][flag]);
          }
        }
        for(int j = i - 2; j >= 1; -- j) {
          if(a[j] == a[i - 1]) {
            if(i != n + 1 && a[j] < a[i] && flag == 1) continue;
            if(i != n + 1 && a[j] > a[i] && flag == 0) continue;
            if(dp[j][flag] >= 1e9) continue;
            dp[i][flag] = min(dp[i][flag], dp[j][flag] + 1);
          }
        }
      }
    }
    int res = 1e9;
    res = min(res, dp[n + 1][0]);
    res = min(res, dp[n + 1][1]);
    if(res == 1e9) res = -1;
    cout << res << "\n";
  }
}

namespace Full {

  int best[maxn][2];

  void Solve() {
    memset(dp, 0x3f, sizeof dp);
    memset(best, 0x3f, sizeof best);
    dp[1][0] = dp[1][1] = 0;
    best[a[1]][0] = 0;
    best[a[1]][1] = 0;
    for(int i = 2; i <= n + 1; ++ i) {
      for(int flag = 0; flag <= 1; ++ flag) {
        if((i == n + 1) || (a[i - 1] > a[i] && flag == 1) || (a[i - 1] < a[i] && flag == 0)) {
          if(dp[i - 1][flag] < 1e9) {
            dp[i][flag] = min(dp[i][flag], dp[i - 1][flag]);
          }
          if(best[a[i - 1]][flag] < 1e9) {
            dp[i][flag] = min(dp[i][flag], best[a[i - 1]][flag] + 1);
            best[a[i]][flag] = min(best[a[i]][flag], dp[i][flag]);
          }
        }
      }
    }
    int res = 1e9;
    res = min(res, dp[n + 1][0]);
    res = min(res, dp[n + 1][1]);
    if(res == 1e9) res = -1;
    cout << res << "\n";
  }
}

void Solve(int Test) {
  cin >> n;
  vector<int> v;
  for(int i = 1; i <= n; ++ i) cin >> a[i], v.pb(a[i]);
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  for(int i = 1; i <= n; ++ i) {
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
  }
//  if(Subtask() == 1)
//    Sub1::Solve();
//  if(Subtask() == 2)
//    Sub2::Solve();
//  if(Subtask() == 3)
    Full::Solve();
}

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
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
