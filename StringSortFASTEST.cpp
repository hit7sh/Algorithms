#include<bits/stdc++.h>
#include<stdio.h>
#define ll long long
#define eb(n) emplace_back(n)
#define debug(x) cout<<"#x"<<" is "<<x<<endl
#define INF 10000000000
#define mod 1000000007
#define endl "\n"
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))
#define fo(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)
using namespace std;
/**
This method sort a string in O(n) time.
Assumption: Each index contains character in range ('a'<=st[i]<='z') or ('A'<=st[i]<='Z')
I recently came across something called 'Count Sort'.
It made me curious to implement on string, as each index has limited range values.
Lemme explain briefly, traverse through string and increase the count of 
frequency array frequency[st[i]]++ then traverse through frequency array/map
and put back the value in order.
*/
void sort_str(string& st)
{
    ll i,id=0,c_lw[26]={0},c_up[26]={0};
    for(char x:st)
        if(x>96)(c_lw[x-'a'])++;
        else (c_up[x-'A'])++;
    
    fo(i,26)
    {
        while(c_up[i]--)
            st[id++]=(char)(i+'A');
        while(c_lw[i]--)
            st[id++]=(char)(i+'a');
    }
}
int main()
{   
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
     string st;
     cin>>st;
     sort_str(st);
     cout<<st;
    return 0;
}
