#include <bits/stdc++.h>
#define F first
#define S second
#define MOD 1000000007
#define pb push_back
#define bit(x,p) ((x>>p) & 1)
#define ll long long
#define pi acos(-1)
#define pii pair<int,int>
#define Task "CF"
using namespace std;

const int base = 100003;
const int maxn = 105;

string s;

long long Mul(long long a,long long b,long long mod) {
    long long c = 0;
    for(;b;b /= 2, a = (a + a) % mod) {
        if(b % 2) c = (c + a) % mod;
    }
    return c;
}

long long Mu(long long a,long long b,long long mod) {
    long long c = 1;
    for(;b;b /= 2, a = Mul(a,a,mod)) {
        if(b % 2) c = Mul(c,a,mod);
    }
    return c;
}

bool Check(long long n){
	if(n < 2) return 0;
	for(long long i = 2; i * i * i <= n; ++i)
        if(n % i == 0) return 0;
	for(int it = 0; it < 1e3; ++it){
		long long i = rand() % (n - 1) + 1;
		if(__gcd(i, n) != 1) return 0;
		if(Mu(i, n - 1, n) != 1) return 0;
	}
	return 1;
}

void Solve(){
    cin >> s;
    int n = s.length();
    s = " " + s;
    for(int i = 1; i <= n; ++i) {
        if(s[i] == '3' || s[i] == '4' || s[i] == '7'){
            cout << "no" << "\n";
            return;
        }
    }
    long long num = 0,num1 = 0;
    for(int i = 1; i <= n; ++i) {
        num1 = num1 * 10 + (s[i] - '0');
    }
    for(int i = n; i >= 1; --i) {
        if(s[i] == '6') num = num * 10 + 9;
        else if(s[i] == '9') num = num * 10 + 6;
        else num = num * 10 + (s[i] - '0');
    }
    if(Check(num) && Check(num1)) cout << "yes" << "\n";
    else cout << "no" << "\n";
}

void NumTime(){
    cerr << "Toi Di Chep Code" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
	if(fopen(Task".inp","r")){
		freopen(Task".inp","r",stdin);
		freopen(Task".out","w",stdout);
	}
    int test = 1;
//    cin >> test;
    NumTime();
    while(test --){
        Solve();
    }
}

