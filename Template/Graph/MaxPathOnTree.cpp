// V T AN
#include <bits/stdc++.h>
#define Task "longest_path"
#define F first
#define S second
#define pb push_back

using namespace std;

const int maxn = 100005;

int n;
vector<pair<int, int> > ke[maxn];
int d[maxn], mx, pos;

void DFS(int u, int par) {
    for(auto p : ke[u]) {
        int v = p.F, w = p.S;
        if(d[v] < d[u] + w && v != par) {
            d[v] = d[u] + w;
            DFS(v, u);
        }
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
    DFS(1, 1);
    for(int i = 1; i <= n; ++ i) {
        if(d[i] > mx) mx = d[i], pos = i;
    }
    memset(d, 0, sizeof d);
    DFS(pos, pos);
    cout << *max_element(d + 1, d + n + 1);
}

// CHY_AKAV
