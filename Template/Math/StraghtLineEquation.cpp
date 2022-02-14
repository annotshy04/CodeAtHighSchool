#include <bits/stdc++.h>
#define F first
#define S second
#define MOD 1000000007
#define pb push_back
#define ll long long
#define db double
#define Task "BTS"

using namespace std;

const int maxn = 100005;

int n;
pair<int, int> a[maxn], be, en;
double A, B, C;

void Make_Seg(pair<ll, ll> a, pair<ll, ll> b) {
    pair<ll, ll> u = {b.F - a.F, b.S - a.S};
    A = u.S, B = - u.F, C = 1ll * u.F * a.S - 1ll * u.S * a.F;	
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
	if(fopen(Task".inp", "r")){
		freopen(Task".inp", "r", stdin);
		freopen(Task".out", "w", stdout);
	}
    cin >> n;
    for(int i = 1; i <= n; ++ i) cin >> a[i].F >> a[i].S;
    cin >> be.F >> be.S >> en.F >> en.S;
    Make_Seg(be, en);
}

// CHY-AKAV
