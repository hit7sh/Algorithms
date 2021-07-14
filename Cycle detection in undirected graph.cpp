int nc, ec; // nc = nodes count, ec = edges count
void dfs(int u, vector<vector<int>>& adj, vector<int>& vis) {
    nc++; ec += adj[u].size();
    vis[u] = 1;
    for (int v : adj[u]) 
        if (!vis[v])
            dfs(v, adj, vis);
}
bool solve(int n, vector<vector<int> > &edges) {
    vector<int> vis(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < edges.size(); i++) { // make adj matrix
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    bool ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) { // check in every connect component
            nc = ec = 0;
            dfs(i, adj, vis);
            ec /= 2;
            ans |= ec != (nc - 1); // for a component to be connected edges = nodes - 1
        }
    }
    return ans;
}
