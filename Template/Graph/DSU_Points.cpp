/** VU TRUONG AN **/
#include <bits/stdc++.h>
#define FOR(i,x,y) for(int i = x; i <= y ; ++i)
#define FORN(i,x,y) for(int i = x; i >= y ; --i)
#define F first
#define S second
#define maxn 1005
#define mp make_pair
#define pb push_back
#define ll long long
#define Task "disjoint"
using namespace std;
int n,m,root[maxn];
int get_root(int x)
{
    if (root[x] == 0) return x;
    root[x] = get_root(root[x]);
    return root[x];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin >> n >> m;
    while(m--)
    {
        int a,u,v;
        cin >> a >> u >> v;
        int q = get_root(u);
        int p = get_root(v);
        if(a == 1)
            if(p != q) root[p] = q;
        if(a == 2)
        {
            if(p == q) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}
