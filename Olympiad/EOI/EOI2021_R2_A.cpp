// annotshy

#include <bits/stdc++.h>

#define Task "CF"

/*
	Task: Split l 8laba
*/

using namespace std;

const int maxn = 200005;

int n, a[maxn];

void Solve(int Test) {
  cin >> n;
  for(int i = 1; i <= n; ++ i) cin >> a[i];
  long long s = accumulate(a + 1, a + n + 1, 0ll);
	long long sum = 0;
	for(int i = 1; i < n; ++ i) {
		sum += a[i];
		if(s % sum) continue;
		long long cur = 0;
		int ok = 1;
		for(int j = i + 1; j <= n; ++ j) {
			cur += a[j];
			if(cur == sum) cur = 0;
			else if(cur > sum) {
				ok = 0;
				break;
			}
		}
		if(ok) {
			cout << "YES" << "\n";
			return;
		}
	}
	cout << "NO" << "\n";
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