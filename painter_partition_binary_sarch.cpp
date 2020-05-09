// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define _sum(a) accumulate(a.begin(), a.end(), 0)
#define f0(i,n) for(i=0;i<n;i++)

using namespace std;
using vi = vector<int>;

int main(){
    speed();
    int k,t,i,n,lb=0,rb=0,ans;
    cin>>k>>t>>n;
    vi A(n);
    f0(i,n)
        cin>>A[i];
    sort(A.begin(),A.end());
    lb=A[n-1];
    rb=_sum(A);
    while(lb<=rb){
        int mid=lb+(rb-lb)/2 , c=0,s=0;
        f0(i,n){
            s+=A[i];
            if(s>mid)
                c++,s=A[i];   //find required painters for mid
        }
        if(c<=k)
            ans=mid,rb=mid-1;
        else lb=mid+1;
    }
    cout<<ans*t;
    return 0;
}
