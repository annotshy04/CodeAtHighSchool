// V T AN
#include <bits/stdc++.h>
#define Task "center_node"
#define F first
#define S second
#define pb push_back

using namespace std;

const int maxn = 100005;

int n;
vector<pair<int, int> > ke[maxn];
long long d[maxn], mx, be, en;
int tr[maxn];

void DFS(int u) {
    for(auto p : ke[u]) {
        int v = p.F, w = p.S;
        if(tr[v]) continue;
        tr[v] = u;
        d[v] = max(d[v], d[u] + w);
        DFS(v);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
	if(fopen(Task".inp", "r")){
		freopen(Task".inp", "r", stdin);
		freopen(Task".out", "w", stdout);
	}
    cin >> n;
    for(int i = 1; i < n; ++ i) {
        int u, v, w;
        cin >> u >> v >> w;
        ke[u].pb({v, w});
        ke[v].pb({u, w});
    }
    tr[1] = -1;
    DFS(1);
    for(int i = 1; i <= n; ++ i) {
        if(d[i] > mx) mx = d[i], be = i;
    }
    memset(d, 0, sizeof d);
    memset(tr, 0, sizeof tr);
    tr[be] = -1;
    DFS(be);
    mx = 0;
    for(int i = 1; i <= n; ++ i) {
        if(d[i] > mx) mx = d[i], en = i;
    }
    long long res = 1e18;
    int u = en;
    while(u != be) {
        res = min({res, max(d[u], d[en] - d[u])});
        u = tr[u];
    }
    cout << res;
}

// CHY_AKAV
