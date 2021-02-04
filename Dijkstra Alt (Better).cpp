#include<bits/stdc++.h>
using namespace std;

ostream& operator<<(ostream& ot, vector<int>& v) { for (int& x: v) ot << x << ' '; return ot; }
void solve() {	
	int m, n, u, v, w;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n);

	while (m--) {
		cin >> u >> v >> w;
		--u, --v;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	int src;
	cin >> src;
	--src;

	vector<int> vis(n), dist(n, -1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(0, src); // (dist, vertex)


	while (!pq.empty()) {
		auto [pd, p] = pq.top(); 
		pq.pop();

		if (vis[p])
			continue;

		vis[p] = 1;
		dist[p] = pd;

		for (auto& [ch, cw] : adj[p]) {
			pq.emplace(dist[p] + cw, ch);
		}
	}

	print(dist);
}
