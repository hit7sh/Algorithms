// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define findmax(v) *max_element(v.begin(), v.end())
#define f0(i, n) for(i = 0; i < (int)(n); i++)
#define endl "\n"

using namespace std;
const int mod = 1e9+7,mxN = 1e6+5;

template<typename... Args>void print(Args... args){((cout << args << " "), ...);
cout << endl;}

int A[mxN], B[mxN];

void solve(){ //A
	int i, n, b, m, prev = -1, cur  = 0, ans = 0;
	cin >> n >> b >> m;
	f0(i, m)
		cin >> A[i];
	f0(i, m) {
		cur = A[i]/b;
		if(prev == cur)
			continue;
		prev = A[i]/b;
		ans++;
	}
	print(ans);
}	

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    __speed();
    tt solve();
    return 0;
}
