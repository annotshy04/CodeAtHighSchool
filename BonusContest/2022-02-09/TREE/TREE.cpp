#include<bits/stdc++.h>

#define Task "TREE"
#define pb push_back

using namespace std;

const int maxn = 200005;

int n, a[maxn];
vector<int> adj[maxn];

namespace Sub1 {

	int res = 0;

	void DFS(int u, int s, long long S, int M, int p = -1) {
		if(2 * M < S && u > s) ++ res;
		for(auto v : adj[u]) {
			if(v == p) continue;
			DFS(v, s, S + a[v], max(M, a[v]), u);
		}
	}

	void Solve() {
		for(int i = 1; i <= n; ++ i) {
			DFS(i, i, 1ll * a[i], a[i]);
		}
		cout << res << "\n";
	}
} // Sub1


namespace Sub2 {

	int child[maxn];
	long long res = 0;

	void DFS(int u, int p = -1) {
		child[u] = 1;
		int delta = 0;
		for(auto v : adj[u]) {
			if(v == p) continue;
			DFS(v, u);
			child[u] += child[v];
			res += child[v] - 1;
			res += 1ll * child[v] * delta;
			delta += child[v];
		}
	}

	void Solve() {
		DFS(1);
		cout << res << "\n";
	}
}
void Solve(int Test) {
	cin >> n;
	for(int i = 1; i <= n; ++ i) cin >> a[i];
	for(int i = 1; i < n; ++ i) {
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	if(n <= 1000) {
		Sub1::Solve();
		return;
	}
	if(*max_element(a + 1, a + n + 1) == 1) {
		Sub2::Solve();
		return;
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
