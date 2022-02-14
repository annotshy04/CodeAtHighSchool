// annotshy

#include <bits/stdc++.h>

#define Task "CF"
#define pb push_back

using namespace std;

const int maxn = 200005;

int n, len, x, posa, posb, posc;
string s;
bool ok[10][10][10][10], cur[10][10][10][10];
int nex[10001][10], last[10];

void Solve(int Test) {
	cin >> n;
	for(int t = 1; t <= n; ++ t) {
		cin >> len >> s;
		s = " " + s;
		memset(cur, 0, sizeof cur);
		memset(last, -1, sizeof last);
		for(int i = len; i >= 1; -- i) {
			int x = s[i] - '0';
			last[x] = i;
			for(int j = 0; j <= 9; ++ j) nex[i][j] = last[j];
		}
		for(int a = 0; a <= 9; ++ a) {
			posa = nex[1][a];
			if(posa == -1) continue;
			for(int b = 0; b <= 9; ++ b) {
				posb = nex[posa][b];
				if(posb == -1) continue;
				for(int c = 0; c <= 9; ++ c) {
					posc = nex[posb][c];
					if(posc == -1) continue;
					for(int d = 0; d <= 9; ++ d) {
						if(nex[posc][d] == -1) continue;
						cur[a][b][c][d] = 1;
					}
				}
			}
		}
		for(int a = 0; a <= 9; ++ a) {
			for(int b = 0; b <= 9; ++ b) {
				for(int c = 0; c <= 9; ++ c) {
					for(int d = 0; d <= 9; ++ d) {
            if(t == 1) ok[a][b][c][d] = cur[a][b][c][d];
            else ok[a][b][c][d] &= cur[a][b][c][d];
					}
				}
			}
		}
	}
	int res = 0;
	for(int a = 0; a <= 9; ++ a) {
		for(int b = 0; b <= 9; ++ b) {
			for(int c = 0; c <= 9; ++ c) {
				for(int d = 0; d <= 9; ++ d) res += ok[a][b][c][d];
			}
		}
	}
	cout << res << "\n";
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  if(fopen(Task".inp", "r")) {
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
  }
  int test = 1;
  // cin >> test;
  for(int i = 1; i <= test; ++ i) {
    Solve(i);
  }
}

/*no pain no gain*/
