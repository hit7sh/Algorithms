#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int mod=1e9+7;

ull C(int n, int r) 
{ 
    vector<ull>C(r+1,0);
    C[0]=1;   
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, r); j > 0; j--) 
            C[j] = C[j] + C[j-1];
    }
    return C[r]; 
}

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
        cout<<(dp[n][r])<<" "<<C(n,r)<<endl;
    return 0;
}
