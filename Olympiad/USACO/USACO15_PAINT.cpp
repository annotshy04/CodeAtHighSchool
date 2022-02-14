#include <bits/stdc++.h>

#define Task "paint"
#define int long long

using namespace std;

const int maxn = 100005;

void Solve() {
  int a1, a2, b1, b2;
  cin >> a1 >> a2 >> b1 >> b2;
  if(a1 > a2) swap(a1, a2);
  if(b1 > b2) swap(b1, b2);
  if(b1 <= a1) {
    if(b2 <= a1) {
      cout << b2 - b1 + a2 - a1;
    } else if(b2 <= a2) {
      cout << a2 - b1;
    } else {
      cout << b2 - b1;
    }
  } else if(b1 <= a2) {
    if(b2 <= a2) {
      cout << a2 - a1;
    } else {
      cout << b2 - a1;
    }
  } else {
    cout << a2 - a1 + b2 - b1;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  if(fopen(Task".in", "r")) {
     freopen(Task".in", "r", stdin);
     freopen(Task".out", "w", stdout);
  }
  Solve();
}

