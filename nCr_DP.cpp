#include<bits/stdc++.h>
using namespace std;
long long int dp[778][778]{0};
void generate()
{int i,j;
    dp[2][1]=2;
    for(i=2;i<=777;i++)for(j=0;j<=i;j++)if(j==0||j==i)dp[i][j]=1;
    for(i=3;i<=777;i++)
    for(j=1;j<i;j++)
    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
}
int main()
{
    generate();
    int n,r;
        cin>>n>>r;
        cout<<(dp[n][r])<<endl;
    return 0;
}