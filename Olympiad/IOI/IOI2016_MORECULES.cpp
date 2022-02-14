#include<bits/stdc++.h>

#define Task "CF"

using namespace std;

const int maxn = 200005;

int n, l, r, mx, mn;
int a[maxn];

void Sub1() {
	int sum = 0;
	for(int i = 1; i <= n; ++ i) {
		sum += a[i];
		if(sum >= l) {
			if(sum <= r) {
				cout << i << "\n";
				for(int j = 0; j < i; ++ j) cout << j << " ";
				return;
			}
			break;
		}
	}
	cout << 0;
}

namespace Sub2 {
	vector<pair<int, int> > le, gr;

	void Solve() {
		for(int i = 1; i <= n; ++ i) {
			if(a[i] == mn) le.push_back({a[i], i - 1});
			else if(a[i] == mx) gr.push_back({a[i], i - 1});
		}
		long long sum1 = 0;
		for(int i = 0; i < (int) le.size(); ++ i) {
			long long sum2 = 0;
			sum1 += le[i].first;
			for(int j = 0; j < (int) gr.size(); ++ j) {
				sum2 += gr[j].first;
				if(sum1 + sum2 >= l && sum1 + sum2 <= r) {
					cout << (i + 1) + (j + 1) << "\n";
					for(int x = 0; x <= i; ++ x) cout << le[x].second << " ";
					for(int x = 0; x <= j; ++ x) cout << gr[x].second << " ";
					cout << "\n";
					return;
				}
			}
		}
		sum1 = 0;
		for(int i = 0; i < (int) le.size(); ++ i) {
			sum1 += le[i].first;
			if(sum1 >= l && sum1 <= r) {
				cout << (i + 1) << "\n";
				for(int x = 0; x <= i; ++ x) cout << le[x].second << " ";
				cout << "\n";
				return;
			}
		}
		sum1 = 0;
		for(int i = 0; i < (int) gr.size(); ++ i) {
			sum1 += gr[i].first;
			if(sum1 >= l && sum1 <= r) {
				cout << (i + 1) << "\n";
				for(int x = 0; x <= i; ++ x) cout << gr[x].second << " ";
				cout << "\n";
				return;
			}
		}
		cout << 0 << "\n";
	}
}

namespace Sub_3_4 {

	int dp[10005], tr[10005];

	void Solve() {
		dp[0] = 1;
		for(int i = 1; i <= n; ++ i) {
			for(int s = r; s >= 0; -- s) {
				if(dp[s] && s + a[i] <= r && !dp[s + a[i]]) {
					dp[s + a[i]] = 1;
					tr[s + a[i]] = i;
				}
			}
		}
		for(int s = l; s <= r; ++ s) {
			if(dp[s]) {
				vector<int> ans;
				while(s) {
					int id = tr[s];
					ans.push_back(id);
					s -= a[id];
				}
				sort(ans.begin(), ans.end());
				cout << ans.size() << "\n";
				for(auto x : ans) cout << x - 1 << " ";
				cout << "\n";
				return;
			}
		}
		cout << 0 << "\n";
	}
}

namespace Full {

	#define int long long
	pair<int, int> b[maxn];
	long long s[maxn];

	void Solve() {
		for(int i = 1; i <= n; ++ i) {
			b[i] = {a[i], i - 1};
		}
		sort(b + 1, b + n + 1);
		for(int i = 1; i <= n; ++ i) {
			s[i] = s[i - 1] + b[i].first;
		}
		for(int i = 1; i <= n; ++ i) {
			int L = i - 1, R = n + 1;
			while(R - L > 1) {
				int mid = (L + R) >> 1;
				if(s[mid] - s[i - 1] >= l) R = mid;
				else L = mid;
			}
			if(R != n + 1 && s[R] - s[i - 1] <= r && s[R] - s[i - 1] >= l) {
				vector<int> ans;
				for(int x = i; x <= R; ++ x) ans.push_back(b[x].second);
				cout << ans.size() << "\n";
				for(auto x : ans) cout << x << " ";
				return;
			}
		}
		cout << 0 << "\n";
	}
}

void Solve(int Test) {
	cin >> n >> l >> r;
	for(int i = 1; i <= n; ++ i) cin >> a[i];
	mx = *max_element(a + 1, a + n + 1);
	mn = *min_element(a + 1, a + n + 1);
	if(n <= 100 && mx == mn) {
		Sub1();
		return;
	}
	if(n <= 100 && mx - mn <= 1) {
    Sub2::Solve();
    return;
	}
	if(n <= 10000 && r <= 10000 && mx <= 10000) {
		Sub_3_4::Solve();
		return;
	}
	Full::Solve();
	return;
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