#include<bits/stdc++.h>
using namespace std;

template<typename T>
vector<T> compress(vector<T>& A) {
  vector<T> sorted = A;
  sort(sorted.begin(), sorted.end());
  sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
  for (T& x : A) {
    x = int(lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin());
  }
  return sorted;
}
