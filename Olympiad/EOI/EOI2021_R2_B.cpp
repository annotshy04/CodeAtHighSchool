// annotshy

#include <bits/stdc++.h>

#define Task "CF"
#define pb push_back
#define F first 
#define S second

/*
	Task: Oooor
*/

using namespace std;

const int maxn = 200005;

int n;
int par[maxn][20], w[maxn], h[maxn];
pair<int, int> point, ed[maxn];
vector<pair<int, int> > adj[maxn];
int ans = 0;

void DFS(int u) {
	for(auto p : adj[u]) {
		int v = p.F, c = p.S;
		if(v == par[u][0]) continue;
		par[v][0] = u;
		w[v] = c;
		for(int i = 1; i <= 18; ++ i) par[v][i] = par[par[v][i - 1]][i - 1];
		h[v] = h[u] + 1;
		DFS(v);
	}
}

int LCA(int u, int v) {
	if(h[v] > h[u]) swap(u, v);
	int delta = h[u] - h[v];
	for(int i = 18; i >= 0; -- i) {
		if(delta >> i & 1) u = par[u][i];
	}
	if(u == v) return u;
	for(int i = 18; i >= 0; -- i) {
		if(par[u][i] != par[v][i]) {
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}

int Get(int u, int cha) {
	int ans = 0;
	while(u != cha) {
		ans |= w[u];
		u = par[u][0];
	}
	return ans;
}

void Calc(int i, int j) {
	if(i == j) return;
	int cha = LCA(i, j);
	int res = Get(i, cha) | Get(j, cha);
	if(ans < res) {
		ans = res;
		point = {i, j};
	}
}

void Solve(int Test) {
  cin >> n;
  for(int i = 1; i <= n; ++ i) adj[i].clear();
  for(int i = 1; i < n; ++ i) {
  	int u, v; cin >> u >> v;
  	adj[u].pb({v, i});
  	adj[v].pb({u, i});
  	ed[i] = {u, v};
  }
  if(n == 2) {
  	cout << 1 << " " << 2 << "\n";
  	return;
  } 
  DFS(1);
  int idx = 1;
 	for(int i = 1; i <= n; ++ i) {
 		if((n | i) > (n | idx)) idx = i;
  }
  ans = 0;
  Calc(ed[n].F, ed[idx].F);
  Calc(ed[n].F, ed[idx].S);
  Calc(ed[n].S, ed[idx].F);
  Calc(ed[n].S, ed[idx].S);
  cout << point.F << " " << point.S << "\n";
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