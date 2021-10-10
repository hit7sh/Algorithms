#include<bits/stdc++.h>
using namespace std;

vector<ll> dijkstra(vector<vector<pair<int, int>>>& adj, int s) {
  int n = (int) adj.size();
  vector<int> vis(n);
  vl dist(n, -1);
  pq<pair<ll, int>> pq;
  pq.emplace(0, s); // (dist, vertex)


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
  return dist;
}
