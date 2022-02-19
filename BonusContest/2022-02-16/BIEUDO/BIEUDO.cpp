#include<bits/stdc++.h>

#define Task "BIEUDO"

using namespace std;

const int maxn = 200005;

int n, h[maxn];
long long p;
int l[maxn], r[maxn];

void Get_L() {
  stack<int> st;
  for(int i = 1; i <= n; ++ i) {
    while(st.size() && h[st.top()] >= h[i]) st.pop();
    if(st.size()) l[i] = st.top();
    else l[i] = 0;
    st.push(i);
  }
}

void Get_R() {
  stack<int> st;
  for(int i = n; i >= 1; -- i) {
    while(st.size() && h[st.top()] > h[i]) st.pop();
    if(st.size()) r[i] = st.top();
    else r[i] = n + 1;
    st.push(i);
  }
}

void Sub1() {
  long long res = 0;
  for(int i = 1; i <= n; ++ i) {
    int mn = 2e9;
    for(int j = i; j <= n; ++ j) {
      mn = min(mn, h[j]);
      int len = j - i + 1;
      long long need = (p + len - 1) / len;
      if(need > mn) continue;
      res += mn - need + 1;
    }
  }
  cout << res << "\n";
}

namespace Sub2 {

  int t[3005];

  void Solve() {
    long long res = 0;
    int mx = *max_element(h + 1, h + n + 1);
    for(int i = 1; i <= n; ++ i) {
      for(int H = 1; H <= mx; ++ H) {
        if(H > h[i]) {
          t[H] = i;
          continue;
        }
        int len = (p + H - 1) / H;
        int last = t[H] + 1, need = i - len + 1;
        if(last > need) continue;
        res += need - last + 1;
      }
    }
    cout << res << "\n";
  }
}

namespace Sub3 {

  void Solve() {
    Get_L();
    Get_R();
    long long res = 0;
    for(int i = 1; i <= n; ++ i) {
      l[i] ++;
      r[i] --;
      long long cur = 1;
      cur += r[i] - i;
      cur += i - l[i];
      cur += 1ll * (r[i] - i) * (i - l[i]);
      res += cur * h[i];
    }
    cout << res << "\n";
  }
}

void Solve(int Test) {
  cin >> n >> p;
  for(int i = 1; i <= n; ++ i) cin >> h[i];
  if(n <= 3000) {
    Sub1();
    return;
  }
  if(*max_element(h + 1, h + n + 1) <= 3000) {
    Sub2::Solve();
    return;
  }
  if(p == 1) {
    Sub3::Solve();
    return;
  }
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
