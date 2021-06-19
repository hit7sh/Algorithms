bool DFS(vvi& adj, int v, vi &vis, vector<int> &color)
{
    for (int u: adj[v])
    {
        // if vertex `u` is explored for the first time
        if (!vis[u])
        {
            // mark the current node as vis
            vis[u] = true;
 
            // current node has the opposite color of that its parent
            color[u] = !color[v];
 
            // if DFS on any subtree rooted at `v` returns false
            if (!DFS(adj, u, vis, color)) {
                return false;
            }
        }
 
        // if the vertex has already been vis and the color of the vertex
        // `u` and `v` are the same, then the graph is not bipartite
        else if (color[v] == color[u]) {
            return false;
        }
    }
 
    return true;
}
