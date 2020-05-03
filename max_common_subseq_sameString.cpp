#include <bits/stdc++.h>
using namespace std;

int main() {
	int ans=0,i,l;
	string st;
	unordered_map<char,int>M;
	cin>>st;
	l=st.length();
	
	for(i=0;i<l;i++){
	    if(M.count(st[i]))
	        ans=max(ans, l-(i-M[st[i]]));
	    M[st[i]]=i;
	}
	cout<<ans<<endl;
	return 0;
}
