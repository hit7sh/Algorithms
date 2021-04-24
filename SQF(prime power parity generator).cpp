const int N = 1e7 + 5;

vector<int> sqf(N + 1);
void generateSqf() {
  /*
  * suppose n = 90
  * prime factorization of 90 = 2^1 * 3^2 * 5^1
  * In sqf representation we consider only the primes with 'odd' powers.
  * so sqf(90) = 2 * 5 = 10
  */
  for (int i = 0; i <= N; i++){
    sqf[i] = i;
  }
  for (int i = 2; i * i <= N; i++){
    for (int j = i * i; j <= N; j += i * i){
      while (sqf[j] % (i * i) == 0){
        sqf[j] /= i * i;
      }
    }
  }
}
