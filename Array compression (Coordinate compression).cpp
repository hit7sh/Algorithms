#include<bits/stdc++.h>
using namespace std;

void compress(vector<int>& A) {
  vector<int> sorted = A;
  sort(sorted.begin(), sorted.end());
  sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
  for (int& x : A) {
    x = int(lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin());
  }
}

