#include <bits/stdc++.h>
using namespace std;

int main() {
	string input,st="#";
	cin>>input;
	for(char x:input)
	    st+=x,st+="#";
	st="@"+st+"&";

	int i,ans=0,C=0,R=0,l=st.length();
	vector<int>P(l);
	for(i=1;i<l-1;i++){
	    int mirr = 2*C-i;
	    if(i<R)
	        P[i]=min(R-i,P[mirr]);
	    while(st[i+1+P[i]]==st[i-(1+P[i])])
	        P[i]++;
	    if(i+P[i]>R)
	        C=i,R=i+P[i];
	    ans=max(ans,P[i]);
	}
	cout<<ans;
	return 0;
}
