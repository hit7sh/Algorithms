#include<bits/stdc++.h>
using namespace std;

void compress(vector<int>& A) {
	vector<int> sorted = A;
	vector<int> compressed(A.size());
	sort(sorted.begin(), sorted.end());
	for (int i = 1; i < (int) A.size(); i++) {
		if (sorted[i] == sorted[i - 1])
			compressed[i] = compressed[i - 1];
		else
			compressed[i] = compressed[i - 1] + 1;
	}
	for (int i = 0; i < (int) A.size(); i++) {
		A[i] = compressed[lower_bound(sorted.begin(), sorted.end(), A[i]) - sorted.begin()];
	}
}
