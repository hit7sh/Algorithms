// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
 
#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define dbg(x) cout << "(" << __LINE__ << ": "<< #x << " = " << x << ")\n"
 
#define Yes(x) print((x) ? "Yes" : "No")
#define tt 	int t; for (cin >> t; t--; )
 
#define f0(i, n)  for (i = 0; i < (int)(n); i++)
#define f1(i, n)  for (i = 1; i <=(int)(n); i++)
 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x.size())
 
#define EB emplace_back
#define PB push_back

#define LB lower_bound
#define UB upper_bound

#define endl "\n"
#define S second
#define F first

using namespace std;
using mii = map<int, int>;
using pii = pair<int, int>;
 
using ll = int64_t;
using vi = vector<int>;
 
using vvi = vector<vi>;
using vl = vector<ll>;
 
const pair<int, int> DD[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int mod = 1e9 + 7, mxN = 7e5 + 5, INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
 

template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }

template <typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& p) { in >> p.F >> p.S; return in; }
template <typename T1, typename T2> ostream& operator<<(ostream& ot, pair<T1, T2>& p) { ot << p.F << ' ' << p.S; return ot; }

template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }
template <typename T> ostream& operator<<(ostream& ot, vector<T>& v) { for (T& x:v) ot << x << ' '; return ot; }

const int N = 2e5 + 5;

ll t[4 * N];
ll n, q;

ll qry(ll l, ll r, ll v = 1, ll tl = 0, ll tr = N) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return gcd(qry(l, min(r, tm), v*2, tl, tm), qry(max(l, tm+1), r, v*2+1, tm+1, tr));
}

void upd(ll pos, ll new_val, ll v = 1, ll tl = 0, ll tr = N) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            upd(pos, new_val, v*2, tl, tm);
        else
            upd(pos, new_val, v*2+1, tm+1, tr);
        t[v] = gcd(t[v*2],  t[v*2+1]);
    }
}


void solve() {
	cin >> n >> q;
	ll u, v, l, w, i, load;
	vector<vector<pair<ll, ll>>> QueriesOf(n + 1);
	vector<vector<vector<ll>>> adj(n + 1);
	vector<ll> ans(q);
	f0(i, n - 1) {
		cin >> u >> v >> l >> w;
		adj[u].push_back({v, l, w});
		adj[v].push_back({u, l, w});
	}
	f0(i, q) {
		cin >> u >> load;
		QueriesOf[u].EB(load, i);
	}

	function<void(ll, ll)> dfs = [&](ll cur, ll parent) {
		for (auto& [city, idx] : QueriesOf[cur]) {
			ans[idx] = qry(0, city);
		}
		for (auto& ch : adj[cur]) {
			if (ch[0] == parent) continue;
			ll child = ch[0], lim = ch[1], cost = ch[2];
			
			upd(lim, cost); // before entering subtree

			dfs(child, cur);

			upd(lim, 0); // backtracking 
		}
	};
	dfs(1, -1);

	print(ans);
}
 




signed main() { 
	 __speed();
	 int t, i; for (cin >> t, i = 1; i <= t; i++) cout << "Case #" << i << ": ", solve();
}
