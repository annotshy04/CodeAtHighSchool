// annotshy

#include <bits/stdc++.h>

#define Task "CF"
#define pb push_back

/*
	Task: Baby Ehab plays with colors
*/

using namespace std;

const int maxn = 100005;

int n;
vector<int> adj[maxn], rev_adj[maxn];
int color[maxn], deg[maxn], mxcolor = 0;
int vis[25];

void Solve(int Test) {
  cin >> n;
 	for(int i = 1; i <= n; ++ i) color[i] = 0, deg[i] = (int) rev_adj[i].size();
  mxcolor = log2(n) + 1;
  queue<int> q;
  for(int i = 1; i <= n; ++ i) {
  	if(deg[i] == 0) q.push(i), color[i] = 1;
  }
  while(q.size()) {
  	int u = q.front();
  	q.pop();
  	for(auto v : adj[u]) {
  		-- deg[v];
  		if(deg[v] == 0) {
		  	for(int i = 1; i <= mxcolor; ++ i) vis[i] = 0;
  			for(auto x : rev_adj[v]) {
		  		vis[color[x]] = 1;
		  	}
		  	for(int i = 1; i <= mxcolor; ++ i) {
		  		if(!vis[i]) {
		  			color[v] = i;
		  			break;
		  		}
		  	}
		  	q.push(v);
  		}
  	}
  }
  for(int i = 1; i <= n; ++ i) cout << color[i] << " ";
  cout << "\n";
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
  for(int i = 1; i <= 100000; ++ i) {
  	for(int j = i * 2; j <= 100000; j += i) {
  		adj[i].pb(j);
  		rev_adj[j].pb(i);
  	}
  }
  for(int i = 1; i <= test; ++ i) {
    Solve(i);
  }
}

/*no pain no gain*/
