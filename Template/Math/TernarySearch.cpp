#include <bits/stdc++.h>
#define FORX(i,x,y) for(int i = x; i <= y ; ++i)
#define FORN(i,x,y) for(int i = x; i >= y ; --i)
#define reset(x,y) memset(x,y,sizeof(x))
#define bp(i) (1 << i)
#define F first
#define S second
#define maxn 100005
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define bit(p,x) ((x>>p) & 1)
#define Task "circle"
using namespace std;

typedef long long ll; typedef long double ld; typedef double db;
typedef string str;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; typedef pair<db,db> pdd;
typedef vector<int> vi; typedef vector<ll> vll; typedef vector<db> vdb; typedef vector<str> vstr; typedef vector<pii> vpii; typedef vector<pll> vpll; typedef vector<pdd> vpdb;

const int base = 100003;
const long long MM = 1ll*MOD*MOD;
const int maxc = 2e9;
int n;
pdd a[maxn];

db Cal(double x){
    double Y = 0;
    for(int i = 1;i <= n;i++)
        Y = max(Y,((x - a[i].F) * (x - a[i].F) + (double)a[i].S * a[i].S)/ (2*a[i].S));
    return Y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].F >> a[i].S;
    db L = -1e9,R = 1e9;
    for(int i = 1;i <= 100;i++){
        db M1 = L + (R - L) / 3;
        db M2 = R - (R - L) / 3;
        if(Cal(M1) < Cal(M2)) R = M2;
        else L = M1;
    }
    cout << fixed << setprecision(3) << Cal(L) << "\n";
}
