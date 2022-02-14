// annotshy
/*
  Problem: TANCHAN - freecontest 
*/
#include <bits/stdc++.h>

#define Task "TANCHAN"
#define F first
#define S second

using namespace std;

const int maxn = 200005;

int n, a[maxn], st[maxn], top = 0;
long long s[maxn], f[maxn];
pair<long long, long long> line[maxn];
double p[maxn], q[maxn], x[maxn]; // y = px + q;

// new, top, top - 1;
bool Check(int i, int j, int k) {
  double x1 = 1.0 * (line[i].S - line[j].S) / (line[j].F - line[i].F);
  double x2 = 1.0 * (line[i].S - line[k].S) / (line[k].F - line[i].F);
  return (x1 > x2);
}

void Solve(int Test) {
  cin >> n;
  for(int i = 1; i <= n; ++ i) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
    f[i] = f[i - 1] + 1ll * i * a[i];
    line[i] = {(i - 1), 1ll * (i - 1) * s[i - 1] - f[i - 1]};
  }
  int l = 0, r = 0;
  long long ans = -2e18;
  for(int i = 1; i <= n; ++ i) {
    while(top > 1 && !Check(i, st[top], st[top - 1])) -- top;
    st[++ top] = i;
    p[top] = line[i].F, q[top] = line[i].S;
    if(top == 1) x[top] = -2e9;
    else x[top] = (q[top] - q[top - 1]) / (p[top - 1] - p[top]);
    int pos = upper_bound(x + 1, x + top + 1, - s[i]) - x - 1;
    int id = st[pos];
    if(ans < f[i] - line[id].F * s[i] + line[id].S) {
      ans = f[i] - line[id].F * s[i] + line[id].S;
      l = line[id].F + 1, r = i;
    }
  }
  cout << ans << "\n";
  cout << l << " " << r;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  if(fopen(Task".inp", "r")) {
     freopen(Task".inp", "r", stdin);
     freopen(Task".out", "w", stdout);
  }
  int test = 1;
//  cin >> test;
  for(int i = 1; i <= test; ++ i) {
    Solve(i);
  }
}

