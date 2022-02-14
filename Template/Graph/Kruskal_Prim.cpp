#include <bits/stdc++.h>
#define FOR(i,x,y) for(int i = x; i <= y ; ++i)
#define FORN(i,x,y) for(int i = x; i >= y ; --i)
#define F first
#define S second
#define maxn 30005
#define mp make_pair
#define pb push_back
#define ll long long
#define Task "mintree"
using namespace std;
//Kruskal
struct data
{
    int u, v, w;
};

int n,m,root[30005];
long long dem;
data a[100005];
vector <data> kq;

int get_root(int x)
{
    if(root[x] == 0) return x;
    root[x] = get_root(root[x]);
    return root[x];
}
bool comp(data p,data q)
{
    return p.w < q.w;
}
void Kruskal()
{
    sort(a + 1,a + m + 1,comp);
    memset(root,0,sizeof(root));
    dem = 0;
    for(int i = 1;i <= m;i++)
    {
        int p = get_root(a[i].u);
        int q = get_root(a[i].v);
        if(p != q)
        {
            root[p] = q;
            dem += a[i].w;
            kq.pb(a[i]);
        }
    }
    cout << dem << "\n";
    for(int i = 0;i < n - 1;i++)
        cout << kq[i].u << " " << kq[i].v << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= m;i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    Kruskal();
    return 0;
}
