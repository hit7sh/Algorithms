// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
 
using namespace std;
using ll = int64_t;

 

 
 
 
int main() {
  ll n, i, ans = 0;
	cin >> n;
	++n;
	
	for (i = 1; i < 63; i++) {
		ll bit = 1LL << i;
		
		ll ones = (n/bit)*(bit/2);
    
		if (n%bit > bit/2)
			ones += n%bit - bit/2;

		ans += ones;
	}
	cout << ans;
 
    return 0;
}
