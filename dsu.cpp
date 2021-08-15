#include<bits/stdc++.h>
using namespace std;

class dsu{
public:
	vector<int>p, siz;
	int n;
	dsu(int _n):n(_n) {
		p.resize(n+1);
		siz.resize(n+1, 1);
		iota(p.begin(), p.end(), 0);
	}

	inline int get(int x) {
		return (x==p[x]?x:(p[x]=get(p[x])));
	}
	
	inline int getsize(int x) {
    		return siz[get(x)];
  	}
	
	inline bool unite(int x, int y) {
		x=get(x);
		y=get(y);

		if (x == y)
			return false;

		if (siz[x] >= siz[y])
			swap(x, y);

		siz[y] += siz[x];
		p[x] = y;
		return true;

	}
};


// x->y (edge)
// if it fails to unite (that is both of their representatives are the same
// that we have found a cycle for sure, otherwise we set representative of node x is y.
