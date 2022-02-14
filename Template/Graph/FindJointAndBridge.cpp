void Tarjan(int u, int par, int pre_id) {
  low[u] = num[u] = ++ cnt;
  cur_cnt[u] = sz[in[u]] - 1;
  child[u] = 1;
  for(auto p : adj[u]) {
    int v = p.F, id = p.S;
    if(id == pre_id) continue;
    if(num[v]) low[u] = min(low[u], num[v]);
    else {
      Tarjan(v, u, id);
      low[u] = min(low[u], low[v]);
      child[u] += child[v];
    }
  }
  // is joint
  if(low[u] >= num[par]) {
    cur_cnt[par] -= child[u];
    ans1[par] += 1ll * child[u] * cur_cnt[par];
  }
  // is brigde
  if(low[u] > num[par]) {
    ans2[pre_id] += 1ll * child[u] * (sz[in[u]] - child[u]);
  }
}