// annotshy

/*
	source: DSUR - thay Thuan HUST
*/

#include <bits/stdc++.h>

#define Task "CF"
#define pb push_back

using namespace std;

const int maxn = 100005;

struct query {
	int t, u, v;
} Q[maxn];

struct event {
	int u, v;
	bool united;
};

struct dsu_save {
	int u, szu, v, szv;
	dsu_save() {}
	dsu_save(int _u, int _szu, int _v, int _szv) : u(_u), szu(_szu), v(_v), szv(_szv) {}
};

struct dsu_rollback {

	vector<int> p, sz;
	stack<dsu_save> st;

	dsu_rollback() {}

	void reset(int n) {
		p.resize(n + 1);
		sz.resize(n + 1);
		for(int i = 1; i <= n; ++ i) p[i] = i, sz[i] = 1;
	}

	int root(int u) {
		return (p[u] == u) ? p[u] : root(p[u]);
	}

	bool unite(int u, int v) {
		u = root(u);
		v = root(v);
		if(u == v) return 0;
		if(sz[u] > sz[v]) swap(u, v);
		st.push({u, sz[u], v, sz[v]});
		p[u] = v;
		sz[v] += sz[u];
		return 1;
	}

	void rollback() {
		if(st.empty()) return;
		dsu_save x = st.top();
		st.pop();
		p[x.u] = x.u;
		p[x.v] = x.v;
		sz[x.u] = x.szu;
		sz[x.v] = x.szv;
	}
} mydsu;

int n, q, ans[maxn];
map<pair<int, int>, int> M;
vector<event> E[maxn * 4];

void Add(int node, int l, int r, int u, int v, int s, int t) {
	if(l > v || r < u) return;
	if(l >= u && r <= v) {
		E[node].pb({s, t, 0});
		return;
	}
	int mid = (l + r) >> 1;
	Add(node * 2, l, mid, u, v, s, t);
	Add(node * 2 + 1, mid + 1, r, u, v, s, t);
}

void DFS(int node, int l, int r) {
	for(auto &q : E[node]) {
		q.united = mydsu.unite(q.u, q.v);
	}
	if(l == r) {
		if(Q[l].t == 3)
      ans[l] = (mydsu.root(Q[l].u) == mydsu.root(Q[l].v));
	} else {
    int mid = (l + r) >> 1;
    DFS(node * 2, l, mid);
    DFS(node * 2 + 1, mid + 1, r);
	}
	for(auto q : E[node]) {
		if(q.united) {
			mydsu.rollback();
		}
	}
}

void Solve(int Test) {
  cin >> n >> q;
  mydsu.reset(n);
  for(int i = 1; i <= q; ++ i) {
  	int t, u, v; cin >> t >> u >> v;
  	if(u > v) swap(u, v);
  	if(t == 1) {
  		if(M[{u, v}] == 0) {
        M[{u, v}] = i;
  		}
  	} else if(t == 2) {
  		if(M[{u, v}])
        Add(1, 1, q, M[{u, v}], i - 1, u, v);
  		M[{u, v}] = 0;
  	}
  	Q[i] = {t, u, v};
  }
  for(int i = 1; i <= q; ++ i) {
    int t = Q[i].t, u = Q[i].u, v = Q[i].v;
    if(t > 1) continue;
    if(M[{u, v}] == i) {
      Add(1, 1, q, i, q, u, v);
    }
  }
  DFS(1, 1, q);
	for(int i = 1; i <= q; ++ i) {
		if(Q[i].t == 3) {
			if(ans[i]) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
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
  // cin >> test;
  for(int i = 1; i <= test; ++ i) {
    Solve(i);
  }
}

/*no pain no gain*/
