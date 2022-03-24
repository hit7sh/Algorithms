template<class T, T unit = T()>
struct SegTree {
    T f(T a, T b) { return max(a, b); }
    vector<T> s; int n;
    SegTree(int _n = 0, T def = unit) : s(2*_n, def), n(_n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};
