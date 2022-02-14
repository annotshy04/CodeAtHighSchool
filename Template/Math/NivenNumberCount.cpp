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

const int maxn = 1005;

int sum;
long long n, dp[15][120][120][2];
vector<int> num;

long long DP(int pos, int left, int mod, int f) {
  if(pos == sz(num)) return (left == 0 && mod == 0);
  long long &res = dp[pos][left][mod][f];
  if(res != -1) return res;
  res = 0;
  int limit = 9;
  if(!f) limit = num[pos];
  for(int d = 0; d <= min(limit, left); ++ d) {
    int nexf = f;
    if(d < limit) nexf = 1;
    res += DP(pos + 1, left - d, (mod * 10 + d) % sum, nexf);
  } 
  return res;
}

long long Calc(long long n) {
  while(n) {
    num.pb(n % 10);
    n /= 10;
  }
  reverse(num.begin(), num.end());
  int maxsum = sz(num) * 9;
  long long res = 0;
  for(int i = 1; i <= maxsum; ++ i) {
    sum = i;
    memset(dp, -1, sizeof dp);
    res += DP(0, sum, 0, 0);
  }
  return res;
} 

void Solve(int Test) {
  cin >> n;
  cout << Calc(n) << "\n";
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  // if(fopen(Task".inp", "r")) {
  //   freopen(Task".inp", "r", stdin);
  //   freopen(Task".out", "w", stdout);
  // }
  int test = 1;
//  cin >> test;
  for(int i = 1; i <= test; ++ i) {
    Solve(i);
  }
}

/*no pain no gain*/
