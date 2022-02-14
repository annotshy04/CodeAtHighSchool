#include <bits/stdc++.h>
#define FOR(i,x,y) for(int i = x; i <= y ; ++i)
#define FORN(i,x,y) for(int i = x; i >= y ; --i)
#define F first
#define S second
#define maxn 100005
#define mp make_pair
#define pb push_back
#define ll long long
#define Task "sconnect"
using namespace std;
int n,m,low[maxn],num[maxn],s[maxn],dd[maxn];
int top = 0,cnt = 0,tplt = 0;
vector<int> a[maxn];
vector<int> res[maxn];
void Tarjan(int &u)
{
    low[u] = num[u] = ++cnt;
    s[++top] = u;
    for(int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i];
        if(dd[v])
            continue;
        if(num[v])
            low[u] = min(low[u],num[v]);
        else
        {
            Tarjan(v);
            low[u] = min(low[u],low[v]);
        }
    }
    if(low[u] == num[u])
    {
        tplt++;
        while(1)
        {
            int v = s[top--];
            res[tplt].pb(v);
            dd[v] = 1;
            if(v == u) break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        a[u].pb(v);
    }
    for(int i = 1;i <= n;i++)
        if(num[i] == 0) Tarjan(i);
    cout << tplt << "\n";
    for(int i = 1;i <= tplt;i++)
    {
        cout << res[i].size() << "\n";
        for(int v = 0;v < res[i].size();v++)
            cout << res[i][v] << " ";
        cout << "\n";
    }
}
