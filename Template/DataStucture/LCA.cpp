void DFS(int u) {
  for(auto p : adj[u]) {
    int v = p.F, id = p.S;
    if(par[u][0] == v) continue;
    par[v][0] = u;
    for(int i = 1; i <= 17; ++ i) {
      par[v][i] = par[par[v][i - 1]][i - 1];
    }
    h[v] = h[u] + 1;
    DFS(v);
  }
}

int LCA(int u, int v) {
  if(h[u] < h[v]) swap(u, v);
  int delta = h[u] - h[v];
  for(int i = 17; i >= 0; -- i) {
    if(delta >> i & 1) u = par[u][i];
  }
  if(u == v) return u;
  for(int i = 17; i >= 0; -- i) {
    if(par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[u][0];
}

int Jump(int u, int delta) {
  for(int i = 16; i >= 0; -- i) {
    if((delta >> i) & 1) u = par[u][i];
  }
  return u;
}

int Dist(int u, int v) {
  int cha = LCA(u, v);
  return (h[u] + h[v] - 2 * h[cha]);
}
