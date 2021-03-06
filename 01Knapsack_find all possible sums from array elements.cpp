// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define f1(i, n) for(i = 1; i<= int(n); i++)

using namespace std;

template<typename... Args>void print(Args... args){((cout << args << " "), ...);cout << endl;}

void solve(){
	int A[]={1, 3, 4, 5, 10}, i;
	int knapsack[1000]={1};
	for(int x:A){
		for(i=1000-x; ~i;--i)
			if(knapsack[i])
				knapsack[i+x]=1;
	}
	f1(i, 999)
		if(knapsack[i])
			print(i);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    __speed();
    solve();
    return 0;
}
