#include <bits/stdc++.h>

using namespace std;

#define in ({int x = 0; int c = getchar(), n = 0; for(; !isdigit(c); c = getchar()) n = (c == '-'); for(; isdigit(c); c = getchar()) x = x * 10 + c - '0'; n ? -x : x;})

#define forinc(a, b, c) for(int a = b, _c = c; a <= _c; ++a)
#define fordec(a, b, c) for(int a = b, _c = c; a >= _c; --a)
#define forv(a, b) for(auto &a : b)
#define reset(a, b) memset(a, b, sizeof a)
#define all(a) a.begin(), a.end()

#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define gg exit(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {
    return l + rng() % (r - l + 1);
}

const int N = 200010;

int n, cnt;
int a[N], sz[N], dd[N];
vector<int> ad[N];

void dfs1(int u, int p = 0) {
    sz[u] = 1;
    cnt++;
    forv(v, ad[u]) if(v != p && !dd[v])
        dfs1(v, u), sz[u] += sz[v];
}

int dfs2(int u, int p = 0) {
    forv(v, ad[u]) if(v != p && !dd[v] && sz[v] > cnt / 2)
        return dfs2(v, u);
    return u;
}

vector<pair<int, long long>> tmp, val;
vector<int> rev;
vector<long long> rrh;
long long ans;
int bit[N];

void upd(long long i) {
    i = lower_bound(all(rrh), i) - rrh.begin() + 1;
    for(; i; i -= i & -i) {
        bit[i]++;
        rev.pb(i);
    }
}

int que(long long i) {
    i = upper_bound(all(rrh), i) - rrh.begin() + 1;
    int ret = 0;
    for(; i <= rrh.size(); i += i & -i)
        ret += bit[i];
    return ret;
}

void dfs3(int u, int m, long long s, int p = 0) {
    m = max(m, a[u]);
    s += a[u];
    if(s > m + m)
        ans++;
    tmp.push_back({m, s});
    forv(v, ad[u]) if(v != p && !dd[v])
        dfs3(v, m, s, u);
}

void dfs(int u) {
    cnt = 0;
    dfs1(u);
    dd[u = dfs2(u)] = 1;

    forv(v, ad[u]) if(!dd[v]) {
        dfs3(v, a[u], a[u]);
        sort(all(tmp));
        forv(i, tmp) rrh.push_back(i.second);
        sort(all(rrh));
        rrh.erase(unique(all(rrh)), rrh.end());
        forv(i, tmp) {
            ans -= que(2ll * i.first - i.second + a[u]);
            upd(i.second);
        }
        rrh.clear();
        forv(i, rev) bit[i] = 0;
        rev.clear();
        val.insert(val.end(), all(tmp));
        tmp.clear();
    }
    sort(all(val));
    forv(i, val) rrh.push_back(i.second);
    sort(all(rrh));
    rrh.erase(unique(all(rrh)), rrh.end());
    forv(i, val) {
        ans += que(2ll * i.first - i.second + a[u]);
        upd(i.second);
    }
    val.clear();
    rrh.clear();
    forv(i, rev) bit[i] = 0;
    rev.clear();

    forv(v, ad[u]) if(!dd[v])
        dfs(v);
}

main() {
#define task "TREE"
    if(fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }


    n = in;
    forinc(i, 1, n) a[i] = in;
    forinc(i, 2, n) {
        int u = in, v = in;
        ad[u].pb(v);
        ad[v].pb(u);
    }

    dfs(1);

    cout << ans << "\n";

    ans = 0;
    rrh.clear();
    forinc(i, 1, n) ad[i].clear(), dd[i] = 0;


    return 0;
}
