// annotshy

#include <bits/stdc++.h>

#define Task "CF"
#define F first
#define S second
#define pb push_back

using namespace std;

const int maxn = 200005;

int n, k;
int a[maxn];

void Solve(int Test) {
  cin >> n >> k;
  for(int i = 1; i <= k; ++ i) cin >> a[i];
  map<string, long long> score, res;
	for(int i = 1; i <= k; ++ i) {
		string s; cin >> s;
		score[s] += a[i];
	}
	vector<string> ans;
	for(int i = 1; i <= n; ++ i) {
		string s, t; cin >> s >> t;
		if(score.find(s) != score.end()) {
			if(!res[t]) ans.pb(t);
			res[t] += score[s];
		}
	}
	sort(ans.begin(), ans.end(), [&](string p, string q) {
		if(res[p] == res[q]) return p < q;
		return res[p] > res[q];
	});
	cout << ans.size() << "\n";
	for(auto x : ans) cout << x << " " << res[x] << "\n";
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  if(fopen(Task".inp", "r")) {
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
  }
  int test = 1;
  cin >> test;
  for(int i = 1; i <= test; ++ i) {
    Solve(i);
  }
}

/*no pain no gain*/