// annotshy
 
#include <bits/stdc++.h>
 
#define Task "CF"
#define sz(x) (int) x.size()
#define MOD 1000000007
 
using namespace std;
 
const int maxn = 1005;
 
int n, q, k;
vector<vector<int> > insect, person;
 
bool Check(int x, int y) {
  for(int i = 1; i <= k; ++ i) {
    if(insect[x][i] > person[y][i]) return 0;
  }
  return 1;
}
 
namespace Sub2 {
 
  int T[maxn];
 
  void Update(int x) {
    for(; x <= 1000; x += x & -x) T[x] ++;
  }
 
  int Get(int x) {
    int res = 0;
    for(; x; x -= x & -x) res += T[x];
    return res;
  }
 
  void Solve() {
    memset(T, 0, sizeof T);
    for(int i = 1; i <= n; ++ i) Update(insect[i][1]);
    for(int i = 1; i <= q; ++ i) {
      cout << Get(person[i][1]) << "\n";
    }
  }
}
 
void Solve(int Test) {
  cin >> n >> q >> k;
  insect.resize(n + 1);
  for(int i = 1; i <= n; ++ i) {
    insect[i].resize(k + 1);
    for(int j = 1; j <= k; ++ j) cin >> insect[i][j];
  }
  person.resize(q + 1);
  for(int i = 1; i <= q; ++ i) {
    person[i].resize(k + 1);
    for(int j = 1; j <= k; ++ j) cin >> person[i][j];
  }
  if(k == 1) {
    Sub2::Solve();
    return;
  }
  for(int i = 1; i <= q; ++ i) {
    int res = 0;
    for(int j = 1; j <= n; ++ j) res += Check(j, i);
    cout << res << "\n";
  }
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