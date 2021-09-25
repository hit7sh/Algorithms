#include<bits/stc++.h>
using namespace std;

vector<int> lis(vector<int> a){
	int n = (int)a.size();
	vector<int> r(n, 0);
	vector<int> stk;
	for(int i = 0; i < n; i++){
		int x = lower_bound(stk.begin(), stk.end(), a[i]+1) - stk.begin();
		r[i] = x;
		if(x >= (int)stk.size()){
			stk.push_back(a[i]);
		}
		stk[x] = a[i];
	}
	return r;
}
