#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[50][50];

int main(){
    int i,j,n=10;
    for(i=0;i<=n;i++)
        dp[0][i]=dp[i][0]=dp[1][i]=dp[i][1]=1;
        
    for(i=2;i<=n;i++){
        for(j=2;j<=n;j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-i];

    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            cout << dp[i][j] << " \n"[j==n];
    // here, p(n) = A[n][n] 
    return 0;
}
