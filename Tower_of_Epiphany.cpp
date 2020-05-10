// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define debug(x) cout<<#x<<" is "<<x<<endl
#define f0(i, n) for(i = 0; i < n; i++)
#define f1(i, n) for(i = 1; i<= n; i++)
#define endl "\n"

using namespace std;
using umii = unordered_map<int, int>;
using mii = map<int, int>;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
const int mod=1e9+7;
void towerofepi(){
    int n,i,ans=0;
    cin>>n;
    int A[n],left[n],right[n],mx=INT_MIN;
    f0(i,n)
        cin>>A[i];
    f0(i,n)
        mx=max(mx,A[i]),left[i]=mx;
    mx=INT_MIN;
    for(i=n-1;i>=0;i--)
        mx=max(mx,A[i]),right[i]=mx;
    f0(i,n)
        if(min(left[i],right[i])-A[i]>0)
            ans+=min(left[i],right[i])-A[i];
    cout<<ans;
}
int main(){
    speed();
    towerofepi();
    return 0;
}
