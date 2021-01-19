#include<bits/stdc++.h>
#define speed() ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define endl "\n"
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)

using namespace std;
int i,j,n;

// +++++++++++++++++++++++++++++++ ANOTHER WAY ++++++++++++++++++++++++++++++++++++

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);

            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main()
{
    speed();
    cin>>n;
//-------------------------------------
    vector<bool>is_prime(n+1,true);
    for(i=2;i*i<=n;i++)
        if(is_prime[i])                 //Complexity: O(n*log(log(n)))
            for(j=i*i;j<=n;j+=i)
                is_prime[j]=0;
//-------------------------------------
    f1(i,n)
        if(is_prime[i]&&(i-1))
            cout<<i<<endl;
    return 0;
}
