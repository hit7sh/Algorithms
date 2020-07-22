/*
    In the sample problem, for a given number n. the goal is to 
    compute the probability that randomly chosen integer from a range [1, n] 
    with uniform distribution is divisible by at least one of integers 2, 3, 11, 13.
*/

#include <iostream>
using namespace std;
long long gcd(long long a,long long b){
	if(b)
		return gcd(b, a%b);
	return a;

}

int main() {
	long long n, A[4] = {2, 3, 11, 13}, i, j;
	cin >> n;
	long long g, ans = 0, sign, cp;
	for(i=1;i<(1<<4);i++){
		cp=1;
		sign = __builtin_popcountll(i)&1?1:-1;
		for(j=0;j<4;j++)
			if((i>>j)&1)
				cp *= A[j];
		ans += sign*n/cp;
	}
	g = gcd(ans, n);
	cout << ans/g << ' ' << n/g;
	return 0;
}
