// annotshy

/*
  Problem: FLOOR - VOI Training
*/

#include <bits/stdc++.h>
#define F first
#define S second
#define MOD 1000000007
#define pb push_back
#define ll long long
#define Task "FLOOR"

using namespace std;

const int maxn = 1005;

int m, n;
int a[maxn][maxn];

namespace Full {
    int f[12][12][maxn][maxn], w, h;
    long long s[maxn][maxn], ans;

    void Max(int &x, int y) {
        x = max(x, y);
    }

    void RMQ_2D() {
        for(int u = 0; u < 11; ++u) {
            for(int v = 0; v < 11; ++v) {
                if(v == 0 && u == 0) continue;
                for(int i = 1; i + (1 << u) - 1 <= m; ++i) {
                    for(int j = 1; j + (1 << v) - 1 <= n; ++j) {
                        if(u) {
                            Max(f[u][v][i][j], f[u - 1][v][i][j]);
                            Max(f[u][v][i][j], f[u - 1][v][i + (1 << (u - 1))][j]);
                        }
                        if(v) {
                            Max(f[u][v][i][j], f[u][v - 1][i][j]);
                            Max(f[u][v][i][j], f[u][v - 1][i][j + (1 << (v - 1))]);
                        }
                        if(u && v) {
                            Max(f[u][v][i][j], f[u - 1][v - 1][i][j]);
                            Max(f[u][v][i][j], f[u - 1][v - 1][i + (1 << (u - 1))][j + (1 << (v - 1))]);
                        }
                    }
                }
            }
        }
    }

    void PreSum() {
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j)
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }

    int Get_Max(int x, int y, int u, int v) {
        int len1 = log2(u - x + 1);
        int len2 = log2(v - y + 1);
        int res = 0;
        Max(res, f[len1][len2][x][y]);
        Max(res, f[len1][len2][u - (1 << len1) + 1][v - (1 << len2) + 1]);
        Max(res, f[len1][len2][x][v - (1 << len2) + 1]);
        Max(res, f[len1][len2][u - (1 << len1) + 1][y]);
        return res;
    }

    long long Get_Sum(int x, int y, int u, int v) {
        return s[u][v] - s[u][y - 1] - s[x - 1][v] + s[x - 1][y - 1];
    }

    void Cal(int x, int y) {
        int mx = Get_Max(x, y, x + w - 1, y + h - 1);
        long long sum = Get_Sum(x, y, x + w - 1, y + h - 1);
        ans = min(ans, 1ll * mx * w * h - sum);
    }

    void Solve() {
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                f[0][0][i][j] = a[i][j];
            }
        }
        RMQ_2D();
        PreSum();
        int q; cin >> q;
        while(q --) {
            cin >> w >> h;
            ans = 1e12;
            for(int i = 1; i <= m - w + 1; ++i)
                for(int j = 1; j <= n - h + 1; ++ j) Cal(i, j);
            cout << ans << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
	if(fopen(Task".inp", "r")){
		freopen(Task".inp", "r", stdin);
		freopen(Task".out", "w", stdout);
	}
    cin >> m >> n;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j) cin >> a[i][j];
    if(n <= 50 && m <= 50) {
        Sub1::Solve();
        return 0;
    }
    Full::Solve();
}

// CHY_AKAV
