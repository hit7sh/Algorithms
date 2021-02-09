int upper_bound_implementation(vi& A, int v) {
	// returns n if no lowerbound exists otherwise the indexl
	int n = (int) A.size(), i;
	int L = 0, R = n, M;

	while (L < R) {
		M = L + (R - L) / 2;

		if (v >= A[M])
			L = M + 1;
		else
			R = M;
	}
	return L;
}
