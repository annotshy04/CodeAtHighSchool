// V T An
#include <bits/stdc++.h>
#define Task "MINPATH"
#define pb push_back
#define F first
#define S second

using namespace std;

const int maxn = 100005;

int n, m, s, t;
vector<pair<int, int> > ke[maxn];
long long d[maxn];
int tr[maxn];

void DIJK(int s) {
    for(int i = 1; i <= n; ++ i) d[i] = 1e18;
    d[s] = 0;
    priority_queue<pair<long long, int> > PQ;
    PQ.push({-d[s], s});
    while(PQ.size()) {
        int u = PQ.top().S;
        long long l = -PQ.top().F;
        PQ.pop();
        if(l > d[u]) continue;
        for(auto p : ke[u]) {
            int v = p.F, w = p.S;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                tr[v] = u;
                PQ.push({-d[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
	if(fopen(Task".inp", "r")){
		freopen(Task".inp", "r", stdin);
		freopen(Task".out", "w", stdout);
	}
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; ++ i) {
        int u, v, w; cin >> u >> v >> w;
        ke[u].pb({v, w});
        ke[v].pb({u, w});
    }
    DIJK(s);
    cout << d[t] << "\n";
    vector<int> ans;
    while(t != s) {
        ans.pb(t);
        t = tr[t];
    }
    ans.pb(s);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " ";
}

// CHY-AKAV
