struct BIT {
  int n;
  vector<int> tree;

  BIT(int _n) {
    n = _n;
    tree.resize(n + 1);
  }

  void Update(int x, int val) {
    for(; x <= x; x += x & -x) tree[x] += val;
  }
  
  int Get(int x) {
    int res = 0;
    for(; x; x -= x & -x) res += tree[x];
    return res;
  }
}