#include<bits/stdc++.h>
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)
#define ll long long
using namespace std;
int total,dp[101][101],coins[101],i,j,ans=0;
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>total;
    f1(i,total)
        cin>>coins[i];
    int mx;cin>>mx;
    f1(i,mx)dp[1][i]=i;
    
    for(i=2;i<=total;i++)
        f1(j,mx)
            if(coins[i]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=min(1+dp[i][j-coins[i]], dp[i-1][j]);
                
    cout<<dp[total][mx]<<endl;
    int r=total,c=mx,sum=0;
    vector<int>ans;
    while(true)
    {
        if(sum==mx)
        break;
        if(dp[r][c]==dp[r-1][c])
        {ans.push_back(coins[r-1]);r--;sum+=ans.back();}
        else if(dp[r][c]-1==dp[r][c-coins[r]])
        {ans.push_back(coins[r]);c-=coins[r];sum+=ans.back();}
    }
    int last=ans.back();
    ans.pop_back();
    for(auto x:ans)
        cout<<x<<"+";
    cout<<last<<endl;
    return 0;
}
