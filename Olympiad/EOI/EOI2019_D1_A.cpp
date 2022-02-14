// annotshy

#include <bits/stdc++.h>

#define Task "CF"
#define pb push_back
/*Task name: Equivalence Subarray*/

using namespace std;

const int maxn = 100005;

int n, k;
int a[maxn];
int cnt[maxn], occ[maxn], mx;

void Add(int x) {
  if(cnt[x]) occ[cnt[x]] --;
  cnt[x] ++;
  mx = max(mx, cnt[x]);
  occ[cnt[x]] ++;
}

void Rem(int x) {
  if(cnt[x]) occ[cnt[x]] --;
  cnt[x] --;
  if(cnt[x]) occ[cnt[x]] ++;
  while(!occ[mx]) -- mx;
}

bool Check(int len) {
  if(len <= k) return 1;
  mx = 0;
  for(int i = 1; i <= n; ++ i) cnt[i] = occ[i] = 0;
  for(int i = 1; i <= len; ++ i) {
    Add(a[i]);
  }
  if(mx >= len - k) return 1;
  for(int i = len + 1; i <= n; ++ i) {
    Add(a[i]);
    Rem(a[i - len]);
    if(mx >= len - k) return 1;
  }
  return 0;
}

void Solve(int Test) {
  cin >> n >> k;
  vector<int> v;
  for(int i = 1; i <= n; ++ i) cin >> a[i], v.pb(a[i]);
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  for(int i = 1; i <= n; ++ i) {
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
  }
  int l = 1, r = n + 1;
  while(r - l > 1) {
   int mid = (l + r) >> 1;
   if(Check(mid)) l = mid;
   else r = mid;
  }
  cout << l << "\n";
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
