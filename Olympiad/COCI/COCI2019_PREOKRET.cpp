// annotshy
 
#include <bits/stdc++.h>
 
#define Task "CF"
#define F first
#define S second
#define sz(x) (int) x.size()
#define MOD 1000000007
#define pb push_back
 
using namespace std;
 
const int maxn = 1005;
 
int nA, nB;
vector<pair<int, int> > event;
 
void Solve(int Test) {
  cin >> nA;
  for(int i = 1; i <= nA; ++ i) {
    int t; cin >> t;
    event.pb({t, 0});
  }
  cin >> nB;
  for(int i = 1; i <= nB; ++ i) {
    int t; cin >> t;
    event.pb({t, 1});
  }
  sort(event.begin(), event.end());
  int res_score = 0, res_turn = 0;
  int last = -1, cnt0 = 0, cnt1 = 0;
  for(auto x : event) {
    if(x.F <= 1440) ++ res_score;
    if(x.S == 0) cnt0 ++;
    else cnt1 ++;
    if(cnt0 > cnt1) {
      if(last == -1) last = 0;
      else if(last == 1) ++ res_turn, last = 0;
    }
    if(cnt1 > cnt0) {
      if(last == -1) last = 1;
      else if(last == 0) ++ res_turn, last = 1;
    }
  }
  cout << res_score << "\n" << res_turn << "\n";
}
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  if(fopen(Task".inp", "r")) {
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
  }
  int test = 1;
//  cin >> test;
  for(int i = 1; i <= test; ++ i) {
    Solve(i);
  }
}
 
/*no pain no gain*/