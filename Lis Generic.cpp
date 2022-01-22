#include<bits/stc++.h>
using namespace std;

template<typename T>
int lis(vector<T>& A) {
  vector<T> sub;
  sub.push_back(A[0]);
  int n = A.size();
  for (int i = 1; i < n; i++) {
    if(A[i] > sub.back())
      sub.emplace_back(A[i]);
    else
      *lower_bound(sub.begin(), sub.end(), A[i]) = A[i];
  }
  // sub = subsequence itself
  return (int) sub.size();
}
