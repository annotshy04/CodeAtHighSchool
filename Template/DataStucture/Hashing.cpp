/*
  Problem: FOUNGSTRING - Dai Ca Di Hoc
*/

#include <bits/stdc++.h>
#define maxn 1000005
#define mp make_pair
#define pb push_back
#define ll long long
#define MOD 1000000007
#define Task "foundstring"
using namespace std;
string A,B;
const int base = 101;
int n,m,ans[maxn];
long long T[maxn],P[maxn];
ll Get_hash(int L,int R)
{
    int len = R - L + 1;
    return (T[R] - T[L-1] * P[len] + 1ll*MOD*MOD) % MOD;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin >> A >> B;
    n = A.length();
    m = B.length();
    A = " " + A;
    B = " " + B;
    P[0] = 1;
    for(int i = 1;i <= m;i++)
        P[i] = (P[i-1] * base) % MOD;
    ll sa = 0;
    for(int i = 1;i <= n;i++)
        sa = (sa * base + A[i]) % MOD;
    T[0] = 0;
    for(int i = 1;i <= m;i++)
        T[i] = (T[i-1] * base + B[i]) % MOD;
    int dem = 0;
    for(int r = n;r <= m;r++)
    {
        int l = r - n + 1;
        if(Get_hash(l,r) == sa) ans[++dem] = l;
    }
    cout << dem << "\n";
    for(int i = 1;i <= dem;i++) cout << ans[i] << " ";
}
