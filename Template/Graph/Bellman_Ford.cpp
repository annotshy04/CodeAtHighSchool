#include <bits/stdc++.h>
#define FOR(i,x,y) for(int i = x; i <= y ; ++i)
#define FORN(i,x,y) for(int i = x; i >= y ; --i)
#define F first
#define S second
#define maxn 100005
#define maxc 1e9
#define mp make_pair
#define pb push_back
#define ll long long
#define Task "minpath"
using namespace std;
int n,m;
int d[100005];
int Trace[100005],dem = 0;
vector<pair<int,int> > a[maxn];

void Ford_Bellman()
{
    bool Stop;
    for(int CL = 1; CL <= n - 1; CL++)
	{
        Stop = 1;
        for(int u = 1; u <= n; u++)
        {
            for(int i = 0; i < a[u].size(); i++)
            {
                int v = a[u][i].F;
                if(d[v] > d[u] + a[u][i].S)
                {
                    d[v] = d[u] + a[u][i].S;
                    Trace[v] = u;
                    Stop = 0;
                }
            }
        }
        if(Stop)
            break;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        a[u].pb(mp(v,w));
        a[v].pb(mp(u,w));
    }
    Ford_Bellman();
//    cout << d[T] << endl;
    vector <int> res;
    int u = n;
    while (u != 1){
        res.pb(u);
        u = Trace[u];
    }
    res.pb(1);
    cout << res.size() << endl;
    for (int i = res.size()-1; i >= 0; i--) cout << res[i] << " ";
}
