// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
using namespace std;


const int BLOCK = 550, N = 3e5 + 5; // BLOCK = 550 = sqrt(3e5)
int A[N];

struct Query {
	int L, R, idx;
	inline bool operator<(const Query& other) const {
		if (L / BLOCK != other.L / BLOCK)
			return L / BLOCK < other.L / BLOCK;
		return R < other.R;
	}
} Q[N];

void add(int pos) {
	// add A[pos] to range
}

void remove(int pos) {
	// remove A[pos] from range
}

void solve() {
	// input array and queries and sort queries

	int pL = 0, pR = -1;
	f0(i, q) {
		int L = Q[i].L;
		int R = Q[i].R;
		
		while(pL > L)
		pL-- , add(pL);
		
		while(pR < R)
		pR++ , add(pR);
		
		while(pL < L)
		remove(pL) , pL++;
		
		while(pR > R)
		remove(pR) , pR--;
		
		// process answer obtained from query
		// ans[i] = ...
	}
	f0(i, q)
		cout << ans[i] << ' ';
}
 




int main() { 
     solve();
}
