#include <bits/stdc++.h>
#define FORX(i,x,y) for(int i = x; i <= y ; ++i)
#define FORN(i,x,y) for(int i = x; i >= y ; --i)
#define reset(x,y) memset(x,y,sizeof(x))
#define bp(i) (1 << i)
#define F first
#define S second
#define maxn 20000005
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit1(x) __builtin_popcount(x)
#define bit(x,p) ((x>>p) & 1)
#define Task "ant"
using namespace std;

typedef long long ll; typedef long double ld; typedef double db;
typedef string str;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; typedef pair<db,db> pdd;
typedef vector<int> vi; typedef vector<ll> vll; typedef vector<db> vdb; typedef vector<str> vstr; typedef vector<pii> vpii; typedef vector<pll> vpll; typedef vector<pdd> vpdb;

const int base = 100003;
const long long MM = 1ll*MOD*MOD;
const int maxc = 2e9;

//int random(int l, int r) {
//    long long x = 1ll * rand() * rand() * rand() + 1ll * rand() * rand() + rand();
//    return int(x % (r - l + 1) + l);
//}
int n,m;
ll dem = 0,P[maxn],inv[maxn];
ll Mu(ll a,ll b){
    ll c = 1;
    for(;b ;b /= 2,a = a * a % MOD)
        if(b % 2) c = c * a % MOD;
    return c;
}

void Prepare(){
    P[0] = 1;
    for(int i = 1;i <= 20000000;++i) P[i] = (P[i - 1] * (ll)i) % MOD;
    inv[10000000] = Mu(P[10000000],MOD - 2);
    for(int i = 9999999;i >= 0;--i) inv[i] = (inv[i + 1] * (ll)(i + 1)) % MOD;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
	if(fopen(Task".inp","r")){
		freopen(Task".inp","r",stdin);
		freopen(Task".out","w",stdout);
	}
	cin >> n >> m;
    Prepare();
	for(int A = 0;A <= m;++A){
        int C = m - A;
        int B = n - C;
        if(B < 0 || C < 0) continue;
        ll pos = P[A + B + C] % MOD;
        pos = (pos * inv[A]) % MOD;
        pos = (pos * inv[B]) % MOD;
        pos = (pos * inv[C]) % MOD;
        dem = (dem + pos) % MOD;
	}
	cout << dem;
}
