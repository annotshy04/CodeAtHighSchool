#include <bits/stdc++.h>
#define F first
#define S second
#define MOD 1000000007
#define pb push_back
#define bit(x,p) ((x>>p) & 1)
#define Task "convex"
#define pii pair<long long,long long>
using namespace std;

const int base = 100003;
const int maxn = 200005;

int n;

struct data {
    long long x,y,id;
} a[maxn],st[maxn];

bool comp(data a,data b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

pii Vecto(data a,data b){
    return {b.x - a.x,b.y - a.y};
}

bool CCW(data a,data b,data c){
    pii u = Vecto(a,b);
    pii v = Vecto(b,c);
    return (u.F * v.S - u.S * v.F) > 0;
}

long long sqr(long long x){
    return x * x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
	if(fopen(Task".inp","r")){
		freopen(Task".inp","r",stdin);
		freopen(Task".out","w",stdout);
	}
    cin >> n;
    for(int i = 1;i <= n;++i) cin >> a[i].x >> a[i].y,a[i].id = i;
    sort(a + 1,a + n + 1,comp);
    st[1] = a[1];
    int top = 1;
    for(int i = 2;i <= n;++i){
        while(top > 1 && !CCW(st[top - 1],st[top],a[i])) top--;
        st[++top] = a[i];
    }
    int last = top;
    for(int i = n;i >= 1;--i){
        while(top > last && !CCW(st[top - 1],st[top],a[i])) top--;
        st[++top] = a[i];
    }
    --top;
    cout << top << "\n";
    double sum = 0;
    long long area = 0;
    for(int i = 1;i <= top;++i) cout << st[i].id << " ";
    cout << "\n";
    st[top + 1] = st[1];
    for(int i = 1;i <= top;++i){
        sum += 1.0 * sqrt(sqr(st[i].x - st[i + 1].x) + sqr(st[i].y - st[i + 1].y));
    }
    cout << fixed << setprecision(6) << abs(sum) << "\n";
    int dem = 0;
    for(int i = 1;i <= top;++i){
        long long pos = (st[i + 1].x - st[i].x) * (st[i].y + st[i + 1].y);
        area += pos / 2;
        if(pos % 2) dem ++;
    }
    area = abs(area);
    cout << area + dem / 2;
    if(dem % 2) cout << ".5";
    else cout << ".0";
}
