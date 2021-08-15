const int NN = 2e5+5;
int lp[NN] = {};
vector<int> pr;

void sieve() {
  for (int i=2; i < NN; ++i) {
      if (lp[i] == 0) {
          lp[i] = i;
          pr.push_back(i);
    }
      for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=NN; ++j)
          lp[i * pr[j]] = pr[j];
  }
}
