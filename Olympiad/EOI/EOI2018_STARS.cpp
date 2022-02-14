// annotshy
 
#include <bits/stdc++.h>
 
#define Task "CF"
#define sz(x) (int) x.size()
#define MOD 1000000007
#define int long long
 
using namespace std;
 
const int maxn = 1005;
 
int a, b;

int Calc(int y) {
  return y / 4 - y / 100 +  y / 400;
}

void Solve(int Test) {
  cin >> a >> b;
  cout << Calc(b) - Calc(a - 1) << "\n";
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