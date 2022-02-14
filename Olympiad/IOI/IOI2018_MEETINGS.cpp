#include<bits/stdc++.h>

#define Task "CF"

using namespace std;

const int maxn = 200005;

vector<long long> minimum_costs(vector<int> H, vector<int> L, vector<int> R) {
	vector<vector<long long> > cost;
	int n = H.size();
	cost.resize(n);
	for(int i = 0; i < n; ++ i) {
		cost[i].resize(n);
		cost[i][i] = H[i];
		int mx = H[i];
		for(int j = i - 1; j >= 0; -- j) {
			mx = max(mx, H[j]);
			cost[i][j] = cost[i][j + 1] + mx;
//			cout << i << " " << j << " " << cost[i][j] << "\n";
		}
		mx = H[i];
		for(int j = i + 1; j < n; ++ j) {
			mx = max(mx, H[j]);
			cost[i][j] = cost[i][j - 1] + mx;
//			cout << i << " " << j << " " << cost[i][j] << "\n";
		}
	}
	int q = L.size();
	vector<long long> res;
	for(int i = 0; i < q; ++ i) {
		int l = L[i], r = R[i];
		long long ans = 1e18;
		for(int x = l - 1; x <= r; ++ x) {
      long long L_cost = 0;
      long long R_cost = 0;
      if(x >= l) L_cost = cost[x][l];
      if(x + 1 <= r) R_cost = cost[x + 1][r];
			ans = min(ans, L_cost + R_cost);
		}
		res.push_back(ans);
	}
	return res;
}

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
//  if(fopen(Task".inp", "r")) {
//    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
//  }
  vector<long long> ans = minimum_costs({2, 4, 3, 5}, {0, 1}, {2, 3});
	for(auto x : ans) cout << x << "\n";
}
