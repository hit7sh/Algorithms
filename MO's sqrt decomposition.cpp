// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
using namespace std;


int main() {
	
 	// take inputs......................
  int n, q;
  cin >> n >> q;
  vector<int> A(n);
  for (int& x : A) cin >> x;
	
  vector<array<int, 3>> Q(q);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    Q[i] = {l, r, i};
  }
	// -------------------------
	
	
	// sort..................................................................	
  const int BLOCK = sqrt(n);
  sort(Q.begin(), Q.end(), [&](const array<int, 3>& a, const array<int, 3>& b) {
    if (a[0] / BLOCK != b[0] / BLOCK) return a[0] / BLOCK < b[0] / BLOCK;
    return a[1] < b[1];
  });
	// -----------------------------------------------------------------------
	
  int ans = 0;  // answer of current segment
  vector<int> mp(n);

	
	
//-----------------------------------------
  auto add = [&](int x) {
	  // add x to the segment
  };
  auto remove = [&](int x) {
	  // remove y from the segment
  };
//-----------------------------------------
	
  int pL = 0, pR = -1;
  vector<int> res(q);
  for (int i = 0; i < q; i++) {
    auto [L, R, idx] = Q[i];

    while (pL > L) add(A[--pL]);
    while (pR < R) add(A[++pR]);
    while (pL < L) remove(A[pL]), pL++;
    while (pR > R) remove(A[pR]), pR--;

    res[idx] = ans;
  }
	
  for (int i = 0; i < q; i++) {
    cout << res[i] << ' ';
  }
	
	
	
	
	return 0;
}
