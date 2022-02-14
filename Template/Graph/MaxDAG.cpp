#include <bits/stdc++.h>
#define FOR(i,x,y) for(int i = x; i <= y ; ++i)
#define FORN(i,x,y) for(int i = x; i >= y ; --i)
#define F first
#define S second
#define maxn 100005
#define mp make_pair
#define pb push_back
#define ll long long
#define Task "maxpdag"
using namespace std;
int n,m,bac[maxn],d[maxn],S[maxn];
vector<pair<int,int> > a[maxn];
void MAXDAG(){
    queue<int> Q;
    for(int i = 1;i <= n;++i){
        if(!bac[i]) Q.push(i);
    }
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(auto v : ke[u]){
            --bac[v.F];
            if(bac[v.F] == 0) Q.push(v.F);
            d[v.F] = max(d[v.F],d[u] + v.S);
        }
    }
    cout << *max_element(d + 1,d + n + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        a[u].pb(mp(v,w));
        bac[v] ++;
    }
    MAX_DAG();
    return 0;
}
