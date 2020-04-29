#include<bits/stdc++.h>
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int i,j,l;
    cin>>l;
    int A[l],B[l];
    fill_n(B,l,1);
    f0(i,l)
    cin>>A[i];
    
    f1(i,l-1)
        f0(j,i)
            if(A[i]>A[j])
                B[i]=max(1+B[j],B[i]);
    
    int max=*max_element(B,B+l),id=0;
    f0(id,l)
        if(B[id]==max)
            break;
            
    vector<int>ans(max);
    ans.emplace_back(A[id]);
    int count=1,temp=id;

    for(i=id-1;i>=0;i--)
        if(B[i]+1==B[id])
            ans.emplace_back(A[i]),id=i;

    for(i=max-1;i>=0;i--)
        cout<<ans[i]<<" ";
    return 0;
}
