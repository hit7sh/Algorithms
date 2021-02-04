void solve() {	
	ll i, j, n, m, u, v, w;
	cin >> n >> m;
	vector<vector<pair<ll, ll>>> g(n+1);
	vl vis(n+1), dist(n+1);
	dist[1] = 0; // source

	f1(i, m) {
		cin >> u >> v >> w;
		g[u].PB({v, w});
		// g[v].PB({u, w});
	}

	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
	q.push({0, 1});
 
	while (sz(q)) {
		auto x = q.top(); q.pop();
		ll p = x.S;
		if (vis[p])
			continue;
 		dist[p] = x.F;
		vis[p] = 1;
 
		for (auto& [c, d] : g[p]) {	
				q.push({dist[p] + d, c});
			}
	}
	dist.erase(dist.begin());
	print(dist);
}
