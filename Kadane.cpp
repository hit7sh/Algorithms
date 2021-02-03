// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;
using vl = vector<ll>;
 
const int mod = 1e9+7, mxN = 7e5+5, INF = 0x3f3f3f3f;
 
template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }

template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }


 
int main() {
  int n;
	cin >> n;
	vl A(n);
	cin >> A;
	ll cur, best;
	cur = 0;
	best = -INF;

	for (ll& x : A) {
		cur += x;
		cur = max(cur, x);
		best = max(best, cur);
	}

	print(best);
}
