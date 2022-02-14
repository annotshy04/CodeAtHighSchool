// annotshy

#include <bits/stdc++.h>

#define Task "CF"

using namespace std;

const int maxn = 200005;

int a, b;

void Solve(int Test) {
  cin >> a >> b;
  cout << (a + b) - 1 << "\n";
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