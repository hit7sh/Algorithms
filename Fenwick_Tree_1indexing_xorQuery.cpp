// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define f1(i, n) for(i = 1; i<= (int)(n); i++)
#define endl "\n"

using namespace std;

template<typename... Args>void print(Args... args){((cout << args << " "), ...);cout << endl;}

int ft[300005], n, A[300005]; // ft = fenwick tree
void upd(int i, int v){
	for(;i<=n; i+=i&-i) // i += i&-i goes to the parent segment
		ft[i] ^= v;
}
void build(){
	for(int i=1;i<=n;i++)
		upd(i, A[i]);
}
int get(int r){     // returns query(1 to r)
	int res=0;
	for(; r>0; r -= r&-r) // i -= i&-i goes to child segment
		res ^= ft[r];
	return res;
}

void solve(){
	int  q, i, t, x, y;
	cin >> n >> q;
	f1(i, n) cin >> A[i];
	build();              // necessary to build the fenwick tree first
	while(q--){
		cin >> t >> x >> y;
		
		if(t==1){
			upd(x, y);
		}else{
			print(get(y) ^ get(x-1));   
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout);
	#endif
    __speed() solve();
    return 0;
}
