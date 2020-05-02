#include<bits/stdc++.h>
using namespace std;
long long int dp[778][778]{0};
void generate(){
    int i,j;
    for(i=1;i<=777;i++)
        dp[i][i]=dp[i][0]=1;
        
    for(i=2;i<=777;i++)
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
