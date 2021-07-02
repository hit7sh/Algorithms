int count_primes(int n) {
  int c = 0;
  for (int p : primes) {
    if (p * p > n) break;
    
    while (n % p == 0) {
      n /= p;
      c++;
    }
  }
  if (n > 1)
    c++;
  return c;
}
