// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define tt 	int t; for (cin >> t; t--; )

#define f0(i, n)  for (i = 0; i < (int)(n); i++)
#define f1(i, n)  for (i = 1; i <=(int)(n); i++)

#define EB emplace_back
#define PB push_back

#define endl "\n"
#define S second
#define F first



using namespace std;
using vi = vector<int>;

const int mod = 1e9+7, mxN = 2e5+5, INF = 0x3f3f3f3f;



template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }

template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }
template <typename T> ostream& operator<<(ostream& ot, vector<T>& v) { for (T& x:v) ot << x << ' '; return ot; }


vector<pii> adj[mxN];

void solve() {
	int n, m, u, v, w, i, s;
	cin >> n >> m;
	f0(i, m) {
		cin >> u >> v >> w;
		// --u, --v;
		adj[u].EB(v, w);
		adj[v].EB(u, w);
	}
	cin >> s;

	vector<bool> vis(n+1);
	vi dist(n+1, INF);
  
	dist[s] = 0;
	priority_queue<pii> q;  // by default it is max Heap
	q.emplace(0, s);

	while (!q.empty()) {
		int p = q.top().S; q.pop();
    
		if (vis[p])
			continue;
      
		vis[p] = 1;
    
		for (pii& c:adj[p]) {
				v = c.F; w = c.S;
				if (dist[p] + w < dist[v]) {
					dist[v] = dist[p] + w;
					q.emplace(-dist[v], v);
				}
		}
	}
  
	dist.erase(dist.begin()+s);
	dist.erase(dist.begin());

	for (int& x:dist)
		if (x==INF)
			x = -1;

	print(dist);
  
	f1(i, n)
		adj[i].clear();
	
	
}















int main() {

    __speed() tt solve();

    return 0;
}
