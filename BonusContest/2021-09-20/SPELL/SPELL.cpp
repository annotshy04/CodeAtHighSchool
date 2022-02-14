#include <bits/stdc++.h>

#define Task "SPELL"

using namespace std;

const int maxn = 100005;

string s;
vector<int> L, R, mxL, mxR;
int n;

vector<int> Manacher(string s) {
  vector<int> d1(n);
  for(int i = 0, l = 0, r = -1; i < n; ++ i) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while(0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
      ++ k;
    }
    d1[i] = k --;
    if(i + k > r) {
      l = i - k;
      r = i + k;
    }
  }
  for(int i = 0; i < n; ++ i) d1[i] = d1[i] * 2 - 1;
  return d1;
}

void Solve() {
  cin >> s;
  n = s.size();
  vector<int> d = Manacher(s);
//  for(auto x : d) cout << x << " ";
  L.resize(n); R.resize(n); mxL.resize(n); mxR.resize(n);
  for(int i = 0; i < n; ++ i) {
    L[i - d[i] / 2] = max(L[i - d[i] / 2], d[i]);
    R[i + d[i] / 2] = max(R[i + d[i] / 2], d[i]);
  }
  mxL[0] = R[0];
  mxR[n - 1] = L[n - 1];
  for(int i = 1; i < n; ++ i) {
    L[i] = max(L[i], L[i - 1] - 2);
  }
  for(int i = n - 2; i >= 1; -- i) {
    mxR[i] = max(mxR[i + 1], L[i]);
  }
  for(int i = n - 2; i >= 0; -- i) {
    R[i] = max(R[i], R[i + 1] - 2);
  }
  for(int i = 1; i < n; ++ i) {
    mxL[i] = max(mxL[i - 1], R[i]);
  }
  long long ans = 0;
  for(int i = 0; i < n - 1; ++ i) {
    ans = max(ans, 1ll * mxL[i] * mxR[i + 1]);
  }
  cout << ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  if(fopen(Task".inp", "r")) {
     freopen(Task".inp", "r", stdin);
     freopen(Task".out", "w", stdout);
  }
  Solve();
}

