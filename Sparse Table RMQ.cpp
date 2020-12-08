#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define dbg(x) cout << "--- " << #x << " = " << x << " ---\n";
#define findmax(v) *max_element(v.begin(), v.end())
#define _sum(a) accumulate(a.begin(), a.end(), 0)
#define tt int t;for(cin>>t; t--; )
#define f0(i, n) for(i = 0; i < int(n); i++)
#define f1(i, n) for(i = 1; i<= int(n); i++)
#define cmax(a, b) a= max(a, b)
#define cmin(a, b) a= min(a, b)
#define all(x) x.begin(), x.end()
#define EB emplace_back
#define PB push_back
#define F first
#define S second
#define endl "\n"

using namespace std;
using mii = map<int, int>;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
const int mod = 1e9+7,mxN = 2e5+5;

int st[mxN][20]={};
void solve(){
	int K=20, N, i, q, L, R;
	cin >> N;
	vi array(N);
	f0(i, N)
		cin >> array[i];
	int log[mxN+1];
	log[1] = 0;
	for (int i = 2; i < mxN; i++)
	    log[i] = log[i/2] + 1;

	for (int i = 0; i < N; i++)
    st[i][0] = array[i];

	for (int j = 1; j <= K; j++)
	    for (int i = 0; i + (1 << j) <= N; i++)
	        st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);

	cin >> q;
	while(q--){
		cin >> L >> R;
		int j = log[R - L + 1];
		int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
		cout << (minimum) << endl;

	}
	
}

int main(){
    __speed();
    solve();
    return 0;
}
