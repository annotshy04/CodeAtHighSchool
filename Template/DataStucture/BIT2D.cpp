/*
  Problem: DISPLAY - VOI Training
*/

#include <bits/stdc++.h>
#define F first
#define S second
#define MOD 1000000007
#define pb push_back
#define ll long long
#define Task "DISPLAY"

using namespace std;

const int maxn = 1005;

int m, n, A, B, k;
int a[maxn][maxn], ans = 0;

namespace Full {

    int T[maxn][maxn], ans;

    void Update(int x, int y, int val) {
        for(; x; x -= x & -x)
            for(int z = y; z; z -= z & -z)
                T[x][z] += val;
    }

    int Get(int x, int y) {
        int res = 0;
        for(; x <= m; x += x & -x)
            for(int z = y; z <= n; z += z & -z) res += T[x][z];
        return res;
    }

    void Upd_Grid(int i, int j, int val) {
        Update(i + A - 1, j + B - 1, val);
        Update(i - 1, j + B - 1, - val);
        Update(i + A - 1, j - 1, - val);
        Update(i - 1, j - 1, val);
    }

    bool Check() {
        for(int i = 1; i <= m; ++ i) {
            for(int j = 1; j <= n; ++ j) {
                int val = a[i][j] + Get(i, j);
                if(val % k)
                    return 0;
            }
        }
        return 1;
    }

    void Solve() {
        for(int j = 1; j <= n - B + 1; ++ j) {
            for(int i = 1; i <= m - A + 1; ++ i) {
                int val = (a[i][j] + Get(i, j)) % k;
                if(val != 0) {
                    int time = k - val;
                    Upd_Grid(i, j, time);
                    ans += time;
                }
            }
        }
        if(!Check()) cout << "IMPOSSIBLE";
        else cout << ans;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
	if(fopen(Task".inp", "r")){
		freopen(Task".inp", "r", stdin);
		freopen(Task".out", "w", stdout);
	}
    cin >> m >> n >> A >> B >> k;
    for(int i = 1; i <= m; ++ i)
        for(int j = 1; j <= n; ++ j) cin >> a[i][j];
    Full::Solve();
    return 0;
}

// CHY_AKAV
