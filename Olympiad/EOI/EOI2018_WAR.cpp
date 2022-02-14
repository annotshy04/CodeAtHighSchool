// annotshy

#include <bits/stdc++.h>

#define Task "CF"

using namespace std;

const int maxn = 200005;

int n, A, W;
struct PERSON {
	int w, a, id;
} person[maxn];

bool cmp1(PERSON p, PERSON q) {
	return p.w - p.a > q.w - q.a;
}

void Solve(int Test) {
  cin >> n >> W >> A;
  for(int i = 1; i <= n; ++ i) {
  	int w, a; cin >> w >> a;
  	person[i] = {w, a, i};
  }
  sort(person + 1, person + n + 1, cmp1);
  long long ans = 0;
  for(int i = 1; i <= W; ++ i) {
  	ans += person[i].w;
  	vis[person[i].id] = 1;
  }
  for(int i = n; i >= n - A + 1; -- i) {
  	ans += person[i].a;
  	vis[person[i].id] = 1;
  }
  for(int i = W + 1; i <= n - A; ++ i) {
  	if(vis[person[i].id]) continue;
  	ans += max(person[i].w, person[i].a);
  }
  cout << ans << "\n";
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
