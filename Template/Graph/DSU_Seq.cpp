// V T An
#include <bits/stdc++.h>
#define F first
#define S second
#define MOD 1000000007
#define pb push_back
#define ll long long
#define Task "CRISIS"

using namespace std;

const int maxn = 200005;

int n, Q;
int root[maxn], Next[maxn];

int Get_Root(int u) {
    if(root[u] == u) return u;
    root[u] = Get_Root(root[u]);
    return root[u];
}

void Union(int u, int v) {
    int p = Get_Root(u);
    int q = Get_Root(v);
    if(p == q) return;
    root[p] = q;
}

int UnionSegment(int l, int r) {
    int u = Next[l];
    if(u >= r) return u;
    int v = u + 1;
    Union(u, v);
    return Next[l] = Next[u] = Next[v] = UnionSegment(v, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
	if(fopen(Task".inp", "r")){
		freopen(Task".inp", "r", stdin);
		freopen(Task".out", "w", stdout);
	}
    cin >> n >> Q;
    for(int i = 1; i <= n; ++ i) root[i] = Next[i] = i;
    while(Q --) {
        char t; cin >> t;
        int u, v; cin >> u >> v;
        if(t == '1') {
            Union(u, v);
        }
        if(t == '2') {
            UnionSegment(u, v);
        }
        if(t == '?') {
            int p = Get_Root(u);
            int q = Get_Root(v);
            if(p == q) cout << "yes" << "\n";
            else cout << "no" << "\n";
        }
    }
}

// CHY-AKAV
