#include<bits/stdc++.h>

#define Task "CF"

using namespace std;

const int maxn = 200005;

string s;
int k, c[maxn], n;

bool OnlyDot() {
	for(int i = 0; i < n; ++ i) if(s[i] != '.') return 0;
	return 1;
}

bool OnlyDotAndShift() {
	for(int i = 0; i < n; ++ i) if(s[i] != '.' && s[i] != '_') return 0;
	return 1;
}

namespace Sub2 {

	bool ok[25][2];

	bool Check(string s) {
		vector<int> ans;
		int cnt = 0;
		for(int i = 0; i < n; ++ i) {
			if(s[i] == 'X') cnt ++;
			else {
				if(cnt) ans.push_back(cnt);
				cnt = 0;
			}
		}
		if(cnt) ans.push_back(cnt);
		if((int) ans.size() != k) return 0;
		for(int i = 0; i < k; ++ i) {
			if(ans[i] != c[i + 1]) return 0;
		}
		return 1;
	}

	void Solve() {
		for(int mask = 0; mask < (1 << n); ++ mask) {
			string cur = "";
			for(int i = 0; i < n; ++ i) {
				if(mask >> i & 1) cur += '_';
				else cur += 'X';
			}
			if(!Check(cur)) continue;
			for(int i = 0; i < n; ++ i) {
				if(mask >> i & 1) ok[i][0] = 1;
				else ok[i][1] = 1;
			}
		}
		for(int i = 0; i < n; ++ i) {
			if(ok[i][0] && ok[i][1]) cout << '?';
			else if(ok[i][0]) cout << '_';
			else cout << 'X';
		}
	}
}

namespace Sub3 {

	bool know[maxn];

	void Solve() {
		int run = 1, cnt = 0;
		string cur = s;
		for(int i = 0; i < n; ++ i) {
			if(cnt == c[run] || run > k) cur[i] = '_', run ++, cnt = 0;
			else cur[i] = 'X', cnt ++;
		}
		if(cur[0] == 'X' && cur[n - 1] == 'X') {
			cout << cur << "\n";
			return;
		}
		for(int i = 1; i <= n; ++ i) {
			int l = 0, r = n - 1;
			for(int j = 1; j < i; ++ j) {
				for(int x = 1; x <= c[j]; ++ x) l ++;
				l ++;
			}
			for(int j = k; j > i; -- j) {
				for(int x = 1; x <= c[j]; ++ x) r --;
				r --;
			}
			if(l + c[i] - 1 >= r - c[i] + 1) {
				for(int x = r - c[i] + 1; x <= l + c[i] - 1; ++ x) know[x] = 1;
			}
		}
		for(int i = 0; i < n; ++ i) {
			if(know[i]) cout << "X";
			else cout << "?";
		}
		cout << "\n";
	}
}

namespace Sub4 {

	int nex[maxn], pre[maxn];
	int meet[maxn], know[maxn];

	void Solve() {
		nex[n] = 0;
		for(int i = n - 1; i >= 0; -- i) {
			if(s[i] == '_') nex[i] = 0;
			else nex[i] = nex[i + 1] + 1;
		}
		for(int i = 0; i < n; ++ i) {
			if(s[i] == '_') pre[i] = 0;
			else pre[i] = (i == 0) ? 1 : pre[i - 1] + 1;
		}
		for(int i = 1; i <= k; ++ i) {
			int l = 0;
			string cur = s;
			for(int j = 1; j < i; ++ j) {
				while(nex[l] < c[j] && l < n) cur[l] = '_', ++ l;
				for(int x = 1; x <= c[j]; ++ x) {
          cur[l] = 'X', ++ l;
          if(!know[x]) know[x] = 1;
				}
				cur[l] = '_';
				l ++;
			}
			int r = n - 1;
			for(int j = k; j > i; -- j) {
				while(pre[r] < c[j] && r >= 0) cur[r] = '_', -- r;
				for(int x = 1; x <= c[j]; ++ x) {
          cur[r] = 'X', -- r;
          if(!know[x]) know[x] = 1;
				}
				cur[r] = '_';
				r --;
			}
			while(nex[l] < c[i] && l < n) cur[l] = '_', ++ l;
			while(pre[r] < c[i] && r >= 0) cur[r] = '_', -- r;
			if(l > r) continue;
			for(int j = 0; j < n; ++ j) meet[j] = 0;
			int ok = 0;
			for(int j = l; j <= r; ++ j) {
				if(nex[j] >= c[i]) {
					ok ++;
					for(int x = j; x <= j + c[i] - 1; ++ x) {
						meet[x] ++;
						know[x] = 1;
					}
				}
			}
			for(int j = l; j <= r; ++ j) {
				if(meet[j] == ok) know[j] = 2;
			}
		}
		for(int i = 0; i < n; ++ i) {
			if(s[i] == '_') cout << '_';
			else if(know[i] == 2) cout << 'X';
			else if(know[i] == 1) cout << '?';
			else cout << '_';
		}
		cout << "\n";
	}
} // sub4

namespace Full {

	int f[maxn][105], g[maxn][105];
	int can_w[maxn], can_b[maxn];
	int black[maxn], white[maxn];
	int occ[maxn];

	void Solve() {
		s = " " + s + " ";
		for(int i = 1; i <= n; ++ i) {
			black[i] = black[i - 1] + (s[i] == 'X');
			white[i] = white[i - 1] + (s[i] == '_');
		}
		white[n + 1] = white[n];
		f[0][0] = 1;
		for(int i = 1; i <= n; ++ i) {
			f[i][0] = (black[i] == 0);
			for(int j = 1; j <= k; ++ j) {
				bool w = f[i - 1][j];
				bool b = (i >= c[j]) && (s[i - c[j]] != 'X') && (white[i] == white[i - c[j]]);
				if(i > c[j]) b &= (f[i - c[j] - 1][j - 1]);
				else b &= (j == 1);
				if(s[i] == '_') f[i][j] = w;
				else if(s[i] == 'X') f[i][j] = b;
				else f[i][j] = (w | b);
			}
		}
		g[n + 1][k + 1] = g[n + 2][k + 1] = 1;
		for(int i = n; i >= 1; -- i) {
			g[i][k + 1] = (black[n] - black[i - 1] == 0);
			for(int j = k; j >= 1; -- j) {
				bool w = g[i + 1][j];
				bool b = ((n - i + 1 >= c[j]) && (s[i + c[j]] != 'X') && (white[i - 1] == white[i + c[j] - 1]) && g[i + c[j] + 1][j + 1]);
				if(s[i] == '_') g[i][j] = w;
				else if(s[i] == 'X') g[i][j] = b;
				else g[i][j] = (w | b);
			}
		}
		for(int i = 1; i <= n; ++ i) {
			if(s[i] == '_') {
				can_w[i] = 1;
			} else {
				for(int j = 0; j <= k; ++ j) {
					if(f[i - 1][j] && g[i + 1][j + 1]) can_w[i] = 1;
				}
			}
			for(int j = 1; j <= k; ++ j) {
				if(i >= c[j] && s[i - c[j]] != 'X' && s[i + 1] != 'X' && white[i] - white[i - c[j]] == 0) {
					if((i > c[j] && f[i - c[j] - 1][j - 1]) || (i == c[j] && j == 1)) {
						if(g[i + 2][j + 1]) {
							occ[i - c[j] + 1] ++, occ[i + 1] --;
						}
					}
				}
			}
		}
		for(int i = 1; i <= n; ++ i) {
			occ[i] += occ[i - 1];
			if(occ[i] > 0) can_b[i] = 1;
		}
		for(int i = 1; i <= n; ++ i) {
			if(s[i] != '.') cout << s[i];
			else {
				if(can_b[i] && can_w[i]) cout << '?';
				else if(can_w[i]) cout << '_';
				else cout << 'X';
			}
		}
		cout << "\n";
	}
} // Sub5

void Solve(int Test) {
	cin >> s;
	n = s.size();
	cin >> k;
	for(int i = 1; i <= k; ++ i) cin >> c[i];
	// if(n <= 20 && OnlyDot()) {
	// 	Sub2::Solve();
	// 	return;
	// }
	// if(n <= 100 && OnlyDot()) {
	// 	Sub3::Solve();
	// 	return;
	// }
	// if(n <= 100 && OnlyDotAndShift()) {
	// 	Sub4::Solve();
	// 	return;
	// }
	// if(n <= 100) {
		Full::Solve();
		return;
	// }
}

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
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
