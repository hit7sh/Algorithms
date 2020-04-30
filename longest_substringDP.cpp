#include <bits/stdc++.h>
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)
using namespace std;

int main() {
	string st, max_pal;
	int i, j, l;
	cin>>st;
	l = st.length();
	vector<vector<bool>>dp(l, vector<bool>(l));
	f0(i, l)
	    dp[i][i] = true, i?(dp[i][i-1] = true):0;

	int from = 0, how_many = 1;
	f1(j, l-1)
	    f0(i, l-j)
	        if((st[i]==st[i+j]) && (dp[i+1][i+j-1]))
	            dp[i][i+j] = true,from = i, how_many = j+1;
	            
	f0(i, l)
	    f0(j,l)
	        cout<<dp[i][j]<<" \n"[j==l-1];
	
	max_pal = st.substr(from, how_many);
	cout<<max_pal;
	return 0;
}
