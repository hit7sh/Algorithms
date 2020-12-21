#include<bits/stdc++.h>
using namespace std;

class dsu{
public:
	vector<int>p;
	int n;
	dsu(int _n):n(_n){
		p.resize(n+1);
		iota(p.begin(), p.end(), 0);
	}
	inline int get(int x){
		return (x==p[x]?x:(p[x]=get(p[x])));
	}
	inline bool unite(int x, int y){
		x=get(x);
		y=get(y);
		if(x!=y){
			p[x]=y;
			return true;
		}
		return false;
	}
};


// x->y (edge)
// if it fails to unite (that is both of their representatives are the same
// that we have found a cycle for sure, otherwise we set representative of node x is y.
