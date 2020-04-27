#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    
    ll n;
    cin>>n;
    ll ans = n*n + n*(n*n-1)/6; //Well, that's the formula. It's derived by observing bruteforce count.
    cout<<ans;

    return 0;
}
