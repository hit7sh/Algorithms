const int N = 1e7 + 5;

vector<int> sqf(N + 1);
void generateSqf() {
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
