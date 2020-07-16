#include<iostream>
using namespace std;

int extended_euclidean(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main(){
  int n, mod, x, y;
  cin >> n >> mod;
  extended_euclidean(n, mod, x, y);
  cout << (x%mod+mod)%mod << endl;
  return 0;
}
