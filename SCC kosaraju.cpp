vector<vector<int>> kosaraju() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n), rg(n), SCC;
  vector<int> self;
 
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    if (x == y) self.push_back(x);
    g[x].push_back(y);
    rg[y].push_back(x);
  }
  SCC.push_back(self);
  vector<int> r(n), vis(n), ans(n), toposort, C;
 
  function<void(int)> dfs_topsort = [&](int u) {
    vis[u] = 1;
    for (int v : g[u])
      if (!vis[v])
        dfs_topsort(v);
    toposort.push_back(u);
  };
  for (int i = 0; i < n; i++) {
    if (!vis[i]) dfs_topsort(i);
    if (i == 0) r = vis;
  }
  
  reverse(toposort.begin(), toposort.end());
  vis = vector<int>(n, 0);
 
  function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    C.push_back(u);
    for (int v : rg[u])
      if (!vis[v])
        dfs(v);
  };
 
  for (int i : toposort) {
    if (!vis[i]) {
      C = vector<int>();
      dfs(i);
      if (C.size() > 1) // excluding single node without self loop
        SCC.push_back(C); 
    }
  }
  return SCC;
}
