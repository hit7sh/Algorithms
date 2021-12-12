
template <typename T>
struct fenwick {
    int n;
    vector<T> node;
 
    fenwick(int _n) : n(_n) {
        node.resize(n);
    }
 
    void add(int x, T v) {
        while (x < n) {
            node[x] += v;
            x |= (x + 1);
        }
    }
 
    T get(int x) {  // [0, x]
        T v = 0;
        while (x >= 0) {
            v += node[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
 
    T get(int x, int y) {  // [x, y]
        return (get(y) - (x ? get(x - 1) : 0));
    }
 
    int lower_bound(T v) {
        int x = 0;
        int h = 1;
        while (n >= (h << 1)) {
            h <<= 1;
        }
        for (int k = h; k > 0; k >>= 1) {
            if (x + k <= n && node[x + k - 1] < v) {
                v -= node[x + k - 1];
                x += k;
            }
        }
        return x;
    }
};
