#include <bits/stdc++.h>

#define Task "NOTFIB"
#define MOD 1000000007

using namespace std;

const int maxn = 105;

int n, k;
int f[maxn], a[maxn];

void AddMOD(long long &x, long long y) {
  x += y;
  if(x >= MOD) x -= MOD;
}

struct Matrix {
  int n;
  long long val[maxn][maxn];

  Matrix(int _n) {
    n = _n;
    memset(val, 0, sizeof val);
  }

  Matrix operator * (const Matrix B) {
    Matrix C(n);
    for(int i = 1; i <= n; ++ i) {
      for(int j = 1; j <= n; ++ j) {
        for(int k = 1; k <= n; ++ k) {
          AddMOD(C.val[i][j], val[i][k] * B.val[k][j] % MOD);
        }
      }
    }
    return C;
  }
};

Matrix Mu(Matrix A, long long b) {
  Matrix C(k);
  for(int i = 1; i <= k; ++ i) C.val[i][i] = 1;
  for(; b; b /= 2, A = A * A) {
    if(b % 2) C = C * A;
  }
  return C;
}

void Solve() {
  cin >> n >> k;
  for(int i = 0; i < k; ++ i) cin >> f[i];
  for(int i = 1; i <= k; ++ i) cin >> a[i];
  Matrix T(k);
  for(int i = 1; i <= k; ++ i) {
    T.val[1][i] = a[i];
    if(i > 1) T.val[i][i - 1] = 1;
  }
  Matrix B = Mu(T, n - k + 1);
  long long res = 0;
  for(int i = 0; i < k; ++ i) {
    AddMOD(res, B.val[1][i + 1] * f[k - i - 1] % MOD);
  }
  cout << res;
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

