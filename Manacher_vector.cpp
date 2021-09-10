vector<vector<int>> manacher(string& s){
  int n=s.size();
  vector<int> d1(n);
for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
        k++;
    }
    d1[i] = k--;
    if (i + k > r) {
        l = i - k;
        r = i + k;
    }
  }
  vector<int> d0(n);
for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : min(d0[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
        k++;
    }
    d0[i] = k--;
    if (i + k > r) {
        l = i - k - 1;
        r = i + k ;
    }
}
  // d0 = even center, what is longest radius excluding center to the left
  //      length of odd palindrome = 2 * d0[i]

  // d1 = odd center, what is longest radius including center to the left
  //      length of even palindrome = 1 + 2 * (d1[i] - 1)
    return {d0, d1};
}
