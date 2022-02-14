#include<bits/stdc++.h>

#define Task "TRACKING"
#define int long long

using namespace std;

const int maxn = 200005;

struct Point {
  long long x, y;
} P[maxn];
Point center;
int n;

namespace Sub1 {

  long long Area(Point A, Point B, Point C) {
    return abs((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y));
  }

  void Solve() {
    int res = 0;
    for(int i = 1; i <= n; ++ i) {
      for(int j = i + 1; j <= n; ++ j) {
        for(int k = j + 1; k <= n; ++ k) {
          long long S1 = Area(P[i], P[j], center);
          long long S2 = Area(P[i], P[k], center);
          long long S3 = Area(P[k], P[j], center);
          long long S = S1 + S2 + S3, s = Area(P[i], P[j], P[k]);
          if(S1 && S2 && S3 && s == S) ++ res;
        }
      }
    }
    cout << res << "\n";
  }
}

namespace Sub2 {

  pair<long long, long long> Vecto(Point a, Point b){
    return {b.x - a.x, b.y - a.y};
  }

  long long CCW(Point a, Point b, Point c){
    pair<long long, long long> u = Vecto(a, b);
    pair<long long, long long> v = Vecto(a, c);
    return (u.F * v.S - u.S * v.F);
  }

  void Solve() {
    for(int i = 1; i <= n; ++ i) {
      P[i].x -= center.x;
      P[i].y -= center.y;
    }
    center = {0, 0};
    for(int i = 1; i <= n; ++ i) {
      int sign = 1;
      if(P[i].x < 0) sign = -1;
      Point dx = {-P[i].x, -P[i].y};
      int pos = 0, neg = 0;
      for(int j = 1; j <= n; ++ j) if(i != j) {
        if(sign == 1) {
          if(P[j].x >= 0) continue;
        } else {
          if(P[j].x < 0) continue;
        }
        if(CCW(P[i], center, P[j]))
      }
    }
  }

}

void Solve(int Test) {
  cin >> n;
  cin >> center.x >> center.y;
  for(int i = 1; i <= n; ++ i) cin >> P[i].x >> P[i].y;
  if(n <= 200) {
    Sub1::Solve();
    return;
  }
  if(n <= 5000) {
    Sub2::Solve();
    return;
  }
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
