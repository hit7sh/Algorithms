// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
using namespace std;

class dsu{
public:
    vector<int>p, siz;
    int n;
    dsu(int _n):n(_n) {
        p.resize(n+1);
        siz.resize(n+1, 1);
        iota(p.begin(), p.end(), 0);
    }

    inline int get(int x) {
        return (x==p[x]?x:(p[x]=get(p[x])));
    }

    inline bool unite(int x, int y) {
        x=get(x);
        y=get(y);

        if (x == y)
            return false;

        if (siz[x] >= siz[y])
            swap(x, y);

        siz[y] += siz[x];
        p[x] = y;
        return true;

    }
};

void solve() {
	int n, m, u, v, w, i;
	cin >> n >> m;
	vector<vector<int>> edges;
	f0(i, m) {
		cin >> u >> v >> w;
		--u, --v;
		edges.push_back({w, u, v});
	}
	cin >> w;
	sort(edges.begin(), edges.end());
	dsu D(n);
	int ans = 0;
	for (auto& x : edges) {
		if (D.unite(x[1], x[2]))
			ans += x[0];
	}
	cout << ans;
}
 




int main() {
  solve();
  return 0;
}
