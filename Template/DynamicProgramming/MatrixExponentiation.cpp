struct Matrix {
  vector<vector<int> > val;
  int n, m;
 
  Matrix(int _n, int _m) {
    n = _n, m = _m;
    val.resize(n);
    for(int i = 0; i < n; ++ i) val[i].resize(m);
  }
 
  Matrix operator * (const Matrix B) const {
    assert(m == B.n);
    Matrix C(n, B.m);
    for(int i = 0; i < n; ++ i) {
      for(int j = 0; j < B.m; ++ j) {
        for(int k = 0; k < m; ++ k) {
          C.val[i][j] = (C.val[i][j] + 1ll * val[i][k] * B.val[k][j] % MOD) % MOD;
        }
      }
    }
    return C;
  }
};
 
Matrix Mu(Matrix A, long long b) {
  Matrix C(A.n, A.m);
  for(int i = 0; i < A.n; ++ i) C.val[i][i] = 1;
  for(; b; b /= 2, A = A * A) {
    if(b % 2) C = C * A;
  }
  return C;
}