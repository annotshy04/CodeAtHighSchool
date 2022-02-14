// annotshy

#include <bits/stdc++.h>

#define Task "CF"

using namespace std;

const int maxn = 200005;

int n, h[maxn];
long long dp[maxn], f[maxn][20];

/*
	dp[i] = min(dp[j] + h[i] + h[j] + (i - j + 1))
				= dp[j] + h[j] - j + 1 + (h[i] + i);
*/

long long lazy[maxn * 4], tree[maxn * 4];

void Build(int node, int l, int r) {
  lazy[node] = 1e18;
	if(l == r) {
		tree[node] = 1e18;
		return;
	}
	int mid = (l + r) >> 1;
	Build(node * 2, l, mid);
	Build(node * 2 + 1, mid + 1, r);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

void PushDown(int node, int l, int r) {
	if(l == r || lazy[node] == 1e18) return;
	tree[node * 2] = min(tree[node * 2], lazy[node]);
	lazy[node * 2] = min(lazy[node * 2], lazy[node]);
	tree[node * 2 + 1] = min(tree[node * 2 + 1], lazy[node]);
	lazy[node * 2 + 1] = min(lazy[node * 2 + 1], lazy[node]);
	lazy[node] = 1e18;
}

void Update(int node, int l, int r, int u, int v, long long val) {
	PushDown(node, l, r);
	if(l > v || r < u) return;
	if(l >= u && r <= v) {
		tree[node] = min(tree[node], val);
		lazy[node] = min(lazy[node], val);
		return;
	}
	int mid = (l + r) >> 1;
	Update(node * 2, l, mid, u, v, val);
	Update(node * 2 + 1, mid + 1, r, u, v, val);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

long long Get(int node, int l, int r, int id) {
	PushDown(node, l, r);
	if(l == r) return tree[node];
	int mid = (l + r) >> 1;
	if(id <= mid) return Get(node * 2, l, mid, id);
	return Get(node * 2 + 1, mid + 1, r, id);
}

long long Max(int l, int r) {
	int len = log2(r - l + 1);
	return max(f[l][len], f[r - (1 << len) + 1][len]);
}

void Solve(int Test) {
  cin >> n;
  for(int i = 1; i <= n; ++ i) cin >> h[i], dp[i] = 1e18;
  if(*max_element(h + 1, h + n + 1) == 1) {
  	cout << n + 2 << "\n";
  	return;
  }
  for(int i = 1; i <= n; ++ i) f[i][0] = h[i];
  for(int i = 1; i <= 17; ++ i) {
  	for(int u = 1; u + (1 << i) - 1 <= n; ++ u) {
  		f[u][i] = max(f[u][i - 1], f[u + (1 << (i - 1))][i - 1]);
  	}
  }
  Build(1, 1, n);
  dp[1] = 0;
  Update(1, 1, n, 1, 1, dp[1]);
  for(int i = 1; i <= n; ++ i) {
  	dp[i] = Get(1, 1, n, i);
  	if(i > 1) dp[i] += h[i] + i;
  	int l = i, r = n + 1;
  	while(r - l > 1) {
  		int mid = (l + r) >> 1;
  		if(Max(i, mid) <= h[i]) l = mid;
  		else r = mid;
  	}
  	l = min(l + 1, n);
  	Update(1, 1, n, i + 1, l, dp[i] + h[i] - i + 1);
  }
  // for(int i = 2; i <= n; ++ i) {
  // 	int mx = 0;
  // 	for(int j = i - 1; j >= 1; -- j) {
  // 		if(h[j] >= mx) dp[i] = min(dp[i], dp[j] + h[j] - j + 1 + (h[i] + i));
  // 		mx = max(mx, h[j]);
  // 	}
  // }
  cout << dp[n] << "\n";
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
