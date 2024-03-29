template<typename T>
std::vector<T> divisors(T n) {
  std::vector<T> divisors;
  for (int i = 1; (T) i * i <= n; i++) {
    if (n % i == 0) {
      divisors.push_back(i);
      if (i != n / i) {
        divisors.push_back(n / i);
      }
    }
  }
  return divisors;
}
