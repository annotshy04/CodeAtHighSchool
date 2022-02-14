#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 3005;
 
int r, c, h, w, p[maxn][maxn];
int small[maxn][maxn], big[maxn][maxn];
 
int Get1(int x, int y, int u, int v) {
  return small[u][v] - small[u][y - 1] - small[x - 1][v] + small[x - 1][y - 1];
}
 
int Get2(int x, int y, int u, int v) {
  return big[u][v] - big[u][y - 1] - big[x - 1][v] + big[x - 1][y - 1];
}
 
bool Check(int x) {
  for(int i = 1; i <= r; ++ i) {
    for(int j = 1; j <= c; ++ j) {
      small[i][j] = small[i - 1][j] + small[i][j - 1] - small[i - 1][j - 1] + (p[i][j] < x);
      big[i][j] = big[i - 1][j] + big[i][j - 1] - big[i - 1][j - 1] + (p[i][j] > x);
    }
  }
  for(int i = h; i <= r; ++ i) {
    for(int j = w; j <= c; ++ j) {
      int cur1 = Get1(i - h + 1, j - w + 1, i, j);
      int cur2 = Get2(i - h + 1, j - w + 1, i, j);
      if(cur1 >= cur2) return 1;
    }
  }
  return 0;
}
 
int rectangle() {
  int Le = h * w / 2, Ri = r * c + 1;
  while(Ri - Le > 1) {
    int mid = (Le + Ri) >> 1;
    if(Check(mid)) Ri = mid;
    else Le = mid;
  }
  return Ri;
}

signed main() {
  cin >> r >> c >> h >> w;
  for(int i = 1; i <= r; ++ i) {
    for(int j = 1; j <= c; ++ j) cin >> p[i][j];
  }
  cout << rectangle() << "\n";
}