#include<bits/stdc++.h>

#define Task "BIENDOI"
#define pb push_back

using namespace std;

const int maxn = 200005;

int n, m, q;
int t[maxn], x[maxn], y[maxn], ans[maxn];
vector<int> adj[maxn];
int a[1005][1005], res = 0;

void change(int &x, int val) {
	res -= x;
	x = val;
	res += x;
}

void DFS(int u) {
	ans[u] = res;
	for(auto v : adj[u]) {
		int save = 0;
		if(t[v] == 1) {
			save = a[x[v]][y[v]];
			change(a[x[v]][y[v]], 1);
		}
		if(t[v] == 2) {
			save = a[x[v]][y[v]];
			change(a[x[v]][y[v]], 0);
		}
		if(t[v] == 3) {
			for(int i = 1; i <= m; ++ i) {
				change(a[x[v]][i], a[x[v]][i] ^ 1);
			}
		}
		DFS(v);
		if(t[v] == 1 || t[v] == 2) {
			change(a[x[v]][y[v]], save);
		}
		if(t[v] == 3) {
			for(int i = 1; i <= m; ++ i) {
				change(a[x[v]][i], a[x[v]][i] ^ 1);
			}	
		}
	}
}

void Solve(int Test) {
	cin >> n >> m >> q;
	for(int i = 1; i <= q; ++ i) {
		cin >> t[i];
		if(t[i] <= 2) cin >> x[i] >> y[i];
		else cin >> x[i];
		if(t[i] <= 3) {
			adj[i - 1].pb(i);
		} else {
			adj[x[i]].pb(i);
		}
	}
	DFS(0);
	for(int i = 1; i <= q; ++ i) {
		cout << ans[i] << "\n";
	}
}


signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
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
