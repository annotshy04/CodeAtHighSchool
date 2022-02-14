// annotshy

#include <bits/stdc++.h>

#define Task "CF"

using namespace std;

/*Task name: Operations*/

const int maxn = 200005;

long long a, b;

void Solve(int Test) {
  cin >> a >> b;
  if(a == 0 && b == 0) {
	  cout << "*\n";
	  return;
	}
  if(a == 0) {
  	if(b < 0) cout << "-\n";
  	else cout << "+\n";
  	return;
  }
  if(b == 0) {
  	if(a > 0) cout << "+\n";
  	else cout << "*\n";
  	return;
  }
  if(abs(a) == 1 || abs(b) == 1) {
  	long long res1 = a + b, res2 = a - b, res3 = a * b;
  	long long mx = max({res1, res2, res3});
  	if(mx == res3) cout << "*\n";
  	else if(mx == res1) cout << "+\n";
  	else cout << "-\n";
  	return;
  }
  if((a < 0 && b < 0) || (a > 0 && b > 0)) {
  	cout << "*" << "\n";
  	return;
	}
	if(a - b > a + b) cout << "-" << "\n";
	else cout << "+" << "\n";
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