// V T An
#include <bits/stdc++.h>
#define Task "BOSSES"
#define pb push_back
#define F first
#define S second
 
using namespace std;
 
const int maxn = 50005;
 
int n;
vector<int> a[maxn], ke[maxn];
int dd[maxn];
int ans = 2e9, f[maxn], total;
 
void BFS(int s) {
    queue<int> Q;
    Q.push(s);
    f[s] = 1;
    int ver = 0;
    while(Q.size()) {
        ++ ver;
        int u = Q.front();
        Q.pop();
        total += f[u];
        for(auto v : a[u]) {
            if(!f[v]) {
                f[v] = f[u] + 1;
                ke[u].pb(v);
                Q.push(v);
            }
        }
    }
    if(ver != n) total = 2e9;
}
 
void Solve(int u) {
    for(int i = 1; i <= n; ++ i) ke[i].clear(), f[i] = dd[i] = 0;
    BFS(u);
    total = 0;
    for(int i = 1; i <= n; ++ i) {
        if(!f[i]) return;
        total += f[i];
    }
    ans = min(ans, total);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; ++ i) {
        int k; cin >> k;
        while(k --) {
            int x; cin >> x;
            a[x].pb(i);
        }
    }
 
    for(int i = 1; i <= n; ++ i) {
        Solve(i);
    }
 
    cout << ans;
}
 
// CHY-AKAV