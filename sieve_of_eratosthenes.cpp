#include<bits/stdc++.h>
#define speed() ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define endl "\n"
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)

using namespace std;
int i,j,n;

int main()
{
    speed();
    cin>>n;
//-------------------------------------
    vector<bool>is_prime(n+1,true);
    for(i=2;i*i<=n;i++)
        if(is_prime[i])                 //Complexity: O(n*log(log(n)))
            for(j=i+i;j<=n;j+=i)
                is_prime[j]=0;
//-------------------------------------
    f1(i,n)
        if(is_prime[i]&&(i-1))
            cout<<i<<endl;
    return 0;
}
