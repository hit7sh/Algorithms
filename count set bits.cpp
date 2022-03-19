#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n, int bit) { // O(1)
  // count set bits at position 'bit' in [1, n]
  if (n == 0) return 0;
  int ans = (n / (1 << (bit + 1))) * (1 << bit);
  int md = n % (1 << (bit + 1));
  md -= (1 << bit) - 1;
  ans += max(0, min(md, 1 << bit));
  // ans = n - ans; // to count unset(0) bits
  return ans;
}
