void solve() {
    int n, m, q;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1);
    vector<int> p(n + 1), dep(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dep[0] = -1;
    function<void(int, int)> dfs1 = [&](int u, int par) {
        vis[u] = 1;
        p[u] = par;
        dep[u] = 1 + dep[par];

        for (int& x : adj[u])
            if (!vis[x])
                dfs1(x, u);
    };
    dfs1(1, 0);
    for (int i = 1; i <= n; i++) vis[i] = 0;


    for (int i = 1; i <= n; i++) {
        jump[0][i] = p[i];
    }
    for (int i = 1; 1<<i <= n ; i++) 
        for (int j = 0; j <= n ; j++)
            jump[i][j] = jump[i-1][jump[i-1][j]];

    function<int(int, int)> lca = [&](int p, int q) {
        if(dep[p] < dep[q])
        swap(p, q);
        
        int diff = dep[p] - dep[q];
        
        for(int i = 20; i >= 0; i--) 
            if(diff & (1<<i)) 
            p = jump[i][p];
            
        if(p == q) return p;
     
        for (int i = 20; i >= 0; i--) {
            if (jump[i][p] != jump[i][q]) {
                p = jump[i][p];
                q = jump[i][q];
            }
        }
        return jump[0][p];
    };

    function<int(int, int)> fdist = [&] (int x, int y) {
        return dep[x] + dep[y] - 2 * dep[lca(x, y)];
    };



    for (int i = 1; i <= n; i++)
        jump[0][i] = 0;
    for (int i = 1; 1<<i <= n ; i++) 
        for (int j = 0; j <= n ; j++)
            jump[i][j] = 0;
}
