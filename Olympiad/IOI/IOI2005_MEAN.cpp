// annotshy

#include <bits/stdc++.h>

#define Task "CF"

using namespace std;

/*Task name: Mean Sequence*/

const int maxn = 5000005;

int n;
int l = 2e9, r = -2e9;
int s, m;

void Solve(int Test) {
  cin >> n;
  for(int i = 1; i <= n; ++ i) {
  	cin >> m;
		m = 2 * m - s;
		if(i % 2) l = min(l, (m - s) / 2);
		else r = max(r, (s - m) / 2);
		s = m;
  }
  if(r <= l) cout << l - r + 1 << "\n";
	else cout << 0 << "\n";
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
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

/*no pain no gain*/