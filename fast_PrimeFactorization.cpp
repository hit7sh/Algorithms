// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define endl "\n"

using namespace std;
using ll = long long;

int main(){
    speed();
    ll n,i,c=0;
    cin>>n;
    while(n%2==0)
        n/=2,c++;
    if(c)
        cout<<"+"<<"2^"<<c;
    for(i=3;i*i<=n;i+=2){
        c=0;
        while(n%i==0)
            n/=i,c++;
        if(c)
            cout<<"+"<<i<<"^"<<c;
    }
    if(n>1)
        cout<<"+"<<n<<"^1";
    return 0;
}
