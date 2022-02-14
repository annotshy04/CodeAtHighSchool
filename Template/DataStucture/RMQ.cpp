int RMQ(int l, int r) {
  int len = log2(r - l + 1);
  return min(f[l][len], f[r - (1 << len) + 1][len]); // max, gcd.
}

void Prepare() {
  cin >> n;
  for(int i = 1; i <= n; ++ i)
    cin >> f[i][0];
  for(int i = 1; i <= 17; ++ u)
    for(int u = 1; u +(1 << i) - 1 <= n; ++ u)
      f[u][i] = min(f[u][i - 1], f[u + (1 << (i - 1))][i - 1]);
}
