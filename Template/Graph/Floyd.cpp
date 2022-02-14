#include <bits/stdc++.h>
#define FOR(i,x,y) for(int i = x; i <= y ; ++i)
#define FORN(i,x,y) for(int i = x; i >= y ; --i)
#define F first
#define S second
#define maxn 10005
#define maxc 1e9
#define mp make_pair
#define pb push_back
#define ll long long
#define Task "minpath"
using namespace std;
int n,m,s,t,d[maxn][maxn],tr[maxn][maxn],luu[maxn];

void Floyd()
{
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            tr[i][j] = j;
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
    {
        if(d[i][j] > d[i][k] + d[k][j])
        {
            d[i][j] = d[i][k] + d[k][j];
            tr[i][j] = tr[i][k];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        d[i][i] = 0;
        for(int j = 1; j <= n; j++)
            d[i][j] = 1e9;
    }
    for(int i = 1; i <= m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
    }
    Floyd();
    cout << d[s][t] << "\n";
    int u = s;
    int dem = 0;
    while(u != t)
    {
        luu[++dem] = u;
        u = tr[u][t];
    }
    luu[++dem] = t;
    cout << dem << "\n";
    for(int i = 1;i <= dem;i++)
        cout << luu[i] << " ";

}
