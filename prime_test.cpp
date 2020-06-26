#include<iostream>
using namespace std;
using ll=long long;

bool prime(ll n) { 
  if(n < 2) 
    return 0; 
  else if (n < 4) 
    return true; 
  if (n&1^1 || n % 3 == 0) 
    return false; 
  for (ll i = 5; i * i <= n; i = i + 6) 
    if (n % i == 0 || n % (i + 2) == 0) 
      return false; 
  return true; 
}
int main()
{
  cout << prime(907);
  return 0;
}
