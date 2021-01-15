                  // 1 indexed // 1 indexed // 1 indexed
struct segment {
	int mx = -INF, mn = INF;    // edit this: include properties with their default values (values that when combined doesnt change result
} st[4*mxN];
int n, A[mxN];    // n = number of elements, A = array 

ostream& operator<<(ostream& ot, segment s) { ot << s.mn << ' ' << s.mx; return ot; }   // edit this

segment cmb(segment a, segment b) {
	segment res = {max(a.mx, b.mx), min(a.mn, b.mn)};    // edit this (the result obtained when combining two segments)
	return res;
}

void build(int v = 1, int tl = 1, int tr = n) {
	if (tl == tr)
		st[v].mx = st[v].mn = A[tl];    // edit this
	else {
		int tm = (tl + tr)/2;
		build(2*v, tl, tm);
		build(2*v+1, tm+1, tr);
		st[v] = cmb(st[2*v], st[2*v+1]);
	}
}

segment qry(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r or l < 1 or r > n) {
		segment s;
		return s;
	} else if (l == tl && r == tr)  {
		return st[v];
	} else {
		int tm = (tl + tr)/2;
		return cmb(qry(l, min(r, tm), 2*v, tl, tm), qry(max(l, tm+1), r, 2*v+1, tm+1, tr));
	}
}

