#include <bits/stdc++.h>
#define F first
#define S second
#define MOD 1000000007
#define pb push_back
#define bit(x,p) ((x>>p) & 1)
#define Task "ASSIGN"
using namespace std;

const int base = 100003;
const int maxn = 100005;

int n,m,Match[maxn],used[maxn];
vector<int> ke[maxn];
int tt; // thu tu duyet

bool DFS(int u){
    if(used[u] == tt) return 0;
    used[u] = tt;
    for(auto v : ke[u]){
        if(Match[v] == 0 || DFS(Match[v])){
            Match[v] = u;
            return 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
	if(fopen(Task".inp","r")){
		freopen(Task".inp","r",stdin);
		freopen(Task".out","w",stdout);
	}
    cin >> m >> n;
    int u,v,ans = 0;
    while(cin >> u >> v) ke[u].pb(v);
    int a[maxn];
    for(int i = 1;i <= m;++i) a[i] = i;
    random_shuffle(a + 1,a + m + 1);
    for(int i = 1;i <= m;++i){
        tt = a[i];
        ans += DFS(tt);
    }
    cout << ans << "\n";
    for(int i = 1;i <= n;++i) cout << Match[i] << " ";
}
