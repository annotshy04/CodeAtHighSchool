#include <bits/stdc++.h>
#define F first
#define S second
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define bit(x,p) ((x>>p) & 1)
#define Task "maxflow"
using namespace std;

typedef long long ll;

const int base = 100003;
const long long MM = 1ll*MOD*MOD;
const int maxc = 2e9;
const int maxn = 1005;

int n,m,s,t;
int c[maxn][maxn],f[maxn][maxn],tr[maxn],maxflow;

void DFS(int u){
    for(int v = 1;v <= n;++v){
        if(!tr[v] && c[u][v] > f[u][v]){
            tr[v] = u;
            DFS(v);
        }
    }
}

void BFS(){
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int v = 1;v <= n;++v)
            if(!tr[v] && c[u][v] > f[u][v]){
                tr[v] = u;
                Q.push(v);
            }
    }
}

bool FindP(){
    memset(tr,0,sizeof(tr));
    tr[s] = -1;
    // DFS(s);
    BFS();
    return (tr[t]);
}

void IncFlow(){
    int v = t;
    int delta = 2e9;
    while(v != s){
        int u = tr[v];
        delta = min(delta,c[u][v] - f[u][v]);
        v = u;
    }
    v = t;
    while(v != s){
        int u = tr[v];
        f[v][u] -= delta;
        f[u][v] += delta;
        v = u;
    }
    maxflow += delta;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
	if(fopen(Task".inp","r")){
		freopen(Task".inp","r",stdin);
		freopen(Task".out","w",stdout);
	}
    cin >> n >> m >> s >> t;
    for(int i = 1;i <= m;++i){
        int u,v,w;
        cin >> u >> v >> w;
        c[u][v] = w;
    }
    while(FindP()){
        IncFlow();
    }
    cout << maxflow;
}
