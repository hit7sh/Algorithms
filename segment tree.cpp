                  // 1 indexed // 1 indexed // 1 indexed
struct segment {
	int mx = -INF, mn = INF;    // edit this: include properties with their default values (values that when combined doesnt change result
	segment(int _mx = -INF, int _mn = INF): mx(_mx), mn(_mn) {}	
} st[4*mxN];

int n, A[mxN];    // n = number of elements, A = array 

ostream& operator<<(ostream& ot, segment s) { ot << s.mn << ' ' << s.mx; return ot; }   // edit this

segment cmb(segment a, segment b) {
													    // edit this (the result obtained when combining two segments)
	return segment(max(a.mx, b.mx), min(a.mn, b.mn));
}

void build(int v = 1, int tl = 1, int tr = n) {
	if (tl == tr)
		st[v].mx = st[v].mn = A[tl];    // edit this
	else {
		int tm = (tl + tr)/2;
		build(2*v, tl, tm);				// build segment (tl, tm) // left child 
		build(2*v+1, tm+1, tr);			// build segment (tm+1, tr) // right child
		st[v] = cmb(st[2*v], st[2*v+1]);// combine them
	}
}

segment qry(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r or l < 1 or r > n) {
		return segment();
	} else if (l == tl && r == tr)  {
		return st[v];
	} else {
		int tm = (tl + tr)/2;

		segment left_child = qry(l, min(r, tm), 2*v, tl, tm);
		segment right_child = qry(max(l, tm+1), r, 2*v+1, tm+1, tr);

		return cmb(left_child , right_child);
	}
}

void update(int pos, int new_val, int v = 1, int tl = 1, int tr = n) {
    if (tl == tr) {
        st[v] = segment(new_val, new_val);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(pos, new_val, v*2, tl, tm);
        else
            update(pos, new_val, v*2+1, tm+1, tr);

        st[v] = cmb(st[v*2], st[v*2+1]);
    }
}

